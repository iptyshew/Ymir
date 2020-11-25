project(ast)

set(${PROJECT_NAME}_SRC
  ast.h
  ast.cpp
  visitor.h
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
