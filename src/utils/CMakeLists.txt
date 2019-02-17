project(utils)


set(${PROJECT_NAME}_SRC
  arg_parser.cpp
  arg_parser.h
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
