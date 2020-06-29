#include "camera3d.h"

Camera3D::Camera3D()
{

}

Camera3D::~Camera3D()
{
    delete this;
}

void Camera3D::setRotate(const QQuaternion &r)
{
    m_rotate *= r;

    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix.rotate(m_rotate);
 }

void Camera3D::setTranslate(const QVector3D &t)
{
    m_translate += t;

    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix.rotate(m_rotate);
}

void Camera3D::setGlobalTransform(const QMatrix4x4 &g)
{
    Q_UNUSED(g);
}

void Camera3D::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions)
{
    if (functions != nullptr)
        return;

    program->setUniformValue("u_viewMatrix", m_viewMatrix);
}
