#ifndef WRAPPER_H_
#define WRAPPER_H_

#include <iostream>
#include <memory>

class Wrapper
{
  public:
  ~Wrapper()
  {
    std::cout << "Wrapper destructor is running" << std::endl;
  }

};

extern "C"
{
  void* function_map();
};

int wrapper_halmplane_init();
int halmplane_init();

#define capture_source_as_str(src, strname) src; const static char* strname = #src;

#endif /* WRAPPER_H_ */
