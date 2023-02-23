#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "App.h"
#include "Figures.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

 
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    } 

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Smth wrng!";
    }
    /* Loop until the user closes the window */
    float graphArray[] = {
        -1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(1, 1, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

 /*
        glBegin(GL_TRIANGLES);

        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 1, 0);

        glEnd();

        glFlush(); */
        /* Swap front and back buffers */
        paintTriangle();
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}