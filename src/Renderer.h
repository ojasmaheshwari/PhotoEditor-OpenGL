#pragma once

#include "GL/glew.h"

class VertexArray;
class IndexBuffer;
class Shader;

class Renderer {
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
