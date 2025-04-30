
#include "openglwidget.h"

#include "Renderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "VertexArray.h"
#include "VertexBufferLayout.h"

#include "Shader.h"

#include "Texture.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget(parent) {
}

void OpenGLWidget::initializeGL() {



    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    std::cout << glGetString(GL_VERSION) << '\n';

    float positions[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 1.0f,
    };
    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0
    };

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    vb = VertexBuffer(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push_f(2);
    layout.Push_f(2);
    va.AddBuffer(vb, layout);

    ib = IndexBuffer(indices, 6);

    shader = Shader("res/shaders/basic.glsl");
    shader.Bind();

    Texture texture("res/textures/gorilla.png");
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);

    Renderer renderer;

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();
}

void OpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void OpenGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    renderer.Clear();

    renderer.Draw(va, ib, shader);
}
