list(APPEND
    TANKLIB_APP_SRC
    app/tanklib_app_config.cpp
)

list(APPEND
    TANKLIB_GAMEOBJ_SRC
    gameobj/tanklib_game_object_template.cpp
    gameobj/tanklib_game_object_type.cpp
    gameobj/tanklib_particle_effect_template.cpp
)

list(APPEND
    TANKLIB_GAMEUTILS_SRC
    gameutils/tanklib_context.cpp
)

list(APPEND
    TANKLIB_MISC_SRC
    misc/tanklib_constants.cpp
    misc/tanklib_typedef.cpp
)

list(APPEND
    TANKLIB_OPENGL_SRC
    opengl/tanklib_graphics.cpp
    opengl/tanklib_particle_shader_program.cpp
    opengl/tanklib_simple_shader_program.cpp
    opengl/tanklib_text_size.cpp
    opengl/tanklib_text_system.cpp
)

list(APPEND
    TANKLIB_SHAPE_SRC
    shape/tanklib_polygon.cpp
    shape/tanklib_rectangle.cpp
    shape/tanklib_shape.cpp
    shape/tanklib_tex_pos_array.cpp
    shape/tanklib_tex_rectangle.cpp
)

list(APPEND
    TANKLIB_SOURCE_FILES
    ${TANKLIB_APP_SRC}
    ${TANKLIB_GAMEOBJ_SRC}
    ${TANKLIB_GAMEUTILS_SRC}
    ${TANKLIB_MISC_SRC}
    ${TANKLIB_OPENGL_SRC}
    ${TANKLIB_SHAPE_SRC}
)

list(APPEND
    TANKLIB_INCLUDE_DIR
    ${TANKLIB_SRC_DIR}/app
    ${TANKLIB_SRC_DIR}/gameobj
    ${TANKLIB_SRC_DIR}/gameutils
    ${TANKLIB_SRC_DIR}/misc
    ${TANKLIB_SRC_DIR}/opengl
    ${TANKLIB_SRC_DIR}/shape
)
