#include <iostream> 
#include <map>
#include <string>
#include <memory>

#include <HalMplane.h>
#include <MplaneInterfaces.h> 

extern "C"
{
  void *function_map()
  {
    std::map<std::string, void*> *registered_functions;
    registered_functions = new std::map<std::string, void*>();
    (*registered_functions)["int (*halmplane_init)()"] = (void*) halmplane_init;
    (*registered_functions)["int (*halmplane_exit)()"] = (void*) halmplane_exit; 
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update)(interface_t* interface)"]
     = (void*)halmplane_interface_update; 

    // std::cout <<"address of int (*halmplane_init)() api-registration" << (*registered_functions)["int (*halmplane_init)()"] << std::endl;
    return registered_functions;
  }
}