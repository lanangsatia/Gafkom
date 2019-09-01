#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define xmin -10
#define xmax 10
#define ymin -10
#define ymax 10

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static void grid(int x, int y)
{
    int i;
    glColor3f(.2,.2,.2);
    glBegin(GL_LINES);
    for(i=-x; i<=x; i+=10)
    {
        glVertex2f(i,-y);
        glVertex2f(i,y);
    }
    for(i=-y; i<=y; i++)
    {
        glVertex2f(-x,i);
        glVertex2f(x,i);
    }
    glColor3f(0.7,1,0.7);
    glVertex2f(-x,0);
    glVertex2f(x,0);
    glVertex2f(0,-y);
    glVertex2f(0,y);
    glEnd();
}

void circle(float size)
{
    int N = 30;
    float pX, pY;
    glBegin(GL_POLYGON);
    for(int i = 0; i < N; i++)
    {
        pX = sin(i*2*3.14 / N);
        pY = cos(i*2*3.14 / N);
        glVertex2f(pX * size, pY * size);
    }
    glEnd();
}

float angle_earth = 0.0, angle_moon = 0.0;
void display()
{
    //matahari
    glColor3ub(255, 205, 25);
    circle(3);
    //bumi
    glRotatef((float) glfwGetTime()*50.f,0.f,0.f,1.f);
    glTranslatef(5.5, 5.5, 0);
    glColor3ub(27, 99, 209);
    circle(1);
    //moon
    glRotatef((float) glfwGetTime()*150.f,0.f,0.f,1.f);
    glTranslatef(1.3, 1.3, 0);
    glColor3ub(219, 210, 208);
    circle(0.5);
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(400, 400, "Semesta Matahari, Bumi, dan Bulan", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width * 10 / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(xmin, xmax, ymin, ymax, 1, -1);
        //glOrtho(-ratio, ratio, ymin, ymax, 1, -1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        display();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
