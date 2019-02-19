set(TARGET ymir)

set(SOURCES
  main.cpp

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
add_subdirectory(utils)

target_link_libraries(${TARGET} utils ${CONAN_LIBS})
