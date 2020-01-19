#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
//#include <linux/inotify.h>
#include <sys/inotify.h>
#include <unistd.h>

#include <vector>
#include <string>
#include <thread>
#include "IProject.h"

using namespace std;

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

class Notify
{
    static int m_fd;
    int m_sizeofList;
    static int *m_WorkingDir;
    static char m_Buffer[EVENT_BUF_LEN];
    static bool m_ThreadStop;
    thread m_tMon;

    static void Monitor(IProject *m_ProjectCallback);
    IProject *m_m_ProjectCallback;
public:
    Notify(IProject *m_ProjectCallback);
    int16_t Init();
    int16_t AddToWatch(vector<string> listToWatch);
    int16_t Start();
    int16_t Stop();
    int16_t Join();
};