cmake_minimum_required(VERSION 3.22.1)

include_directories(.)

add_executable(testshape tanktest_test_shape_app.cpp main.cpp)
target_link_libraries(testshape tanklib commonlib ${LIB})
