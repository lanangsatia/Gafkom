#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define ver 350

class Myname{
    public:
        float red = 192; float green = 108; float blue = 132; float alfa = 200;
        float tinggiatas = 23; float tinggitengah = 18;
    void lingkaran(float x, float y, float radx, float rady, int alpha, int tandasin, int tandacos){
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x,y);
        for (int i=0; i <= alpha; i++){
            float rad = i*M_PI/180;
            float xi = x + tandasin*sin(rad)*radx;
            float yi = y + tandacos*cos(rad)*rady;
            glVertex2f(xi,yi);
        }
        glEnd();
    }

    void kotak(float x, float y, float lebar, float tinggi){
        glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+lebar,y);
        glVertex2f(x+lebar,y+tinggi);
        glVertex2f(x,y+tinggi);
        glEnd();
    }

    void HurufS(){
        //lengkung kanan
        glColor4ub(red,green,blue,alfa);
        lingkaran(247-ver, 361-ver, 261-247, tinggitengah, 90, 1, -1);
        //lengkung kiri
        lingkaran(212-ver, 343-ver, 212-198, tinggitengah, 90, -1, 1);
        //atas
        kotak(198-ver,315-ver, 261-198, tinggiatas);
        //tengah
        kotak(212-ver, 343-ver, 247-212, tinggitengah);
        //bottom
        kotak(198-ver, 367-ver, 261-198, tinggiatas);
    }

    void HurufI(){
        //atas
        kotak(267-ver, 315-ver, 304-267, tinggiatas);
        kotak(267-ver, 367-ver, 304-267, tinggiatas);
        kotak(267-ver, 343-ver, 304-267, tinggitengah);
    }

    void HurufN(){
        //atas
        lingkaran(309-ver, 338-ver, 342-309, tinggiatas, 90, 1, -1);
        kotak(355-ver, 315-ver, 372-355, tinggiatas);

        kotak(309-ver, 343-ver, 326-309, tinggitengah);
        kotak(355-ver, 343-ver, 372-355, tinggitengah);

        glBegin(GL_POLYGON);
        glColor4ub(red,green,blue,alfa);
        glVertex2f(327-ver, 343-ver);
        glVertex2f(342-ver, 343-ver);
        glVertex2f(354-ver, 343+tinggitengah-ver);
        glVertex2f(339-ver, 343+tinggitengah-ver);
        glEnd();

        kotak(309-ver, 367-ver, 326-309, tinggiatas);
        lingkaran(372-ver, 367-ver, 372-339, tinggiatas, 90, -1, 1);
    }

    void HurufA(){
        lingkaran(393-ver, 338-ver, 15, tinggiatas, 90,-1,-1);
        kotak(393-ver, 315-ver, 426-393, tinggiatas);
        lingkaran(426-ver, 338-ver, 441-426, tinggiatas, 90, 1, -1);

        kotak(378-ver, 343-ver, 441-378, tinggitengah);

        kotak(378-ver, 367-ver, 397-378, tinggiatas);
        kotak(422-ver, 367-ver, 397-378, tinggiatas);
    }

    void HurufT(){
        lingkaran(466-ver, 338 -ver, 466-447, tinggiatas, 90, -1, -1);
        kotak(466-ver, 315-ver, 491-466, tinggiatas);
        lingkaran(491-ver, 338-ver, 466-447, tinggiatas, 90, 1, -1);

        kotak(466-ver, 343-ver, 491-466, tinggitengah);
        kotak(466-ver, 367-ver, 491-466, tinggiatas);
    }

    void displayName(){
        HurufS();HurufI();HurufA();HurufN();HurufT();
    }
};

class Planet: public Myname{
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

    void Jupiter(){
        glPushMatrix();
            glRotatef((float)glfwGetTime()*-rot, 0,0,1);
            glTranslatef(430-ver, 176-ver,0);
            glColor3ub(200,185,183);
            circle(30);
        glPopMatrix();
    }

    void Saturnus(){
        glPushMatrix();
            glRotatef((float)glfwGetTime()*rot, 0,0,1);
            glTranslatef(603-ver, 417-ver,0);
            glColor3ub(212,179,192);
            circle(30);
            glRotatef((float)glfwGetTime()*20, 0,0,1);
            lingkaran(0,0,20,50,360,1,1);
        glPopMatrix();
    }
};

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
    }
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
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

void display(){
    glBegin(GL_QUADS);
    //kiri
    glColor3ub(53,92,125);
    glVertex2f(-500,-500);
    glVertex2f(-500,500);
    //kanan
    glColor3ub(192,108,132);
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

Myname name;
Planet planet;

int main(void) {
    //Window
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())exit(EXIT_FAILURE);
    window = glfwCreateWindow(700, 700, "BOKU NO NAWA", NULL, NULL);

    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)){
        setup_blend();
        setup_viewport(window);
        display();

        planet.displayPlanet();

        if(name.red <= 53)
            name.red = 242;
        if(name.blue <= 125)
            name.blue = 182;
        if(name.green <= 92)
            name.green = 158;
        name.blue-=0.1;
        name.red-=0.1;
        name.green-=0.1;

        name.displayName();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
