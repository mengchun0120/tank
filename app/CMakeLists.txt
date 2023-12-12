cmake_minimum_required(VERSION 3.22.1)

include(${COMMONLIB_SRC_DIR}/commonlib.cmake)
include(${TANKLIB_SRC_DIR}/tanklib.cmake)

include_directories(
    ${COMMONLIB_INCLUDE_DIR}
    ${TANKLIB_INCLUDE_DIR}
)

add_subdirectory(rungame)
