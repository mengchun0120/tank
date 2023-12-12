list(APPEND
    TANKLIB_APP_SRC
    app/tanklib_app_config.cpp
)


list(APPEND
    TANKLIB_SOURCE_FILES
    ${TANKLIB_APP_SRC}
)

list(APPEND
    TANKLIB_INCLUDE_DIR
    ${TANKLIB_SRC_DIR}/app
)
