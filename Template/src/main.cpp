#include <cstddef>
#include <cstdlib>
#include <emscripten/bind.h>
#include <iostream>


using namespace std;
class Example {
 public:
   void run() {
        
       cout<<"new program  "<<endl;
      
   }
};


EMSCRIPTEN_BINDINGS(Example) {
  emscripten::class_<Example>("Example")
      .constructor<>()
      .function("run", &Example::run);
}