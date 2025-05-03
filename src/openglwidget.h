#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <Texture.h>

class Renderer;
class VertexBuffer;
class VertexArray;
class IndexBuffer;
class Shader;
class VertexBufferLayout;

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget();

    void LoadImage(const std::string &filePath);
private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    Texture* texture;
    Renderer* renderer;
    VertexBuffer* vb;
    VertexArray* va;
    IndexBuffer* ib;
    Shader* shader;
    VertexBufferLayout* layout;
};

#endif // OPENGLWIDGET_H
