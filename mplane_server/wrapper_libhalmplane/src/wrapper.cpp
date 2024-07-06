#include <wrapper.h>
#include <hal_loader.h>

const char* configured_libname = NULL;
Hal_Loader* hal_loader = NULL;

int wrapper_halmplane_init()
{
    std::cout << "wrapper_halmplane_init loading...." << std::endl;
    if(configured_libname == NULL)
    {
      configured_libname = "/usr/lib/libhalmplane.so.0";
      hal_loader = new Hal_Loader(configured_libname);

      std::cout << "wrapper_halmplane_init loaded successfully" << std::endl;
    }
  
    return 0;
}

int halmplane_init()
{
  capture_source_as_str(int (*halmplane_init)(), ftag);
  halmplane_init = (int (*)()) hal_loader->get_function(ftag);
  if(halmplane_init)
  {
    return halmplane_init();
  }
  return 0;
}
