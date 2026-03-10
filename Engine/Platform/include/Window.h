#pragma once

struct GLFWwindow;

class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    void PollEvents();
    bool ShouldClose() const;

    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }
    const char* GetTitle() const { return m_Title; }

    GLFWwindow* GetNativeWindow() const { return m_Window; }

private:
    int m_Width = 1280;
    int m_Height = 720;
    const char* m_Title = "Yokoso Engine";

    GLFWwindow* m_Window = nullptr;
};