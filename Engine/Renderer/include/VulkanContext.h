#pragma once

#include <vulkan/vulkan.h>

class Window;

class VulkanContext{

public:
    VulkanContext(Window* window);
    ~VulkanContext();

    void Init();
    void Shutdown();

private:
    void CreateInstance();

    Window* m_Window = nullptr;

    VkInstance m_Instance = VK_NULL_HANDLE;
};