set(LIB utils)


add_library(${LIB}
  arg_parser.h
  arg_parser.cpp)

target_include_directories(${LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
