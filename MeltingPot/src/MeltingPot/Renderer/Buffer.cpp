#include "mppch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "MeltingPot/Platform/OpenGL/OpenGLBuffer.h"

namespace MeltingPot {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		MP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}

		MP_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:		MP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:	return new OpenGLIndexBuffer(indices, size);
		}

		MP_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}