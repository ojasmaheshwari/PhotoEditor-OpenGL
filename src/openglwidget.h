#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>

class Renderer;
class VertexBuffer;
class VertexArray;
class IndexBuffer;
class Shader;

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();
private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    Renderer* renderer;
    VertexBuffer* vb;
    VertexArray* va;
    IndexBuffer* ib;
    Shader* shader;
};

#endif // OPENGLWIDGET_H
