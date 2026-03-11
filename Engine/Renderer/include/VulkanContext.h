#pragma once

#include <vulkan/vulkan.h>
#include <optional>

class Window;

struct QueueFamilyIndices {

    std::optional<uint32_t> GraphicsFamily;
    std::optional<uint32_t> PresentFamily;

    bool IsComplete() const {
        
        return GraphicsFamily.has_value() && PresentFamily.has_value();

    }

};


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

    void CreateLogicalDevice();

    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);


    Window* m_Window = nullptr;

    VkInstance m_Instance = VK_NULL_HANDLE;
    VkSurfaceKHR m_Surface = VK_NULL_HANDLE;

    VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
    VkDevice m_Device = VK_NULL_HANDLE;

    VkQueue m_GraphicsQueue = VK_NULL_HANDLE;
    VkQueue m_PresentQueue = VK_NULL_HANDLE;



};