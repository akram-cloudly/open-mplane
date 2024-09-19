list(APPEND MPLANE_SERVER_SOURCES
  wrapper_libhalmplane/src/wrapper.cpp
  wrapper_libhalmplane/src/hal_loader.cpp
  wrapper_libhalmplane/src/test_wrapper.cpp
)

include_directories(wrapper_libhalmplane/inc)