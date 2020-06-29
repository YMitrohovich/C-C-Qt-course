#ifndef SIMPLEOBJECT3D_H
#define SIMPLEOBJECT3D_H

#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>

#include <QQuaternion>
#include <QMatrix4x4>
#include <QVector2D>

#include "parameters.h"

struct VertexData {
    VertexData() {}

    VertexData(QVector3D p, QVector2D t, QVector3D n) :
        position(p), texCoord(t), normal(n) {}

    QVector3D                 position;
    QVector2D                 texCoord;
    QVector3D                 normal;
};

class SimpleObject3D : public Parameters
{
private:
   QOpenGLTexture             *m_texture;
   QOpenGLBuffer              m_vertexBuffer;
   QOpenGLBuffer              m_indexBuffer;

   QQuaternion                m_rotate;
   QMatrix4x4                 modelMatrix;
   QMatrix4x4                 m_globalTransform;
   QVector3D                  m_translate;

public:
    SimpleObject3D();
    SimpleObject3D (const QVector<VertexData> &vertData,
                    const QVector<GLuint> &indexes,
                    const QImage &texture);
    ~SimpleObject3D();

    void setGlobalTransform (const QMatrix4x4 &g);
    void setRotate (const QQuaternion &r);
    void setTranslate (const QVector3D &t);
    void draw (QOpenGLShaderProgram *program,
               QOpenGLFunctions *functions);

    void initVertexData (const QVector<VertexData> &vertData,
               const QVector<GLuint> &indexes,
               const QImage &texture);
};

#endif // SIMPLEOBJECT3D_H
