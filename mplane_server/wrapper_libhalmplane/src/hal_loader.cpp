#include "hal_loader.h"
#include <cstddef>
#include <iostream> 

Hal_Loader::Hal_Loader(const char* _libname)
{
    libname = _libname;
  if(libname)
    {
      dlhandle = dlopen("/usr/lib/libhalmplane.so.0", RTLD_NOW);
    
      if (!dlhandle) 
      {
          std::cerr << "Failed to load shared library: " << dlerror() << std::endl;
        //   return ;
      }
    // void (*message_func)() = reinterpret_cast<void (*)()>(dlsym(dlhandle, "message"));

      void* (*rf)() = reinterpret_cast<void* (*)()>(dlsym(dlhandle, "function_map"));
      if(rf)
      {
        // rf();
        std::cout <<"success full" << std::endl;
        registered_functions = (std::map<std::string, void*>*) rf();
      }
      else
      {
        registered_functions = new std::map<std::string, void*>();
      }
    }
  else
    {
      registered_functions = new std::map<std::string, void*>();
    }

}

void* Hal_Loader::get_function(const char* ftag)
{
  if(registered_functions)
    {
      return (*registered_functions)[ftag];
    }
  return NULL;
}