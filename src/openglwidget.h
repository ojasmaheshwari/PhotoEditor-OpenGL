#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <qopenglwidget.h>

#include "Renderer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget* parent = nullptr);
private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    Renderer renderer;
    VertexBuffer vb;
    VertexArray va;
    IndexBuffer ib;
    Shader shader;
};

#endif // OPENGLWIDGET_H
