include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(ymir main.cpp)
add_subdirectory(utils)

target_link_libraries(ymir utils ${CONAN_LIBS})