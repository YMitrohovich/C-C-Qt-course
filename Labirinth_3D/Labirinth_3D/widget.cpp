#include "widget.h"

void Widget::initializeGL()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);        // Set the screen color to black
   glEnable(GL_DEPTH_TEST);                     // Enable depth test
   glEnable(GL_CULL_FACE);                      // Cut the back side of the cube

   initShaders();                               // Initialize shaders

   /*  --- Surface cubes --- */
   m_groups.append(new Group3D);                // Create group to fill it with cubes
   for (auto x = 0; x <= 7; x++) {              // Set needed x, y, z coordinates
        for (auto z = 0; z <= 10; z ++) {
            initCube(1.0f, QImage (":/dirt.png"));    // Initialize cube with size of float
            m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, 0.0f, z));         // Set the location where this cube is needed
            m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);    // Include the created cube in group created above
        }
    }

   for (auto x = 3; x <= 5; x++) {
       for (auto z = 0; z >= -2; z--){
           initCube(1.0f, QImage (":/dirt.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, 0.0f, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
   }
   /* ---------------------- */

   /*  -- Perimeter walls -- */
   m_groups.append(new Group3D);

   /* --- Walls on x axis --- */
   for (auto x = 0; x <= 3; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 0.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto x = 5; x <= 7; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 0.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto x = 0; x <= 7; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 10.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   /* --- Walls on z axis --- */
   for (auto z = 0; z <= 10; z++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(0.0f, y, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
   }

   for (auto z = 0; z <= 10; z++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(7.0f, y, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
   }
   /* ---------------------- */

   /* ---- Inner walls ----- */ 
   m_groups.append(new Group3D);

   /* --- Walls on x axis --- */
   for (auto x = 3; x < 6; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 2.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto x = 3; x < 4; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 4.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto x = 1; x < 3; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 4.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto x = 5; x < 7; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 4.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto x = 2; x < 6; x++) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(x, y, 8.0f));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   /* --- Walls on z axis --- */
   for (auto z = 8; z > 6; z--) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(2.0f, y, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto z = 5; z > 3; z--) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(2.0f, y, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto z = 2; z > 0; z--) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(2.0f, y, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }

   for (auto z = 6; z > 4; z--) {
       for (auto y = 1; y < 3; y++) {
           initCube(1.0f, QImage (":/grass.png"));
           m_cube[m_cube.size() - 1]->setTranslate(QVector3D(5.0f, y, z));
           m_groups[m_groups.size() - 1]->addObject(m_cube[m_cube.size() - 1]);
       }
    }
   /* ---------------------- */

   m_groups[0]->setTranslate(QVector3D(-5.0f, -8.0f, -5.0f));      // Surface cubes translation
   m_groups[1]->setTranslate(QVector3D(-5.0f, -8.0f, -5.0f));      // Perimeter wall cubes translation
   m_groups[2]->setTranslate(QVector3D(-5.0f, -8.0f, -5.0f));      // Inner wall cubes translation

   m_skybox = new SkyBox(25.0f, QImage (":/skybox.png"));          // Creating skybox object of size 25 float with specified image file

   m_camera = new Camera3D;                                        // Creating camera object
   m_camera->setTranslate(QVector3D(0.0f, 7.0f, -4.0f));           // Camera translation to a starting point
}

void Widget::resizeGL(int width, int height)
{
    float aspect = width / static_cast <float> (height);           // Initializing aspect ratio of width to height
    m_projectionMatrix.setToIdentity();                            // Sets matrix to identity
    m_projectionMatrix.perspective(45, aspect, 0.01f, 100.0f);     // Creates perspective projection
}

void Widget::paintGL()
{
    glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);                            // Tells glClear() to clear depth and color buffers

    m_programSkyBox.bind();                                                         // Binds to the current OpenGLContext and makes current shader program active. Any previously binded shader program will be realeased

    m_programSkyBox.setUniformValue("u_projectionMatrix", m_projectionMatrix);      // Set the value to the variable from the location in the resource file

    m_camera->draw(&m_programSkyBox);                                               // Draws skybox in the program
    m_skybox->draw(&m_programSkyBox, context()->functions());                       // Also needed to draw skybox

    m_programSkyBox.release();                                                      // Sets the shader program to unactive state

    m_program.bind();

    m_program.setUniformValue("u_projectionMatrix", m_projectionMatrix);
    m_program.setUniformValue("u_lightPosition", QVector4D (0.0, 0.0, 0.0, 0.0));   // Sets the light position
    m_program.setUniformValue("u_lightPower", 1.05f);                               // Sets the light power

    m_camera->draw(&m_program);                                                     // Draws the cubes
    for (int i = 0; i < m_groups.size(); i++) {                                     // Using loop to draw all the objects
        m_groups[i]->draw(&m_program, context()->functions());
    }

    m_program.release();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)                         // If left button was clicked, m_mousePosition recieves the cursor position, relatively to the widget.
        m_mousePosition = QVector2D (event->localPos());

    event->accept();                                                // Indicates that event receiver wants the event.
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
   if (event->buttons() != Qt::LeftButton) return;                             // Enable rotation only in case if left button was clicked

    QVector2D diff = QVector2D (event->localPos()) - m_mousePosition;
    m_mousePosition = QVector2D (event->localPos());

    float angle = diff.length() / 20.0f;                                       // Sets the rotation speed.
    QVector3D axis = QVector3D (diff.y(), diff.x(), 0.0);                      // Sets the axis of rotation.

    m_camera->setRotate(QQuaternion::fromAxisAndAngle(axis, angle));           // Enable mouse rotation with quanternion using axis and angle.

    update();                                                                  // Updates the widget and sets higher priority for the paintGL function.
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        m_camera->setTranslate(QVector3D(0.15f, 0.0f, 0.0f));               // If left arrow is pressed, camera moves left.
        break;
    case Qt::Key_Right:
        m_camera->setTranslate(QVector3D(-0.15f, 0.0f, 0.0f));              // If right arrow is pressed, camera moves right.
        break;
    case Qt::Key_Down:
        m_camera->setTranslate(QVector3D(0.0f, 0.0f, -0.15f));              // If down arrow is pressed, camera moves backwards.
        break;
    case Qt::Key_Up:
        m_camera->setTranslate(QVector3D(0.0f, 0.0f, 0.15f));               // If up arrow is pressed, camera moves forward.
        break;
    case Qt::Key_Escape:
        close();                                                            // If escape button is pressed, program terminates.
        break;
    case Qt::Key_W:
        m_camera->setTranslate(QVector3D(0.0f, -0.15f, 0.0f));              // If W button is pressed, camera moves up.
        break;
    case Qt::Key_S:
        m_camera->setTranslate(QVector3D(0.0f, 0.15f, 0.0f));               // If S button is pressed, camera moves down.
        break;
    }

    update();
}

void Widget::initShaders()
{
    if (!m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.vsh"))             // Adds shader files to the shader program. If add function was failed to execute, program terminates.
        close();

    if (!m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.fsh"))
        close();

    if (!m_program.link())                                                                     // Links together shaders that were added to current shader program. If link function was failed to execute, program terminates.
        close();

    if (!m_programSkyBox.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vskybox.vsh"))
        close();

    if (!m_programSkyBox.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fskybox.fsh"))
        close();

    if (!m_programSkyBox.link())
        close();
}

void Widget::initCube(float width, const QImage &texture)           // Creates the geometry of cube using specified texture.
{
    float width_div_2  = width / 2.0f;

    QVector<VertexData> vertexes;           // Initialize vertexes for cube type of structure that contains data about vertexes and indexes.

    // Front side of the cube.
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0, 0.0, 1.0)));          // Append function inserts value at the end of the vector.
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, 1.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0, 0.0, 1.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0, 0.0, 1.0)));

    // Right side of the cube.
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(1.0, 0.0, 0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(1.0, 0.0, 0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector2D(1.0, 1.0), QVector3D(1.0, 0.0, 0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(1.0, 0.0, 0.0)));

    // Top side of the cube.
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0, 1.0, 0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0, 1.0, 0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0, 1.0, 0.0)));

    // Back side of the cube.
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0, 0.0, -1.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, -width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0, 0.0, -1.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0, 0.0, -1.0)));

    // Left side of the cube.
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(-1.0, 0.0, 0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(-1.0, 0.0, 0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(-1.0, 0.0, 0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(-1.0, 0.0, 0.0)));

    // Bottom side of the cube.
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0, -1.0, 0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0, -1.0, 0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0, -1.0, 0.0)));

    QVector<GLuint> indexes;                                         // Initialize indexes of the cube.
    for (auto i = 0; i < 24; i+=4) {                                 // Loop used set the location of corner points of the cube.
        indexes.append (static_cast <unsigned int> (i + 0));
        indexes.append (static_cast <unsigned int> (i + 1));
        indexes.append (static_cast <unsigned int> (i + 2));

        indexes.append (static_cast <unsigned int> (i + 2));
        indexes.append (static_cast <unsigned int> (i + 1));
        indexes.append (static_cast <unsigned int> (i + 3));
    }

    m_cube.append(new SimpleObject3D(vertexes, indexes, texture));   // Adds the created cube to the array of objectes.
}

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

Widget::~Widget()
{
    delete m_camera;                                       // Deletes the camera object.

    for (auto i = 0; i < m_cube.size(); ++i)               // Loop deletes all the created objectes.
        delete m_cube[i];

    for (auto i = 0; i < m_groups.size(); ++i)             // Loop deletes all the created groups of objects.
        delete m_groups[i];
}
