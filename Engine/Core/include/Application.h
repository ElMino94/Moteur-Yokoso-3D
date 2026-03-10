#pragma once

#include <memory>

class Window;
class VulkanContext;

class Application {

public:

	Application();
	~Application();

	void Run();

private:

	void Init();
	void Shutdown();

	bool m_Running = true;

	std::unique_ptr<Window> m_Window;
	std::unique_ptr<VulkanContext> m_Renderer;

};