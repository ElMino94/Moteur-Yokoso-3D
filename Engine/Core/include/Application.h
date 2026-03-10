#pragma once

#include <memory>

class Window;

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

};