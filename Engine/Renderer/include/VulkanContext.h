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
    void CreateSurface();

    void PickPhysicalDevise();


    Window* m_Window = nullptr;

    VkInstance m_Instance = VK_NULL_HANDLE;
    VkSurfaceKHR m_Surface = VK_NULL_HANDLE;

    VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;

};