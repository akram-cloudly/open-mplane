#include "hal_loader.h"
#include <cstddef>
#include <iostream> 
#include "wrapper.h"

Hal_Loader::Hal_Loader(const char* _libname)
{
    libname = _libname;
  if(libname)
    {
      dlhandle = dlopen("usr/lib/libhalmplane-mod-example.so.1.1.0", RTLD_NOW | RTLD_GLOBAL);
    
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

    std::cout <<"hal_loader.cpp" << std::endl;
    // halmplane_error_t halmplane_interface_update(interface_t* interface);

    interface_t* xyz;
    halmplane_error_t (*halmplane_interface_update)(interface_t*) = (halmplane_error_t (*)(interface_t*)) dlsym(dlhandle,"halmplane_interface_update");
    // std::cout <<"address of int (*halmplane_init)() hal-loader" << (*registered_functions)["int (*halmplane_init)()"] << std::endl;

    if(halmplane_interface_update)
    {
      std::cout << "successfull of hal_loader.cpp" << std::endl;
      halmplane_interface_update(xyz);
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