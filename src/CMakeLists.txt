include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(ymir main.cpp)

target_link_libraries(ymir ${CONAN_LIBS})