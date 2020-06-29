#ifndef SKYBOX_H
#define SKYBOX_H

#include <QImage>

#include "simpleobject3d.h"

class SkyBox
{
private:
    SimpleObject3D          *m_skybox;

public:
    SkyBox(float width, const QImage &texture);
    ~SkyBox();

    void draw (QOpenGLShaderProgram *program,
               QOpenGLFunctions *functions);
};

#endif // SKYBOX_H
