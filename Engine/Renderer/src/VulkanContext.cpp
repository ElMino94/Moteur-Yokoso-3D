#include "VulkanContext.h"

#include "Logger.h"
#include "Window.h"

#include <GLFW/glfw3.h>

#include <vector>
#include <set>

VulkanContext::VulkanContext(Window* window) : m_Window(window){}

VulkanContext::~VulkanContext() {

	Shutdown();

}

void VulkanContext::Init() {

	Logger::Log("Initializing Vulkan :3");
	CreateInstance();
	CreateSurface();
	PickPhysicalDevise();

}

void VulkanContext::Shutdown()
{
	if (m_Surface != VK_NULL_HANDLE)
	{
		vkDestroySurfaceKHR(m_Instance, m_Surface, nullptr);
		m_Surface = VK_NULL_HANDLE;
	}

	if (m_Instance != VK_NULL_HANDLE)
	{
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

void VulkanContext::CreateSurface() {
	
	if (glfwCreateWindowSurface(m_Instance, m_Window->GetNativeWindow(), nullptr, &m_Surface) != VK_SUCCESS){

		Logger::Error("Failed to create Vulkan surface");
		return;

	}

	Logger::Log("Vulkan surface created");

}

void VulkanContext::PickPhysicalDevise() {

	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(m_Instance, &deviceCount, nullptr);

	if (deviceCount == 0) {

		Logger::Error("Failed to find GPU with vulkan supp");
		return;

	}

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(m_Instance, &deviceCount, devices.data());

	for (const auto& device : devices) {

		QueueFamilyIndices indices = FindQueueFamilies(device);

		if (indices.IsComplete()) {

			m_PhysicalDevice = device;
			Logger::Log("Physical device selected");
			return;

		}

	}

	Logger::Error("Failed to find a suitable gpu");

}

QueueFamilyIndices VulkanContext::FindQueueFamilies(VkPhysicalDevice device) {

	QueueFamilyIndices indices;

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

	uint32_t index = 0;

	for (const auto& queueFamily : queueFamilies) {

		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {

			indices.GraphicsFamily = index;

		}

		VkBool32 presentSupport = VK_FALSE;
		vkGetPhysicalDeviceSurfaceSupportKHR(device, index, m_Surface, &presentSupport);

		if (presentSupport) {

			indices.PresentFamily = index;

		}

		if (indices.IsComplete()) {

			break;

		}

		index++;

	}

	return indices;

}

