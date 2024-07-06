#include <iostream> 
#include <map>
#include <string>
#include <memory>

#include <HalMplane.h>

extern "C"
{
  void *function_map()
  {
    std::map<std::string, void*> *registered_functions;
    registered_functions = new std::map<std::string, void*>();
    (*registered_functions)["int (*halmplane_init)()"] = (void*) halmplane_init;
    // (*registered_functions)["shared_ptr<Mod> (*create_mod_instance)()"] = (void*) create_mod_instance; 
    
    return registered_functions;
  }
}