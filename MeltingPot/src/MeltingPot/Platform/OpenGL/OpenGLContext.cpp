#include "mppch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace MeltingPot {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		MP_CORE_ASSERT(windowHandle, "Window handle is null!");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MP_CORE_ASSERT(status, "Failed to initialize Glad!");

		MP_CORE_INFO("OpenGL Info:");
		MP_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		MP_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		MP_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}