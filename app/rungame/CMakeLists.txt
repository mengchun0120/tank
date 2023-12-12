cmake_minimum_required(VERSION 3.22.1)

include_directories(.)

add_executable(rungame tankapp_rungame_app.cpp main.cpp)
target_link_libraries(rungame tanklib commonlib ${LIB})
