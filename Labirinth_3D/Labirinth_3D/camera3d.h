#ifndef CAMERA3D_H
#define CAMERA3D_H

#include <QOpenGLShaderProgram>

#include <QQuaternion>
#include <QMatrix4x4>
#include <QVector3D>

#include "parameters.h"

class Camera3D : public Parameters
{
private:
    QQuaternion             m_rotate;
    QMatrix4x4              m_viewMatrix;
    QVector3D               m_translate;

public:
    Camera3D();
    ~Camera3D();

    void setGlobalTransform (const QMatrix4x4 &g);
    void setRotate (const QQuaternion &r);
    void setTranslate (const QVector3D &t);
    void draw (QOpenGLShaderProgram *program,
               QOpenGLFunctions *functions = nullptr);
};

#endif // CAMERA3D_H
