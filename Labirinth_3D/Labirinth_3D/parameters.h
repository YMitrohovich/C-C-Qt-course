#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>

#include <QQuaternion>
#include <QMatrix4x4>
#include <QVector3D>

class Parameters {
public:
    virtual ~Parameters() {}

    virtual void setGlobalTransform (const QMatrix4x4 &g) = 0;
    virtual void setRotate (const QQuaternion &r) = 0;
    virtual void setTranslate (const QVector3D &t) = 0;
    virtual void draw (QOpenGLShaderProgram *program,
                       QOpenGLFunctions *functions) = 0;
};

#endif // PARAMETERS_H
