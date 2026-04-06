if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/toy/CMakeLists.txt)
  add_subdirectory(toy)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/myfirstlang/CMakeLists.txt)
  add_subdirectory(myfirstlang)
else()
  message(STATUS "examples: myfirstlang not added (see examples/myfirstlang/README)")
endif()
