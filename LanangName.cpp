#define TRUE 1
#define FALSE 0
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

float xi=500, yi=250;
void kotak(float x, float y, float lebar, float tinggi){        //fungsi kotak
        glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+lebar,y);
        glVertex2f(x+lebar,y+tinggi);
        glVertex2f(x,y+tinggi);
        glEnd();
    }

class LanangName{
public:
    int red=255,green=255,blue=255,
        redA=255,greenA=255,blueA=255,
        redN=255,greenN=255,blueN=255,
        redA2=255,greenA2=255,blueA2=255,
        redN2=255,greenN2=255,blueN2=255,
        redG=255,greenG=255,blueG=255,
        redK=255,greenK=0,blueK=255,
        redK2=255,greenK2=255,blueK2=0,
        tinggi=304-180;

    int isSelected=FALSE;

    void doIfPicked(double xpos, double ypos){                                      //sentuh warna
        if(((xpos >252) && (xpos <269)) && ((ypos >180) && (ypos < 304)) ||         //L
           ((xpos >252) && (xpos <322)) && ((ypos >281) && (ypos < 304))){
            red=0,green=0,blue=255;
            redA=255,greenA=0,blueA=255;
            redN=255,greenN=0,blueN=0;
            redA2=255,greenA2=255,blueA2=0;
            redN2=0,greenN2=255,blueN2=255;
            redG=0,greenG=255,blueG=0;

            isSelected = TRUE;
        }
        else if(((xpos >332) && (xpos < 349)) && ((ypos > 180) && (ypos < 304)) ||  //A
                ((xpos >373) && (xpos < 392)) && ((ypos > 180) && (ypos < 304)) ||
                ((xpos >353) && (xpos < 374)) && ((ypos > 180) && (ypos < 203)) ||
                ((xpos >353) && (xpos < 374)) && ((ypos > 240) && (ypos < 263))
                ){
            red=255,green=0,blue=0;
            redA=255,greenA=255,blueA=0;
            redN=0,greenN=255,blueN=0;
            redA2=0,greenA2=255,blueA2=255;
            redN2=255,greenN2=0,blueN2=255;
            redG=0,greenG=0,blueG=255;
            isSelected = TRUE;
        }
        else if(((xpos >407) && (xpos < 428)) && ((ypos > 180) && (ypos < 304)) ||  //N
                ((xpos >448) && (xpos < 468)) && ((ypos > 180) && (ypos < 304)) ||
                ((xpos >427) && (xpos < 449)) && ((ypos > 180) && (ypos < 203))
                ){
            red=255,green=255,blue=0;
            redA=255,greenA=0,blueA=255;
            redN=255,greenN=0,blueN=0;
            redA2=0,greenA2=255,blueA2=255;
            redN2=0,greenN2=0,blueN2=255;
            redG=0,greenG=255,blueG=0;
            isSelected = TRUE;
        }
        else if(((xpos >332+151) && (xpos < 349+151)) && ((ypos > 180) && (ypos < 304)) ||  //A
                ((xpos >373+151) && (xpos < 392+151)) && ((ypos > 180) && (ypos < 304)) ||
                ((xpos >353+151) && (xpos < 374+151)) && ((ypos > 180) && (ypos < 203)) ||
                ((xpos >353+151) && (xpos < 374+151)) && ((ypos > 240) && (ypos < 263))
                ){
            redA2=255,greenA2=255,blueA2=0;
            red=255,green=0,blue=255;
            redN2=255,greenN2=0,blueN2=0;
            redA=0,greenA2=255,blueA=255;
            redG=0,greenG=0,blueG=255;
            redN=0,greenN=255,blueN=0;
            isSelected = TRUE;
        }
        else if(((xpos >407+152) && (xpos < 428+152)) && ((ypos > 180) && (ypos < 304)) ||      //N
                ((xpos >448+152) && (xpos < 468+152)) && ((ypos > 180) && (ypos < 304)) ||
                ((xpos >427+152) && (xpos < 449+152)) && ((ypos > 180) && (ypos < 203))
                ){
            red=0,green=255,blue=0;
            redA=0,greenA=0,blueA=255;
            redN=255,greenN=255,blueN=0;
            redA2=255,greenA2=0,blueA2=0;
            redN2=255,greenN2=0,blueN2=255;
            redG=0,greenG=255,blueG=255;
            isSelected = TRUE;
        }
        else if(((xpos >635) && (xpos < 654)) && ((ypos > 180) && (ypos < 304)) ||              //G
                ((xpos >653) && (xpos < 719)) && ((ypos > 180) && (ypos < 203)) ||
                ((xpos >653) && (xpos <719 )) && ((ypos > 278) && (ypos < 304)) ||
                ((xpos >699) && (xpos <719 )) && ((ypos > 254) && (ypos < 304)) ||
                ((xpos >680) && (xpos <730 )) && ((ypos > 234) && (ypos < 256))
                ){
            red=0,green=255,blue=255;
            redA=255,greenA=255,blueA=0;
            redN=255,greenN=0,blueN=255;
            redA2=0,greenA2=0,blueA2=255;
            redG=255,greenG=0,blueG=0;
            redN2=0,greenN2=255,blueN2=0;
            isSelected = TRUE;
        }
        else{
            red=0,green=255,blue=0;
            redA=255,greenA=0,blueA=255;
            redN=255,greenN=255,blueN=0;
            redA2=255,greenA2=0,blueA2=0;
            redN2=0,greenN2=0,blueN2=255;
            redG=0,greenG=255,blueG=255;
            redK=255,greenK=255,blueK=255,
            redK2=255,greenK2=255,blueK2=255,
            isSelected = FALSE;
        }
    }

void HurufL(){
    float sudut,x,y;

    //kiri
    glColor3ub(red,green,blue);
    kotak(252-xi,180-yi,269-252,tinggi);
    //bawah
    glColor3ub(red,green,blue);
    kotak(269-xi,281-yi,322-269,23);
}

void HurufA(){
    float x,y;
    //kiri
    glColor3ub(redA,greenA,blueA);
    kotak(332-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(redA,greenA,blueA);
    kotak(373-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(redA,greenA,blueA);
    kotak(349-xi,180-yi,373-349,23);
    //tengah
    glColor3ub(redA,greenA,blueA);
    kotak(349-xi,240-yi,373-349,23);
}

void HurufN(){
    float x,y;
    //kiri
    glColor3ub(redN,greenN,blueN);
    kotak(407-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(redN,greenN,blueN);
    kotak(448-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(redN,greenN,blueN);
    kotak(424-xi,180-yi,373-349,23);

}
void HurufA2(){
    float x,y;
    //kiri
    glColor3ub(redA2,greenA2,blueA2);
    kotak(482-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(redA2,greenA2,blueA2);
    kotak(482+39-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(redA2,greenA2,blueA2);
    kotak(485+39-25-xi,180-yi,373-350,23);
    //tengah
    glColor3ub(redA2,greenA2,blueA2);
    kotak(485+39-25-xi,240-yi,373-350,23);
}

void HurufN2(){
    float x,y;
    //kiri
    glColor3ub(redN2,greenN2,blueN2);
    kotak(559-xi,180-yi,269-252,tinggi);
    //kanan
    glColor3ub(redN2,greenN2,blueN2);
    kotak(559+39-xi,180-yi,269-252,tinggi);
    //atas
    glColor3ub(redN2,greenN2,blueN2);
    kotak(562+39-25-xi,180-yi,373-350,23);
}

void HurufG(){
    float x,y;
    //kiri
    glColor3ub(redG,greenG,blueG);
    kotak(635-xi,180-yi,269-252,278-180);
    //kanan
    glColor3ub(redG,greenG,blueG);
    kotak(687-xi,257-yi,269-252,47);
    //atas
    glColor3ub(redG,greenG,blueG);
    kotak(652-xi,180-yi,52,23);
    //mid
    glColor3ub(redG,greenG,blueG);
    kotak(680-xi,237-yi,30,23);
    //bawah
    glColor3ub(redG,greenG,blueG);
    kotak(635-xi,278-yi,52,304-278);

}



void displayName(){
    //glPushMatrix();
    //glTranslatef(0,-80,0);
    //glScalef(0.7,1,0);
    //glColor3ub(255,255,255);
    //kotak(237-xi,180-yi,740-237,313-180);

    HurufL();HurufA();HurufN();HurufA2();HurufN2();HurufG();
    //kotak(0,0,300,300);
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
        if(redK2 <= 1)
            redK2 = 242;
        if(blueK2 <= 1)
            blueK2 = 182;
        if(greenK2 <= 1)
            greenK2 = 158;
        blueK2-=20;
        redK2-=20;
        greenK2-=20;

        if(redK <= 1)
            redK = 242;
        if(blueK <= 1)
            blueK = 182;
        if(greenK <= 1)
            greenK = 158;
        blueK-=20;
        redK-=20;
        greenK-=20;
            //circle(10);
            glRotatef((float)glfwGetTime()*100, 0,0,1);
            glColor3ub(redK,greenK,blueK);
            kotak(-12.5,-12.5,20,20);
            glRotatef(45,0,0,1);
            glColor3ub(redK2,greenK2,blueK2);
            kotak(-12.5,-12.5,20,20);
    }

    void Matahari(){
        int time = 10;
        for(int i=100;i<=2000;i+=6){
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

  void background(){               //background gajelas wkwk
      int xx=-1000;              //lebar
      int yy=-1000;
      int red=0,green=0,blue=0;
//    for (int j=yy;j<=1000;j+=20){
//        for(int i=xx;i<=1000;i+=20){
//            glPushMatrix();
//            glColor3ub(red+j,green+i,blue+i+j);
//            glRotatef(glfwGetTime()*-10,0,0,1);  //kecepatan
//            kotak(i,j,10,10);
//            glPopMatrix();
//
//        }
//    }
    for (int j=yy;j<=1000;j+=20){
        for(int i=xx;i<=1000;i+=20){
            glPushMatrix();
            glColor3ub(red,green+i,blue+i+j);
            glTranslatef(5,5,0);
            glRotatef(90,0,0,1);
            glRotatef(glfwGetTime()*10,0,0,1);  //kecepatan
            kotak(i,j,10,10);
            glPopMatrix();

        }
    }
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
        background();

        //pla.displayPlanet();
        lanang.displayName();



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
