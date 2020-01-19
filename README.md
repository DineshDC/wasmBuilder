# BACKLOG
# Add commandline 

  write class to parse commandline argument  <span style="color:green;">[D]</span>
```sh
 -nw or --new create new project
 -cc or --class add new class 
 -ec or --emclass add class with ecmascripten with only public interfaces
 -rm or --remclass remove class and its references 
 -pb or --build (build the project)
 -pr or --run (run using  python -m SimpleHTTPServer 8000)
 -pbr or --buildandrun (build the project and run using  python -m SimpleHTTPServer 8000)
 -hr or --hotrun run with notify that will identify changes src, www, libs folder and build the project and run (just like hot reload)
```

# Add notify 
  * write class that will identify the changes in www,src,libs and notify <span style="color:green;">[D]</span>
  * Optimize the notify behviour <span style="color:yellow;">[IP]</span>
 

#  Add boostrap framework
  * Add css,script,pages folder to www template and add boostrap source to it <span style="color:yellow;">[IP]</span>

# Add c++ webdriver to open the web browser
 * This will open the web browser and reload the page on build

# Auto download all dependancies 
 * Identify and download dependancies [Use curl to download]
    - Download latest emsdk build and add to env path (source /home/dd/WASM/emsdk/emsdk_env.sh --build=Release > /dev/null)
    - Download build tools require to build
    - Download latest python to run simple http server
    - Get the latest library for gtest and other third party libs add to sdk folder and build
  

<span style="color:green;">[Done]</span>
<span style="color:yellow;">[In Progress]</span>