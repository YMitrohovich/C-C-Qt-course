#include "group3d.h"

Group3D::Group3D()
{

}

Group3D::~Group3D()
{
    delete [] this;
}

void Group3D::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions)
{
    for (auto i = 0; i < m_cube.size(); ++i) {
        m_cube[i]->draw(program, functions);
    }
}

void Group3D::setTranslate(const QVector3D &t)
{
    m_translate += t;

    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix = m_globalTransform * m_viewMatrix;

    for (auto i = 0; i < m_cube.size(); ++i) {          // IMPORTANT
        m_cube[i]->setGlobalTransform(m_viewMatrix);
    }
}

void Group3D::setGlobalTransform(const QMatrix4x4 &g)
{
    m_globalTransform = g;

    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix = m_globalTransform * m_viewMatrix;    // IMPORTANT
}

void Group3D::setRotate(const QQuaternion &r)
{
    Q_UNUSED(r);
}

void Group3D::addObject(SimpleObject3D *cube)
{
    m_cube.append(cube);
}
