#define TRUE 1
#define FALSE 0
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float xi=500, yi=250;
class LanangName{
public:
    int red=255,green=255,blue=255,
        red1=255,green1=255,blue1=255,
        tinggi=304-180;

    int isSelected=FALSE;

    void doIfPicked(double xpos, double ypos){
        if(((xpos >129-xi) && (xpos < 157-xi)) && ((ypos < 332-yi) && (ypos > 130-yi))){
            red = 0; green = 255; blue = 0;
            isSelected = TRUE;
        }
        else if(((xpos >129-xi) && (xpos < 235-xi)) && ((ypos < 379-yi) && (ypos > 332-yi))){
            red1 = 0; green1 = 0; blue1 = 225;
            isSelected = TRUE;
        }
        else{
            red = green = blue = 255;
            red1 = green1 = blue1 = 225;
            isSelected = FALSE;
        }
    }

    void kotak(float x, float y, float lebar, float tinggi){
        glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+lebar,y);
        glVertex2f(x+lebar,y+tinggi);
        glVertex2f(x,y+tinggi);
        glEnd();
    }

void HurufL(){
    float sudut,x,y;
    //kiri
    glColor3ub(255,0,0);
    kotak(252-xi,180-yi,269-252,tinggi);
    //bawah
    glColor3ub(255,255,0);
    kotak(269-xi,281-yi,322-269,23);
}

void HurufA(){
    float x,y;
    //kiri
    glColor3ub(0,255,255);
    kotak(332-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(0,255,0);
    kotak(373-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(255,255,0);
    kotak(349-xi,180-yi,373-349,23);
    //tengah
    glColor3ub(255,0,255);
    kotak(349-xi,240-yi,373-349,23);
}

void HurufN(){
    float x,y;
    //kiri
    glColor3ub(0,0,129);
    kotak(407-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(204,255,255);
    kotak(448-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(0,255,100);
    kotak(424-xi,180-yi,373-349,23);

}
void HurufA2(){
    float x,y;
    //kiri
    glColor3ub(100,255,0);
    kotak(482-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(0,100,100);
    kotak(482+39-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(255,100,0);
    kotak(485+39-25-xi,180-yi,373-350,23);
    //tengah
    glColor3ub(204,153,100);
    kotak(485+39-25-xi,240-yi,373-350,23);
}

void HurufN2(){
    float x,y;
    //kiri
    glColor3ub(255,0,255);
    kotak(559-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(255,255,204);
    kotak(559+39-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(0,255,255);
    kotak(562+39-25-xi,180-yi,373-350,23);
}

void HurufG(){
    float x,y;
    //kiri
    glColor3ub(255,255,0);
    kotak(635-xi,180-yi,269-252,278-180);
    //kanan
    glColor3ub(0,255,255);
    kotak(687-xi,257-yi,269-252,47);
    //atas
    glColor3ub(0,255,0);
    kotak(652-xi,180-yi,52,23);
    //mid
    glColor3ub(255,0,255);
    kotak(680-xi,237-yi,30,23);
    //bawah
    glColor3ub(255,0,0 );
    kotak(635-xi,278-yi,52,304-278);

}

void displayName(){
    //glPushMatrix();
    //glTranslatef(0,-80,0);
    //glScalef(0.7,1,0);
    //glColor3ub(255,255,255);
    //kotak(237-xi,180-yi,740-237,313-180);
    HurufL();HurufA();HurufN();HurufA2();HurufN2();HurufG();

    //glPopMatrix();
}
};

class Planet: public LanangName{
public:
    void displayPlanet(){
        Matahari();
    }
    int rot = 10;
    int press = FALSE;
private:
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

    void Mata(){
            circle(10);
            glRotatef((float)glfwGetTime()*50, 0,0,1);
            kotak(-12.5,-12.5,25,25);
            glRotatef(45,0,0,1);
            kotak(-12.5,-12.5,25,25);
    }

    void Matahari(){
        int time = 10;
        for(int i=100;i<=2000;i+=10){
            glPushMatrix();
                glRotatef((float)glfwGetTime()*time,0,0,1);
                glTranslatef(0,i,0);
                Mata();
            glPopMatrix();
            time+=10;
        }
    }
};
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
    glOrtho(-500, 500, 250,-250, 1.f, -1.f);
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


LanangName lanang;
Planet pla;

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    lanang.doIfPicked(xpos, ypos);
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

        pla.displayPlanet();
        lanang.displayName();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
