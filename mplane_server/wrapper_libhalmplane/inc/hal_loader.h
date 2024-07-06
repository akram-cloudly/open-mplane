#ifndef HAL_LOADER_H_
#define HAL_LOADER_H_

#include <map>
#include <string>
#include <dlfcn.h>

class Hal_Loader
{
private:
  const char* libname;
  void* dlhandle;
  std::map<std::string, void*> *registered_functions;

public:
  Hal_Loader(const char* libname);
  void* get_function(const char* ftag);
};

#endif /* HAL_LOADER_H_ */