#include <sstream>
#include <algorithm>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <commonlib_file_utils.h>
#include <commonlib_json_param.h>
#include <commonlib_app.h>
#include <commonlib_texture.h>

namespace mcdane {
namespace commonlib {

Texture::~Texture()
{
    if (id_)
    {
        glDeleteTextures(1, &id_);
    }
}

void Texture::init(const std::string &path)
{
    glGenTextures(1, &id_);
    if (id_ == 0)
    {
        THROW_EXCEPT(OpenGLException, "glGenTextures failed");
    }

    glBindTexture(GL_TEXTURE_2D, id_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int numChannels;

    stbi_set_flip_vertically_on_load(true);

    unsigned char *data = stbi_load(path.c_str(),
                                    &width_,
                                    &height_,
                                    &numChannels,
                                    0);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGBA,
                     width_,
                     height_,
                     0,
                     GL_RGBA,
                     GL_UNSIGNED_BYTE,
                     data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        THROW_EXCEPT(OpenGLException, "Failed to load image from " + path);
    }

    stbi_image_free(data);
}

void Texture::init(const rapidjson::Value &v,
                   const std::string &picDir)
{
    std::string fileName;

    std::vector<JsonParamPtr> params{
        jsonParam(fileName, "file", true, k_nonEmptyStrV)
    };

    parse(params, v);

    fileName = constructPath({picDir, fileName});
    init(fileName);
}

} // end of namespace commonlib
} // end of namespace mcdane
