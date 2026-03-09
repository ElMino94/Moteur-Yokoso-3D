#pragma once

class Application {

public:

	Application();
	~Application();

	void Run();

private:

	void Init();
	void Shutdown();

	bool m_Running = true;

};