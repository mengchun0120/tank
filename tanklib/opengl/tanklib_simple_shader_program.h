#ifndef INCLUDED_TANKLIB_SIMPLE_SHADER_PROGRAM_H
#define INCLUDED_TANKLIB_SIMPLE_SHADER_PROGRAM_H

#include <commonlib_vector.h>
#include <commonlib_color.h>
#include <commonlib_vertex_array.h>
#include <commonlib_shader_program.h>

namespace mcdane {
namespace tanklib {

class SimpleShaderProgram: public commonlib::ShaderProgram {
public:
    SimpleShaderProgram() = default;

    ~SimpleShaderProgram() override = default;

    void init(const std::vector<std::string> &vertexShaderFiles,
              const std::vector<std::string> &fragShaderFiles);

    inline void setUseObjRef(bool enabled);

    inline void setObjRef(const commonlib::Point2 &objRef);

    inline void setViewportSize(const commonlib::Point2 &viewportSize);

    inline void setViewportOrigin(const commonlib::Point2 &viewportOrigin);

    void setPositionTexPos(const commonlib::VertexArray &va);;

    inline void setColor(const commonlib::Color &color);

    inline void setUseColor(bool use);

    void setTexture(GLuint textureId);;

    inline void setUseDirection(bool use);

    inline void setDirection(const commonlib::Point2 &direction);

    inline void setUseTexColor(bool use);

    inline void setTexColor(const  commonlib::Color &color);

    inline void setAlpha(float alpha);

private:
    void initLocations();

private:
    GLint positionLoc_;
    GLint useObjRefLoc_;
    GLint objRefLoc_;
    GLint viewportSizeLoc_;
    GLint viewportOriginLoc_;
    GLint colorLoc_;
    GLint useColorLoc_;
    GLint texPosLoc_;
    GLint textureLoc_;
    GLint useDirectionLoc_;
    GLint directionLoc_;
    GLint useTexColorLoc_;
    GLint texColorLoc_;
    GLint alphaLoc_;
};

void SimpleShaderProgram::setUseObjRef(bool enabled)
{
    glUniform1i(useObjRefLoc_, enabled ? 1 : 0);
}

void SimpleShaderProgram::setObjRef(const commonlib::Point2 &objRef)
{
    glUniform2fv(objRefLoc_, 1, reinterpret_cast<const GLfloat *>(&objRef));
}

void SimpleShaderProgram::setViewportSize(
                                        const commonlib::Point2 &viewportSize)
{
    glUniform2fv(viewportSizeLoc_, 1,
                 reinterpret_cast<const GLfloat *>(&viewportSize));
}

void SimpleShaderProgram::setViewportOrigin(
                                        const commonlib::Point2 &viewportOrigin)
{
    glUniform2fv(viewportOriginLoc_, 1,
                 reinterpret_cast<const GLfloat *>(&viewportOrigin));
}

void SimpleShaderProgram::setColor(const commonlib::Color &color)
{
    glUniform4fv(colorLoc_, 1, reinterpret_cast<const GLfloat *>(&color));
}

void SimpleShaderProgram::setUseColor(bool use)
{
    glUniform1i(useColorLoc_, use ? 1 : 0);
}

void SimpleShaderProgram::setUseDirection(bool use)
{
    glUniform1i(useDirectionLoc_, use ? 1 : 0);
}

void SimpleShaderProgram::setDirection(const commonlib::Point2 &direction)
{
    glUniform2fv(directionLoc_, 1,
                 reinterpret_cast<const GLfloat *>(&direction));
}

void SimpleShaderProgram::setUseTexColor(bool use)
{
    glUniform1i(useTexColorLoc_, use ? 1 : 0);
}

void SimpleShaderProgram::setTexColor(const  commonlib::Color &color)
{
    glUniform4fv(texColorLoc_, 1, reinterpret_cast<const GLfloat *>(&color));
}

void SimpleShaderProgram::setAlpha(float alpha)
{
    glUniform1f(alphaLoc_, alpha);
}

} // end of namespace tanklib
} // end of namespace mcdane

#endif

