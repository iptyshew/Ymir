project(frontend)

set(${PROJECT_NAME}_SRC
  frontend.h
  frontend.cpp
  lexer.h
  ilexer.h
  lexer.cpp
  syntax_parser.h
  syntax_parser.cpp
  source.h
  source.cpp
  types.h
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
