#ifndef GROUP3D_H
#define GROUP3D_H

#include <QMatrix4x4>
#include <QVector3D>
#include <QVector>

#include "simpleobject3d.h"

class Group3D : public Parameters
{
private:
    QMatrix4x4                      m_viewMatrix;
    QMatrix4x4                      m_globalTransform;
    QVector3D                       m_translate;

    QVector<SimpleObject3D *>       m_cube;

public:
    Group3D();
    ~Group3D();

    void setGlobalTransform (const QMatrix4x4 &g);
    void setRotate (const QQuaternion &r);
    void setTranslate (const QVector3D &t);
    void draw (QOpenGLShaderProgram *program,
               QOpenGLFunctions *functions);

    void addObject (SimpleObject3D *cube);
};

#endif // GROUP3D_H
