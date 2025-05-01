#pragma once

class VertexBuffer;
class VertexBufferLayout;

class VertexArray {
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;
};
