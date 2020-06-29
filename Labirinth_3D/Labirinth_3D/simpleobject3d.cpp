#include "simpleobject3d.h"

SimpleObject3D::SimpleObject3D() :
    m_indexBuffer (QOpenGLBuffer::IndexBuffer)      // Indicates m_indexBuffer as index buffer. In other case index buffer will be identified as array buffer.
{
    m_texture = nullptr;                            // Indicates m_texture as null.
}

SimpleObject3D::~SimpleObject3D()
{
    if (m_vertexBuffer.isCreated())                 // Buffers and texture are created, they will be destroyed after program terminates.
        m_vertexBuffer.destroy();

    if (m_indexBuffer.isCreated())
        m_indexBuffer.destroy();

    if (m_texture != nullptr) {
        if (m_texture->isCreated())
            m_texture->destroy();
    }
}

SimpleObject3D::SimpleObject3D(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes, const QImage &texture):
    m_indexBuffer (QOpenGLBuffer::IndexBuffer)
{
    m_texture = nullptr;
    initVertexData (vertData, indexes, texture);
}

void SimpleObject3D::initVertexData(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes, const QImage &texture)
{
    if (m_vertexBuffer.isCreated())
        m_vertexBuffer.destroy();

    if (m_indexBuffer.isCreated())
        m_indexBuffer.destroy();

    if (m_texture != nullptr) {
        if (m_texture->isCreated()) {
            delete m_texture;
            m_texture = nullptr;
        }
    }

    m_vertexBuffer.create();                                            // Creates the buffer object.
    m_vertexBuffer.bind();                                              // Binds the buffer with the object.
    m_vertexBuffer.allocate(vertData.constData(),
                            vertData.size() * sizeof (VertexData));     // Allocates number of bytes of space to the buffer.
    m_vertexBuffer.release();                                           // Releases the buffer associated with the object from the current OpenGL context.

    m_indexBuffer.create();
    m_indexBuffer.bind();
    m_indexBuffer.allocate(indexes.constData(),
                           indexes.size() * sizeof(GLuint));
    m_indexBuffer.release();

    m_texture = new QOpenGLTexture(texture.mirrored());                 // Creates texture objects.
    m_texture->setMinificationFilter(QOpenGLTexture::Nearest);          // Applies texture filters.
    m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
    m_texture->setWrapMode(QOpenGLTexture::Repeat);
}

void SimpleObject3D::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions)
{
    if (!m_vertexBuffer.isCreated() || !m_indexBuffer.isCreated()) return;

    m_texture->bind(0);                                 // Binds variable to the existing ready-to-render texture.

    program->setUniformValue("u_texture", 0);

    modelMatrix.setToIdentity();
    modelMatrix.translate(m_translate);                 // Sets the coordinates for view matrix.
    modelMatrix = m_globalTransform * modelMatrix;

    program->setUniformValue("u_modelMatrix", modelMatrix);

    int offset = 0;
    m_vertexBuffer.bind();                              // Binds the buffer with the object.

    int vertloc = program->attributeLocation("a_position");                             // Returns location of the attribute from current shader program's parameter list.
    program->enableAttributeArray(vertloc);                                             // Enable the vertex array at location in the shader program.
    program->setAttributeBuffer(vertloc, GL_FLOAT, offset, 3, sizeof(VertexData));      // Sets an array of vertex values on the attribute location in this shader program.

    offset += sizeof (QVector3D);

    int textloc = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(textloc);
    program->setAttributeBuffer(textloc, GL_FLOAT, offset, 2, sizeof(VertexData));

    offset += sizeof (QVector2D);

    int normloc = program->attributeLocation("a_normal");
    program->enableAttributeArray(normloc);
    program->setAttributeBuffer(normloc, GL_FLOAT, offset, 3, sizeof(VertexData));

    m_indexBuffer.bind();

    functions->glDrawElements(GL_TRIANGLES, m_indexBuffer.size(), GL_UNSIGNED_INT, nullptr);        // Used to draw objects from primitives (triangles, in this case).

    m_vertexBuffer.release();
    m_indexBuffer.release();
    m_texture->release();
}

void SimpleObject3D::setRotate(const QQuaternion &r)
{
    Q_UNUSED(r);            // Macros used to tell Qt Creator that 'r' variable is not used in function. Needed to avoid warnings.
}

void SimpleObject3D::setTranslate(const QVector3D &t)
{
    m_translate += t;       // IMPORTANT
}

void SimpleObject3D::setGlobalTransform(const QMatrix4x4 &g)
{
    m_globalTransform = g; // IMPORTANT
}
