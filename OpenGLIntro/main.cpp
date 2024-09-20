#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int screen[] = { 640, 480 };

int main(int, char**) {

    //Initialize and Check
    if (!glfwInit())
    {
        return -1;
    }

    //Create Window and Pass GLAD
    GLFWwindow* window = glfwCreateWindow(screen[0], screen[1], "Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -1;
    }

    //Set Size of Viewport and Create Callback for resizing
    glViewport(0, 0, screen[0], screen[1]);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glClearColor(0.25f, 0.5f, 0.75f, 1.0f); //Set Background Color


    //Runs Window
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    //Finishes Application
    glfwTerminate();
    return 0;
}

//Resize Window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//Inputs
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}