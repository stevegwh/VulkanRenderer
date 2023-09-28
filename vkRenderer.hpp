//
// Created by Steve Wheeler on 26/09/2023.
//

#ifndef VKRENDERER_HPP
#define VKRENDERER_HPP

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
struct QueueFamilyIndices;
struct SwapChainSupportDetails;

class vkRenderer
{
    GLFWwindow* m_window{};
    VkInstance m_instance{};
    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
    VkDevice m_device{};
    VkSurfaceKHR m_surface{};
    VkQueue m_presentQueue{};
    VkQueue m_graphicsQueue{};
    VkSwapchainKHR m_swapChain{};
    std::vector<VkImage> m_swapChainImages;
    VkFormat m_swapChainImageFormat;
    VkExtent2D m_swapChainExtent;

    void createInstance();
    
    void createSurface();

    void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup();

    static bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    bool isDeviceSuitable(VkPhysicalDevice device);

    void pickPhysicalDevice();

    void createLogicalDevice();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);


public:
    void run();

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::__1::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);
    void createSwapChain();
};


#endif //VKRENDERER_HPP
