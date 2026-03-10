#include "VulkanContext.h"

#include "Logger.h"
#include "Window.h"

#include <GLFW/glfw3.h>

#include <vector>

VulkanContext::VulkanContext(Window* window) : m_Window(window){}

VulkanContext::~VulkanContext() {

	Shutdown();

}

void VulkanContext::Init() {

	Logger::Log("Initializing Vulkan :3");
	CreateInstance();

}

void VulkanContext::Shutdown() {

	if (m_Instance != VK_NULL_HANDLE) {

		vkDestroyInstance(m_Instance, nullptr);
		m_Instance = VK_NULL_HANDLE;

	}

	Logger::Log("Vulkan shutdown :0");

}

void VulkanContext::CreateInstance() {

	VkApplicationInfo appInfo{};

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Yokoso Engine ";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "Yokoso";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_3;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> entensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = static_cast<uint32_t>(entensions.size());
	createInfo.ppEnabledExtensionNames = entensions.data();

	if (vkCreateInstance(&createInfo, nullptr, &m_Instance) != VK_SUCCESS) {

		Logger::Error("Failed to create Vulkan Instance");
		return;

	}

	Logger::Log("Vulkan Instance created");

}