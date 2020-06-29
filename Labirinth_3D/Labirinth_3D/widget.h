#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLShaderProgram>         // Used to connect OpenGL shaders to the program.
#include <QOpenGLTexture>               // Used to work with OpenGL textures.
#include <QOpenGLWidget>                // Used to work with OpenGL graphics.
#include <QOpenGLBuffer>                // Used to manage OpenGL buffer objects.

#include <QMouseEvent>                  // Used to enable mouse actions.
#include <QKeyEvent>                    // Used to enable keyboard actions.
#include <QMatrix4x4>                   // Used to enable actions with projection, model and view matrixes

#include "simpleobject3d.h"
#include "camera3d.h"
#include "group3d.h"
#include "skybox.h"

class Widget : public QOpenGLWidget     // To enable graphics class should be inhereted from QOpenGLWidget
{
    Q_OBJECT

private:
    QOpenGLShaderProgram                m_program;
    QOpenGLShaderProgram                m_programSkyBox;
    QMatrix4x4                          m_projectionMatrix;
    QVector2D                           m_mousePosition;

    QVector<SimpleObject3D *>           m_cube;
    QVector<Group3D *>                  m_groups;

    Camera3D                            *m_camera;
    SkyBox                              *m_skybox;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initializeGL();                                    // Used to set up OpenGL state and resources. Called only once before first call of resizeGL or paintGL
    void resizeGL(int width, int height);                   // Used to set up OpenGL viewport, projections and etc. Called everytime when the widget has been resized.
    void paintGL();                                         // Used to render OpenGL scene. Called everytime needs  to be updated.

    void mousePressEvent (QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    void keyPressEvent (QKeyEvent *event);

    void initCube(float width, const QImage &texture);      // Initialize cube geometry with specified texture
    void initShaders();                                     // Initialize shaders in the program
};

#endif // WIDGET_H

