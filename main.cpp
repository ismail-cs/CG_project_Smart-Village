//#include <windows.h>  // for MS Windows


#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#include<cstdio>
using namespace std;






GLfloat position = 65.0f;
GLfloat position1 = -40.0f;

GLfloat car1_position_x = -40.0f;
GLfloat car1_position_y = -1.0f;
GLfloat car_1_speed = 2.0f;

GLfloat speed = 1.0f;



GLfloat car2_position_x = -40.0f;
GLfloat car2_position_y = 1.0f;
GLfloat car_2_speed = 2.0f;

void display();

void boat_animation_1(int value) {

    if(position <-190.0)
        position = 70.0f;

    position -= speed;

	glutPostRedisplay();


	glutTimerFunc(100,boat_animation_1,0);
}



void boat_animation_2(int value) {

    if(position1 >50.0)
        position1 = -160.0f;

    position1 += speed;

	glutPostRedisplay();


	glutTimerFunc(100,boat_animation_2,0);
}



void car_animation_1(int value) {

    if(car1_position_x >80.0){
        car1_position_x = -160.0f;
        car1_position_y = -7.0f;
    }

    car1_position_x += car_1_speed;
    car1_position_y += 0.1;

	glutPostRedisplay();


	glutTimerFunc(100,car_animation_1,0);
}


void car_animation_2(int value) {

    if(car2_position_x < -160.0){
        car2_position_x = 80.0f;
        car2_position_y = 6.0f;
    }

    car2_position_x -= car_2_speed;
    car2_position_y -= 0.08;

	glutPostRedisplay();


	glutTimerFunc(100,car_animation_2,0);
}



void disback(int val)
{
    glutDisplayFunc(display);
}











void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
    glEnd();
}

void rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b){
    glBegin(GL_POLYGON);       // line 1
	glColor3ub(r, g, b);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        glVertex2f(x4, y4);
        glVertex2f(x1, y1);
    glEnd();
}

void tangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b){
    glBegin(GL_POLYGON);       // line 1
	glColor3ub(r, g, b);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);

        glVertex2f(x2, y2);
        glVertex2f(x3, y3);

        glVertex2f(x3, y3);
        glVertex2f(x1, y1);
    glEnd();
}



void road(){ //main road

    glBegin(GL_POLYGON);   // main road
	glColor3ub(180, 180, 180);
        glVertex2f(-110, -24);
        glVertex2f(110, -13);
        glVertex2f(110, 3);
        glVertex2f(-110, -2);
    glEnd();


    glBegin(GL_POLYGON);   // mid line
	glColor3ub(255, 255, 255);
        glVertex2f(-110, -13.5);
        glVertex2f(110, -5.5);
        glVertex2f(110, -4);
        glVertex2f(-110, -12);
    glEnd();


    glBegin(GL_POLYGON);   // main road down line
	glColor3ub(95, 95, 95);
        glVertex2f(-110, -26);
        glVertex2f(110, -15);
        glVertex2f(110, -13);
        glVertex2f(-110, -24);
    glEnd();



    glBegin(GL_POLYGON);   // main road upp line
	glColor3ub(95, 95, 95);
        glVertex2f(-110, -2);
        glVertex2f(110, 2);
        glVertex2f(110, 4);
        glVertex2f(-110, 0);
    glEnd();




}


void road_mid_line(int r, int g, int b){   // cross croo line
    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-100, -18);
        glVertex2f(-90, -18);
        glVertex2f(-90, -5);
        glVertex2f(-100, -5);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-80, -18);
        glVertex2f(-70, -18);
        glVertex2f(-70, -5);
        glVertex2f(-80, -5);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-60, -18);
        glVertex2f(-50, -18);
        glVertex2f(-50, -5);
        glVertex2f(-60, -5);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-40, -18);
        glVertex2f(-30, -18);
        glVertex2f(-30, -5);
        glVertex2f(-40, -5);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-20, -15);
        glVertex2f(-10, -15);
        glVertex2f(-10, -1);
        glVertex2f(-20, -1);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(0, -15);
        glVertex2f(10, -15);
        glVertex2f(10, -1);
        glVertex2f(0, -1);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(20, -15);
        glVertex2f(30, -15);
        glVertex2f(30, -1);
        glVertex2f(20, -1);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(40, -15);
        glVertex2f(50, -15);
        glVertex2f(50, -1);
        glVertex2f(40, -1);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(60, -15);
        glVertex2f(70, -15);
        glVertex2f(70, -1);
        glVertex2f(60, -1);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(80, -12);
        glVertex2f(90, -12);
        glVertex2f(90, 1);
        glVertex2f(80, 1);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(100, -12);
        glVertex2f(110, -12);
        glVertex2f(110, 2);
        glVertex2f(100, 2);
    glEnd();
}


void lamp_post(){

    int x = -105, y= -25;

    for(int i =0, j=0; i<22; i++, j++){

        glBegin(GL_POLYGON);   // main line
        glColor3ub(59, 81, 0);
            glVertex2f(x, y);
            glVertex2f(x+0.6, y);
            glVertex2f(x+0.6, y+6);
            glVertex2f(x, y+6);
        glEnd();

        circle(0.6, x+1.5, y+7.4, 130, 120, 0);  // light

        glBegin(GL_POLYGON);   // up line
        glColor3ub(59, 81, 0);
            glVertex2f(x, y+6);
            glVertex2f(x+0.6, y+6);
            glVertex2f(x+1.6, y+8);
            glVertex2f(x+1, y+8);
        glEnd();

        x += 10;
        if(j%2==0){
            y++;
        }

    }
}

void river(int r, int g, int b){

    glBegin(GL_POLYGON);   // upp mut
	glColor3ub(143, 131, 70);

        glVertex2f(-110, -60);
        glVertex2f(110, -60);

        glVertex2f(110, -32);
        glVertex2f(65, -29);
        glVertex2f(55, -28);
        glVertex2f(45, -27);
        glVertex2f(35, -26);
        glVertex2f(0, -25);
        glVertex2f(-35, -26);
        glVertex2f(-45, -27);
        glVertex2f(-55, -28);
        glVertex2f(-65, -29);
        glVertex2f(-110, -32);

    glEnd();


    glBegin(GL_POLYGON);   // main river
	glColor3ub(r, g, b);

        glVertex2f(-110, -60);
        glVertex2f(110, -60);

        glVertex2f(110, -34);
        glVertex2f(65, -31);
        glVertex2f(55, -30);
        glVertex2f(45, -29);
        glVertex2f(35, -28);
        glVertex2f(0, -27);
        glVertex2f(-35, -28);
        glVertex2f(-45, -29);
        glVertex2f(-55, -30);
        glVertex2f(-65, -31);
        glVertex2f(-110, -34);

    glEnd();






     glBegin(GL_POLYGON);   // down mut
	glColor3ub(143, 131, 70);

        glVertex2f(-110, -62);
        glVertex2f(110, -62);

        glVertex2f(110, -60);
        glVertex2f(50, -57);
        glVertex2f(0, -56);
        glVertex2f(-50, -57);
        glVertex2f(-110, -60);

    glEnd();



    glBegin(GL_POLYGON);   // down fild
	glColor3ub(23, 219, 0);

        glVertex2f(-110, -70);
        glVertex2f(110, -70);

        glVertex2f(110, -62);
        glVertex2f(50, -59);
        glVertex2f(0, -58);
        glVertex2f(-50, -59);
        glVertex2f(-110, -62);

    glEnd();









}


void river_wave(int r, int g, int b){

glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-60, -40);
        glVertex2f(-45, -40.5);
        glVertex2f(-35, -40);
        glVertex2f(-35, -39.5);
        glVertex2f(-59, -39);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-60, -30);
        glVertex2f(-30, -30);
        glVertex2f(-30, -29.5);
        glVertex2f(-33, -28.5);
        glVertex2f(-59, -29.7);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(50, -40);
        glVertex2f(20, -40);
        glVertex2f(20, -39.5);
        glVertex2f(23, -38.5);
        glVertex2f(49, -39.7);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-20, -38);
        glVertex2f(20, -38);
        glVertex2f(20, -37.5);
        glVertex2f(23, -36.5);
        glVertex2f(-29, -37.7);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-55, -34);
        glVertex2f(-40, -34.5);
        glVertex2f(-15, -34);
        glVertex2f(-13, -33.5);
        glVertex2f(-13, -32.5);
        glVertex2f(-9, -33.7);
        glVertex2f(-50, -34.5);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(40, -34);
        glVertex2f(65, -34);
        glVertex2f(65, -33);
        glVertex2f(50, -33.5);
        glVertex2f(43, -33);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-75, -37);
        glVertex2f(-50, -37);
        glVertex2f(-52, -36.5);
        glVertex2f(-75, -36.8);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-15, -30);
        glVertex2f(-5, -30);
        glVertex2f(-4, -31);
        glVertex2f(25, -30);
        glVertex2f(25, -29.3);
        glVertex2f(15, -28.8);
        glVertex2f(10, -29.2);
        glVertex2f(-15, -29.5);
    glEnd();










    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-90, -50);
        glVertex2f(-75, -50.5);
        glVertex2f(-65, -50);
        glVertex2f(-65, -49.5);
        glVertex2f(-89, -49);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-90, -40);
        glVertex2f(-60, -40);
        glVertex2f(-60, -39.5);
        glVertex2f(-63, -38.5);
        glVertex2f(-89, -39.7);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(20, -50);
        glVertex2f(-10, -50);
        glVertex2f(-10, -49.5);
        glVertex2f(-13, -48.5);
        glVertex2f(19, -49.7);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-50, -48);
        glVertex2f(-10, -48);
        glVertex2f(-10, -47.5);
        glVertex2f(-13, -46.5);
        glVertex2f(-59, -47.7);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-85, -44);
        glVertex2f(-80, -44.5);
        glVertex2f(-45, -44);
        glVertex2f(-43, -43.5);
        glVertex2f(-43, -42.5);
        glVertex2f(-39, -43.7);
        glVertex2f(-80, -44.5);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(10, -44);
        glVertex2f(35, -44);
        glVertex2f(35, -43);
        glVertex2f(20, -43.5);
        glVertex2f(13, -43);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-105, -47);
        glVertex2f(-80, -47);
        glVertex2f(-82, -46.5);
        glVertex2f(-105, -46.8);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-45, -40);
        glVertex2f(-35, -40);
        glVertex2f(-34, -41);
        glVertex2f(-5, -40);
        glVertex2f(-5, -39.3);
        glVertex2f(-15, -38.8);
        glVertex2f(-20, -39.2);
        glVertex2f(-45, -39.5);
    glEnd();









    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-30, -50);
        glVertex2f(-15, -50.5);
        glVertex2f(-5, -50);
        glVertex2f(-5, -49.5);
        glVertex2f(-29, -49);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-30, -40);
        glVertex2f(-0, -40);
        glVertex2f(-0, -39.5);
        glVertex2f(-3, -38.5);
        glVertex2f(-29, -39.7);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(80, -50);
        glVertex2f(50, -50);
        glVertex2f(50, -49.5);
        glVertex2f(47, -48.5);
        glVertex2f(79, -49.7);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(10, -48);
        glVertex2f(50, -48);
        glVertex2f(50, -47.5);
        glVertex2f(47, -46.5);
        glVertex2f(1, -47.7);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-25, -44);
        glVertex2f(-20, -44.5);
        glVertex2f(15, -44);
        glVertex2f(17, -43.5);
        glVertex2f(17, -42.5);
        glVertex2f(11, -43.7);
        glVertex2f(-20, -44.5);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(70, -44);
        glVertex2f(95, -44);
        glVertex2f(95, -43);
        glVertex2f(80, -43.5);
        glVertex2f(73, -43);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(-45, -47);
        glVertex2f(-20, -47);
        glVertex2f(-22, -46.5);
        glVertex2f(-45, -46.8);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
        glVertex2f(15, -40);
        glVertex2f(25, -40);
        glVertex2f(24, -41);
        glVertex2f(55, -40);
        glVertex2f(55, -39.3);
        glVertex2f(45, -38.8);
        glVertex2f(40, -39.2);
        glVertex2f(15, -39.5);
    glEnd();
}


void boat1(){

glPushMatrix();
glTranslatef(position1,0.0f, 0.0f);

    glBegin(GL_POLYGON);       // main boat
	glColor3ub(158, 128, 61);
        glVertex2f(50, -40);
        glVertex2f(55, -43.5);
        glVertex2f(58, -44);
        glVertex2f(72, -44);
        glVertex2f(75, -43.5);
        glVertex2f(80, -40);
    glEnd();

    glBegin(GL_POLYGON);       // bamboo
	glColor3ub(95, 72, 23);
        glVertex2f(64.5, -40);
        glVertex2f(65.5, -40);
        glVertex2f(65.5, -25);
        glVertex2f(64.5, -25);
    glEnd();


    glBegin(GL_POLYGON);       // pall
	glColor3ub(255, 190, 0);
        glVertex2f(60, -36);
        glVertex2f(70, -36);
        glVertex2f(69, -34);
        glVertex2f(68.7, -32);
        glVertex2f(69, -29);
        glVertex2f(70, -27);
        glVertex2f(60, -27);
        glVertex2f(59, -28);
        glVertex2f(58.3, -32);
        glVertex2f(59, -35);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(168, 241, 255);
        glVertex2f(50, -40);
        glVertex2f(60, -41);
        glVertex2f(70, -41);
        glVertex2f(80, -40);
    glEnd();



    glBegin(GL_POLYGON);       // son
	glColor3ub(189, 142, 37);
        glVertex2f(63, -41);
        glVertex2f(72, -41);
        glVertex2f(71, -39);
        glVertex2f(69, -37.7);
        glVertex2f(60, -38);
    glEnd();

    glBegin(GL_POLYGON);       // first son curve
	glColor3ub(125, 95, 29);
        glVertex2f(57, -41);
        glVertex2f(58, -39);
        glVertex2f(60, -38);
        glVertex2f(62, -39);
        glVertex2f(63, -41);
    glEnd();

glPopMatrix();


}


void boat2(){

glPushMatrix();
glTranslatef(position,-5.0f, 0.0f);

    glBegin(GL_POLYGON);       // main boat
	glColor3ub(158, 128, 61);
        glVertex2f(50, -40);
        glVertex2f(55, -43.5);
        glVertex2f(58, -44);
        glVertex2f(72, -44);
        glVertex2f(75, -43.5);
        glVertex2f(80, -40);
    glEnd();

    glBegin(GL_POLYGON);       // bamboo
	glColor3ub(95, 72, 23);
        glVertex2f(64.5, -40);
        glVertex2f(65.5, -40);
        glVertex2f(65.5, -25);
        glVertex2f(64.5, -25);
    glEnd();


    glBegin(GL_POLYGON);       // pall
	glColor3ub(255, 139, 7);
        glVertex2f(60, -36);
        glVertex2f(70, -36);
        glVertex2f(69, -34);
        glVertex2f(68.7, -32);
        glVertex2f(69, -29);
        glVertex2f(70, -27);
        glVertex2f(60, -27);
        glVertex2f(59, -28);
        glVertex2f(58.3, -32);
        glVertex2f(59, -35);
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(168, 241, 255);
        glVertex2f(50, -40);
        glVertex2f(60, -41);
        glVertex2f(70, -41);
        glVertex2f(80, -40);
    glEnd();



    glBegin(GL_POLYGON);       // son
	glColor3ub(189, 142, 37);
        glVertex2f(63, -41);
        glVertex2f(72, -41);
        glVertex2f(71, -39);
        glVertex2f(69, -37.7);
        glVertex2f(60, -38);
    glEnd();

    glBegin(GL_POLYGON);       // first son curve
	glColor3ub(125, 95, 29);
        glVertex2f(57, -41);
        glVertex2f(58, -39);
        glVertex2f(60, -38);
        glVertex2f(62, -39);
        glVertex2f(63, -41);
    glEnd();

glPopMatrix();



}


void fild(int r, int g, int b){

    glBegin(GL_POLYGON);   // river up fild
	glColor3ub(r, g, b);
        glVertex2f(-110, -35);
        glVertex2f(110, -35);
        glVertex2f(110, -10);
        glVertex2f(-110, -10);
    glEnd();
}


void grass(int x, int y){

    glBegin(GL_POLYGON);   // 1
	glColor3ub(6, 140, 0);
        glVertex2f(x, y);
        glVertex2f(x-.5, y+1.5);
        glVertex2f(x-1.5, y+3);
        glVertex2f(x, y+2);
        glVertex2f(x+1.5, y);
    glEnd();



    glBegin(GL_POLYGON);   // 2
	glColor3ub(6, 140, 0);
        glVertex2f(x+1, y);
        glVertex2f(x, y+3.5);
        glVertex2f(x-1.5, y+6);
        glVertex2f(x+1, y+3);
        glVertex2f(x+2, y);

    glEnd();


    glBegin(GL_POLYGON);   // 3
	glColor3ub(6, 140, 0);
        glVertex2f(x+2, y);
        glVertex2f(x+1, y+4);
        glVertex2f(x, y+7);
        glVertex2f(x+2, y+4);
        glVertex2f(x+2.5, y+2);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(6, 140, 0);
        glVertex2f(x+2.8, y+1);
        glVertex2f(x+3.5, y+4);
        glVertex2f(x+6.5, y+7.5);
        glVertex2f(x+5, y+4);
        glVertex2f(x+4, y);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(6, 140, 0);
        glVertex2f(x+4, y);
        glVertex2f(x+6, y+4);
        glVertex2f(x+8, y+6);
        glVertex2f(x+6.5, y+4);
        glVertex2f(x+6, y+2);
        glVertex2f(x+5.8, y);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(0, 135, 8);
        glVertex2f(x+2.4, y+1.5);
        glVertex2f(x+2.9, y+6);

        glVertex2f(x+3.4, y+8);
        glVertex2f(x+4.28, y+9);
        glVertex2f(x+4.4, y+8.8);
        glVertex2f(x+3.7, y+8);

        glVertex2f(x+3.2, y+6);
        glVertex2f(x+2.8, y+1.6);
    glEnd();



     circle(0.75, x+3.6, y+8, 255, 114, 39 );
     circle(0.75, x+2.7, y+9, 255, 114, 39 );
     circle(0.75, x+3.6, y+9.95, 255, 114, 39 );
     circle(0.75, x+4.95, y+9.65, 255, 114, 39 );
     circle(0.75, x+5, y+8.2, 255, 114, 39 );

     circle(0.75, x+4, y+9, 185, 0, 0 );



}


void car1(int r, int g, int b){


glPushMatrix();
glTranslatef(car1_position_x,car1_position_y, 0.0f);

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(24.2, -14.6);
        glVertex2f(45.5, -13);
        glVertex2f(45.4, -10.2);
        glVertex2f(44.7, -9.5);

        glVertex2f(40.5, -9.5);
        glVertex2f(38, -7.5);
        glVertex2f(31, -8);
        glVertex2f(29.3, -10.3);

        glVertex2f(24.6, -11.2);
        glVertex2f(24, -12);
        glVertex2f(24.2, -14.6);

    glEnd();



    glBegin(GL_POLYGON);   // glass s
	glColor3ub(71, 71, 71);
        glVertex2f(29.9, -10.2);
        glVertex2f(34.7, -9.9);
        glVertex2f(34.5, -8.2);
        glVertex2f(31.2, -8.4);
        glVertex2f(29.9, -10.2);
    glEnd();



    glBegin(GL_POLYGON);   // glass b
	glColor3ub(71, 71, 71);
        glVertex2f(35.1, -9.9);
        glVertex2f(40, -9.5);
        glVertex2f(38, -7.9);
        glVertex2f(34.9, -8.1);
        glVertex2f(35.1, -9.9);
    glEnd();


    circle(1.5, 29, -14.2, 70, 62, 56 );
    circle(1.5, 40.8, -13.4, 70, 62, 56);


glPopMatrix();

}


void car2(int r, int g, int b){


glPushMatrix();
glTranslatef(car2_position_x,car2_position_y, 0.0f);

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(24.2, -6.6);
        glVertex2f(45.5, -6);
        glVertex2f(45.4, -3.2);
        glVertex2f(44.7, -2.5);

        glVertex2f(40.5, -2.5);
        glVertex2f(38, -0.5);
        glVertex2f(31, -1);
        glVertex2f(29.3, -3.3);

        glVertex2f(24.6, -4.2);
        glVertex2f(24, -5);
        glVertex2f(24.2, -7.6);

    glEnd();



    glBegin(GL_POLYGON);   // glass s
	glColor3ub(71, 71, 71);
        glVertex2f(29.9, -3.2);
        glVertex2f(34.7, -2.9);
        glVertex2f(34.5, -1.2);
        glVertex2f(31.2, -1.4);
        glVertex2f(29.9, -3.2);
    glEnd();



    glBegin(GL_POLYGON);   // glass b
	glColor3ub(71, 71, 71);
        glVertex2f(35.1, -2.9);
        glVertex2f(40, -2.5);
        glVertex2f(38, -0.9);
        glVertex2f(34.9, -1.1);
        glVertex2f(35.1, -2.9);
    glEnd();


    circle(1.5, 29, -7.2, 70, 62, 56 );
    circle(1.5, 40.8, -6.4, 70, 62, 56);


glPopMatrix();

}


void sky(int r, int g, int b){

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-110, 90);
        glVertex2f(-110, 50);
        glVertex2f(110, 50);
        glVertex2f(110, 90);
    glEnd();

}


void up_fild(int r, int g, int b){

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-110, 50);
        glVertex2f(-110, 0);
        glVertex2f(110, 0);
        glVertex2f(110, 50);
    glEnd();

}


void house1(int r, int g, int b){


    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-81, 51.5);
        glVertex2f(-69.4, 50.8);
        glVertex2f(-76.1, 60);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(164, 0, 137);
        glVertex2f(-69.4, 50.8);
        glVertex2f(-52.4, 52);
        glVertex2f(-59.6, 60.5);
        glVertex2f(-76.1, 60);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-80, 43);
        glVertex2f(-69.1, 41.8);
        glVertex2f(-69.4, 50.8);
        glVertex2f(-80.1 , 51.4);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-69.1, 41.8);
        glVertex2f(-53.38, 43.64);
        glVertex2f(-53.46, 51.92);
        glVertex2f(-69.4 , 50.8);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(121, 105, 0);
        glVertex2f(-81.1, 41.5);
        glVertex2f(-69.1, 40.43);
        glVertex2f(-69.1, 41.8);
        glVertex2f(-81.1, 43);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(121, 105, 0);
        glVertex2f(-69.1, 40.3);
        glVertex2f(-52, 42.4);
        glVertex2f(-52.1, 43.8);
        glVertex2f(-69.1, 41.8);
    glEnd();


}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(7.5);



    fild(64, 200, 0);
    river(168, 241, 255);
    river_wave(147, 224, 240);
    sky(89, 216, 250);
    up_fild(94, 250, 89);

    road();
    road_mid_line(180,180,180);
    car1(188, 0, 0);
    car2(255, 216, 0);
    lamp_post();
    grass(-106, -66);
    grass(-95, -66);
    grass(-100, -64);
    grass(-111, -70);
    grass(-104, -71);

    grass(-91, -68);


    boat1();

    boat2();
    house1(0, 179, 200);


    glFlush();  // Render now
}



/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);// Set the window's initial width & height         // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test");

    glutDisplayFunc(display);// Register display callback handler for window re-paint
    glutTimerFunc(100, boat_animation_1, 0);
    glutTimerFunc(100, boat_animation_2, 0);
    glutTimerFunc(100, car_animation_1, 0);
    glutTimerFunc(100, car_animation_2, 0);

    gluOrtho2D(-110.0, 110.0, -70.0, 90.0);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
