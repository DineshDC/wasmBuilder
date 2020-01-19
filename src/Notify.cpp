#include "Notify.h"
#include <experimental/filesystem>  
namespace fs = std::experimental::filesystem;

int *Notify::m_WorkingDir = nullptr;
char Notify::m_Buffer[EVENT_BUF_LEN] = {0};
int Notify::m_fd = 0;
bool Notify::m_ThreadStop = false;
Notify::Notify(IProject *m_ProjectCallback) : m_m_ProjectCallback {m_ProjectCallback} {

}

void Notify::Monitor(IProject *ProjectCallback)
{
    cout<<"Monitoring thread start\n";
    int i = 0;
    int length = 0;
    while (!m_ThreadStop)
    {
        /*read to determine the event change happens on “/tmp” directory. Actually this read blocks until the change event occurs*/

        length = read(m_fd, m_Buffer, EVENT_BUF_LEN);

        /*checking for error*/
        if (length < 0)
        {
            perror("read");
            break;
        }

        /*actually read return the list of change events happens. Here, read the change event one by one and process it accordingly.*/
        while (i < length)
        {
            struct inotify_event *event = (struct inotify_event *)&m_Buffer[i];
            if (event->len)
            {
                if (event->mask & IN_CREATE)
                {
                    if (event->mask & IN_ISDIR)
                    {
                        printf("New directory %s created.\n", event->name);
                    }
                    else
                    {
                        printf("New file %s created.\n", event->name);
                    }
                }
                else if (event->mask & IN_DELETE)
                {
                    if (event->mask & IN_ISDIR)
                    {
                        printf("Directory %s deleted.\n", event->name);
                    }
                    else
                    {
                        printf("IN_DELETE File %s deleted.\n", event->name);
                    }
                }
                else if (event->mask & IN_MODIFY)
                {
                    if (event->mask & IN_ISDIR)
                    {
                        printf("Directory %s deleted.\n", event->name);
                    }
                    else
                    {
                        printf("IN_MODIFY File %s %s Name %s.\n",event->name,fs::current_path().c_str(),ProjectCallback->m_ProjectName.c_str());
                    }
                    
                    if(ProjectCallback)
                     ProjectCallback->BuildProject("../../" + ProjectCallback->m_ProjectName);
                }
            }
            i += EVENT_SIZE + event->len;
        }
        i = 0;
    }
}
int16_t Notify::Init()
{
    /*creating the INOTIFY instance*/
    m_fd = inotify_init();

    /*checking for error*/
    if (m_fd < 0)
    {
        perror("inotify_init");
        return -1;
    }
}

int16_t Notify::AddToWatch(vector<string> listToWatch)
{

    const int size = listToWatch.size();
    m_WorkingDir = new int[size];
    m_sizeofList = size;
    /*adding the “/tmp” directory into watch list. Here, the suggestion is to validate the existence of the directory before adding into monitoring list.*/
    for (int i = 0; i < size; ++i)
    {
        cout<<"Adding to watch " << listToWatch[i] << "\n";
        m_WorkingDir[i] = inotify_add_watch(m_fd, listToWatch[i].c_str(), IN_CREATE | IN_DELETE | IN_MODIFY);
    }
}

int16_t Notify::Join()
{
    m_tMon.join();
}
int16_t Notify::Start()
{

    thread tmp(this->Monitor,m_m_ProjectCallback);
    m_tMon = std::move(tmp);

}

int16_t Notify::Stop()
{
    m_ThreadStop = true;
    /*removing the “/tmp” directory from the watch list.*/
    for(int i = 0 ; i < m_sizeofList; i++)
        inotify_rm_watch( m_fd, m_WorkingDir[i] );

  /*closing the INOTIFY instance*/
   close( m_fd );
}