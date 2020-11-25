project(driver)

set(${PROJECT_NAME}_SRC
  main.cpp)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
add_subdirectory(utils)
add_subdirectory(frontend)
add_subdirectory(ast)

target_link_libraries(${PROJECT_NAME} utils frontend ast ${CONAN_LIBS})
