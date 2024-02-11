//
// Created by Steve Wheeler on 26/09/2023.
//

#ifndef VULKANRENDERER_HPP
#define VULKANRENDERER_HPP

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
struct QueueFamilyIndices;
struct SwapChainSupportDetails;

class VulkanRenderer
{
    static constexpr int MAX_FRAMES_IN_FLIGHT = 2;
    uint32_t currentFrame = 0;
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
    std::vector<VkImageView> m_swapChainImageViews;
    VkRenderPass m_renderPass;
    VkPipelineLayout m_pipelineLayout;
    VkPipeline m_graphicsPipeline;
    std::vector<VkFramebuffer> m_swapChainFramebuffers;
    VkCommandPool m_commandPool;
    std::vector<VkCommandBuffer> m_commandBuffers;
    std::vector<VkSemaphore> m_imageAvailableSemaphores;
    std::vector<VkSemaphore> m_renderFinishedSemaphores;
    std::vector<VkFence> m_inFlightFences;

    void createRenderPass();
    
    void createGraphicsPipeline();
    
    void createFramebuffers();
    
    void createCommandPool();
    
    void createCommandBuffers();
    
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    void createSwapChain();
    
    void createImageViews();

    void createInstance();
    
    void createSurface();
    
    void createSyncObjects();

    void initWindow();

    void initVulkan();
    
    void drawFrame();

    void mainLoop();

    void cleanup();

    static bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    VkShaderModule createShaderModule(const std::vector<char> &code);

    bool isDeviceSuitable(VkPhysicalDevice device);

    void pickPhysicalDevice();

    void createLogicalDevice();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    
public:
    void run();
};


#endif //VULKANRENDERER_HPP
