add_executable(myfirstlang repl.cpp)
target_include_directories(myfirstlang PUBLIC ${CMAKE_SOURCE_DIR}/include)

install(TARGETS myfirstlang RUNTIME DESTINATION bin)
