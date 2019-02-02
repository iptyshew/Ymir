add_executable(ymir main.cpp)

add_subdirectory(utils)
target_link_libraries(ymir utils)
