#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>


// Function prototypes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{

    // initi window hints
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Nebula", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // allow window resizing
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD manages function pointers for OpenGL so we want to initialize GLAD
    // before we call any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Before we can render we need to tell OpenGL the size of the rendering
    // window
    glViewport(0, 0, 800, 600);



    // start render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Function Implementation
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}