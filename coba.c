#define TRUE 1
#define FALSE 0
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE); // close program on ESC key
}

void setup_viewport(GLFWwindow* window)
{
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1500, 680,0, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

  void display(){
    glBegin(GL_QUADS);
    //kiri
    glColor3ub(53,92,125);
    glVertex2f(0,0);
    glVertex2f(0,600);
    //kanan
    glColor3ub(192,108,132);
    glVertex2f(1000,600);
    glVertex2f(1000,0);
    glEnd();
}
int xi=750, yi=340;


void HurufL(double xpos=0, double ypos=0){
    float sudut,x,y;
    int red=255,green=255,blue=255;

    int isSelected = FALSE;
    int isDragged = FALSE;
        if(((xpos > 182) && (xpos < 221)) &&
           ((ypos > 208) && (ypos < 457))){
            red = 0; green = 255; blue = 0;
            isSelected = TRUE;
            if(isDragged == TRUE){
                x = xpos;
                y = ypos;
            }
        }
        else{
            red = green = blue = 255;
            isSelected = FALSE;
        }
    //glRotatef((float) glfwGetTime()* 100,0,0,1);
    //glTranslatef(0,0,0);

    glBegin(GL_QUADS);
    glColor3f(red,green,blue);
    glVertex2d(182,208);
    glVertex2d(221,208);
    glVertex2d(221,457);
    glVertex2d(182,457);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(red,green,blue);
    glVertex2d(221,410);
    glVertex2d(334,410);
    glVertex2d(334,457);
    glVertex2d(221,457);



}

void HurufA(){
    float x,y;
    //kiri
    glBegin(GL_QUADS);
    glVertex2d(355,457);
    glVertex2d(355,208);
    glVertex2d(400,208);
    glVertex2d(400,457);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glVertex2d(355+85,457);
    glVertex2d(355+85,208);
    glVertex2d(400+85,208);
    glVertex2d(400+85,457);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glVertex2d(400,208);
    glVertex2d(440,208);
    glVertex2d(355+85,255);
    glVertex2d(400,255);
    glEnd();

    //tengah
    glBegin(GL_QUADS);
    glVertex2d(400,208+120);
    glVertex2d(440,208+120);
    glVertex2d(355+85,255+120);
    glVertex2d(400,255+120);
    glEnd();
}

void HurufN(){
    float x,y;
    //kiri
    glBegin(GL_QUADS);
    glVertex2d(355+160,457);
    glVertex2d(355+160,208);
    glVertex2d(400+160,208);
    glVertex2d(400+160,457);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glVertex2d(355+85+160,457);
    glVertex2d(355+85+160,208);
    glVertex2d(400+85+160,208);
    glVertex2d(400+85+160,457);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glVertex2d(400+160,208);
    glVertex2d(440+160,208);
    glVertex2d(355+85+160,255);
    glVertex2d(400+160,255);
    glEnd();

}

void HurufA2(){
    float x,y;
    int a=320;
    //kiri
    glBegin(GL_QUADS);
    glVertex2d(355+a,457);
    glVertex2d(355+a,208);
    glVertex2d(400+a,208);
    glVertex2d(400+a,457);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glVertex2d(355+85+a,457);
    glVertex2d(355+85+a,208);
    glVertex2d(400+85+a,208);
    glVertex2d(400+85+a,457);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glVertex2d(400+a,208);
    glVertex2d(440+a,208);
    glVertex2d(355+85+a,255);
    glVertex2d(400+a,255);
    glEnd();

    //tengah
    glBegin(GL_QUADS);
    glVertex2d(400+a,208+120);
    glVertex2d(440+a,208+120);
    glVertex2d(355+85+a,255+120);
    glVertex2d(400+a,255+120);
    glEnd();
}

void HurufN2(){
    float x,y;
    int a=325;
    //kiri
    glBegin(GL_QUADS);
    glVertex2d(355+160+a,457);
    glVertex2d(355+160+a,208);
    glVertex2d(400+160+a,208);
    glVertex2d(400+160+a,457);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glVertex2d(355+85+160+a,457);
    glVertex2d(355+85+160+a,208);
    glVertex2d(400+85+160+a,208);
    glVertex2d(400+85+160+a,457);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glVertex2d(400+160+a,208);
    glVertex2d(440+160+a,208);
    glVertex2d(355+85+160+a,255);
    glVertex2d(400+160+a,255);
    glEnd();

}

void HurufG(){
    float x,y;
    //glTranslatef (0,(float) glfwGetTime()*100,0); // Bergeser ke kanan 100

    //kiri
    glBegin(GL_QUADS);
    glVertex2d(1002,457);
    glVertex2d(1002,208);
    glVertex2d(1045,208);
    glVertex2d(1045,457);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glVertex2d(1002+137,457);
    glVertex2d(1002+137,361);
    glVertex2d(1045+137,361);
    glVertex2d(1045+137,457);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glVertex2d(1002,208);
    glVertex2d(1182,208);
    glVertex2d(1182,260);
    glVertex2d(1002,260);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glVertex2d(1002,208+197);
    glVertex2d(1182,208+197);
    glVertex2d(1182,260+197);
    glVertex2d(1002,260+197);
    glEnd();

    //mid
    glBegin(GL_QUADS);
    glVertex2d(1097,316);
    glVertex2d(1097,361);
    glVertex2d(1206,361);
    glVertex2d(1206,316);
    glEnd();
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    HurufL(xpos, ypos);
}

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    window = glfwCreateWindow(1000, 500, "LANANG - G64170095", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);


    while (!glfwWindowShouldClose(window))
    {
        setup_viewport(window);
        //display();

        HurufL();
        HurufA();
        HurufN();
        HurufA2();
        HurufN2();
        HurufG();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
