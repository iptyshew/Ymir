set(TARGET ymir)

add_executable(${TARGET} main.cpp)
add_subdirectory(utils)

target_link_libraries(${TARGET} utils ${CONAN_LIBS})
