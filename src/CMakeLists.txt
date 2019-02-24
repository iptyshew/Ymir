project(driver)

set(${PROJECT_NAME}_SRC
  main.cpp
  ast/ast.h)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
add_subdirectory(utils)
add_subdirectory(frontend)

target_link_libraries(${PROJECT_NAME} utils frontend ${CONAN_LIBS})
