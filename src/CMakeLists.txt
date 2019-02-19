set(TARGET ymir)

set(SOURCES
  main.cpp
  utils/arg_parser.h
  utils/arg_parser.cpp

  ast/ast.h

  frontend/frontend.h
  frontend/frontend.cpp
  frontend/lexer.h
  frontend/ilexer.h
  frontend/lexer.cpp
  frontend/syntax_parser.h
  frontend/syntax_parser.cpp
  frontend/source.h
  frontend/source.cpp
  frontend/types.h)

add_executable(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} ${CONAN_LIBS})
