project(test_ymir)


set(${PROJECT_NAME}_SRC
  arg_parser_test.cpp
  lexer_test.cpp
)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ../src/utils ../src/frontend)
target_link_libraries(${PROJECT_NAME}
  utils frontend
  ${CONAN_LIBS}
)

add_test(NAME ${PROJECT_NAME}
		 COMMAND ${PROJECT_NAME})
