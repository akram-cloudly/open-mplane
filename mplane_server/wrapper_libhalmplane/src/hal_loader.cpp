#include "hal_loader.h"
#include <cstddef>
#include <iostream> 
#include "wrapper.h"

Hal_Loader::Hal_Loader(const char* _libname)
{
    libname = _libname;
  if(libname)
    {
      dlhandle = dlopen("/usr/lib/libhalmplane.so.0.1.0", RTLD_NOW);
    
      if (!dlhandle) 
      {
          std::cerr << dlerror() << std::endl;
        //   return ;
      }
      void* (*rf)() = reinterpret_cast<void* (*)()>(dlsym(dlhandle, "function_map"));
      if(rf)
      {
        // rf();
        // std::cout <<"success full" << std::endl;
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

    // std::cout <<"hal_loader.cpp" << std::endl;
    
    // int (*halmplane_init1)() = (int (*)()) get_function("int (*halmplane_init)()");
    // std::cout <<"address of int (*halmplane_init)() hal-loader" << (*registered_functions)["int (*halmplane_init)()"] << std::endl;

    // if(halmplane_init1)
    // {
    //   std::cout << "successfull of hal_loader.cpp" << std::endl;
    //   halmplane_init1();
    // }

}

void* Hal_Loader::get_function(const char* ftag)
{
  if(registered_functions)
    {
      return (*registered_functions)[ftag];
    }
  return NULL;
}

void Hal_Loader::Hal_close()
{
  if(dlclose(dlhandle) == 0)
  {
    std::cout << "Library has closed" << std::endl;
  }
  else 
  {
    std::cout << "Library has not closed" << std::endl;
  }
}