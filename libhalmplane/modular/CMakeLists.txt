string(CONCAT SRC
  "modular/src/wrapper.cpp;"
  "modular/src/hal_loader.cpp;"
  "modular/src/test_wrapper.cpp;" 
)

include_directories(modular/inc)
target_sources(halmplane PRIVATE ${SRC})
