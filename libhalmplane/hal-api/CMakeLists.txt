string(CONCAT SRC
  "api-registration.cpp;"
)
include_directories(inc)

list(TRANSFORM SRC PREPEND "hal-api/")
target_sources(halmplane PRIVATE ${SRC})
