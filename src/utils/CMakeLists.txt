project(utils)
add_library(utils
  arg_parser.h
  arg_parser.cpp)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
