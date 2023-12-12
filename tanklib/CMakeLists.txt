cmake_minimum_required(VERSION 3.22.1)

include(${COMMONLIB_SRC_DIR}/commonlib.cmake)
include(tanklib.cmake)

include_directories(
    ${COMMONLIB_INCLUDE_DIR}
    ${TANKLIB_INCLUDE_DIR}
)

add_library(tanklib STATIC ${TANKLIB_SOURCE_FILES})

