#include <iostream>
#include "WasmBuilder.h"

int main(int ac, char** av) {

   WasmBuilder *build = new WasmBuilder(ac,av);
   build->Init();
   build->Start();

   while(1){
      sleep(1);
   }
   // std::string path = std::experimental::filesystem::temp_directory_path();

   //  std::cout << "path = " << path << std::endl;
   
   // IProject *project = new WasmProject();

   // project->CreateProject("__test");
}
