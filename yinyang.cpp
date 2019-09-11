#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define ver 350

int transX,transY;

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
    }
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
    }

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    transX = xpos;
    transY = ypos;
}

void setup_viewport(GLFWwindow* window){
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-350, 350, 350, -350, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void circle(float size){
        int N = 180;
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

void SetengahcircleKiri(float size){
        int N = 180;
        float pX, pY;
        glBegin(GL_POLYGON);
        for(int i = 0; i < N; i++)
        {
            pX = -sin(i*2*3.14 / N/2);
            pY = -cos(i*2*3.14 / N/2);
            glVertex2f(pX * size, pY * size);
        }
        glEnd();
    }

void SetengahcircleKanan(float size){
        int N = 180;
        float pX, pY;

        glBegin(GL_POLYGON);
        for(int i = 0; i < N; i++)
        {
            pX = sin(i*2*3.14 / N/2);
            pY = cos(i*2*3.14 / N/2);
            glVertex2f(pX * size, pY * size);
        }
        glEnd();
    }

void display(){
    glBegin(GL_QUADS);
    //kiri
    glColor3ub(255,255,225);
    glVertex2f(-500,-500);
    glVertex2f(-500,500);
    //kanan
    glColor3ub(0,0,0);
    glVertex2f(500,500);
    glVertex2f(500,-500);
    glEnd();
}

void setup_blend(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
}

void yinyang(int size){
    glRotatef(glfwGetTime()*100,0,0,1);
    glColor3ub(0,0,0);
    SetengahcircleKiri(size);

    glColor3ub(255,255,255);
    SetengahcircleKanan(size);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0,size/2,0);
    circle(size/2);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0,-size/2,0);
    circle(size/2);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0,-size/2,0);
    circle(size/6);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0,size/2,0);
    circle(size/6);
    glPopMatrix();
}


int main(void) {

    //Window
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())exit(EXIT_FAILURE);
    window = glfwCreateWindow(700, 700, "Yin Yang", NULL, NULL);

    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    while (!glfwWindowShouldClose(window)){
        setup_blend();
        setup_viewport(window);
        display();

        glPushMatrix();
        glTranslatef(transX-350,transY-350,0);
        yinyang(20);
        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
