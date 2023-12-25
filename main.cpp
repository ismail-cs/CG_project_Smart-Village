

//#include <windows.h>  // for MS Windows


#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#include<cstdio>
#include <vector>
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



GLfloat cloud1_position_x = 65.0f;
GLfloat cloud_1_speed = 0.6f;

GLfloat cloud2_position_x = 65.0f;
GLfloat cloud_2_speed = 0.8f;

GLfloat sun_position_y = 40.0f;
GLfloat sun_speed = 1.0f;

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



void cloud_animation_1(int value) {

    if(cloud1_position_x <-190.0)
        cloud1_position_x = 70.0f;

    cloud1_position_x -= cloud_1_speed;

	glutPostRedisplay();

	glutTimerFunc(100,cloud_animation_1,0);
}

void cloud_animation_2(int value) {

    if(cloud2_position_x <-190.0)
        cloud2_position_x = 70.0f;

    cloud2_position_x -= cloud_2_speed;

	glutPostRedisplay();

	glutTimerFunc(100,cloud_animation_2,0);
}


void sun_animation(int value) {

    if(sun_position_y > 98.0){
        sun_position_y = 40.0f;
    }


    sun_position_y += sun_speed;

	glutPostRedisplay();

	glutTimerFunc(100,sun_animation,0);
}



void disback(int val)
{
    glutDisplayFunc(display);
}











void circle(float radius, float xc, float yc, float r, float g, float b){
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



void drawTransparentCircle(float x, float y, float radius, float transparency) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(1.0f, 1.0f, 1.0f, transparency); // White color with transparency

    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f); // White color for the outline

    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
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



void lamp_post_2(){

    int x = -103.4, y= -1.9;

    for(int i =0, j=0; i<22; i++, j++){

        glBegin(GL_POLYGON);   // main line
        glColor3ub(59, 81, 0);
            glVertex2f(x, y);
            glVertex2f(x+0.6, y);
            glVertex2f(x+1, y+3.7);
            glVertex2f(x+0.4, y+3.7);
        glEnd();

        circle(0.366, x+2, y+4.4, 130, 120, 0);  // light



        glBegin(GL_POLYGON);   // up line
        glColor3ub(59, 81, 0);
            glVertex2f(x+0.4, y+3.7);
            glVertex2f(x+1, y+3.7);
            glVertex2f(x+2.2, y+4.9);
            glVertex2f(x+1.6, y+4.9);
        glEnd();

        x += 10;
        if(j==5){
            y+=1;
            j=0;
        }

    }
}


// Lamp Post Night Mode ----- Avizit Roy

void lamp_post_night(){

    int x = -105, y= -25;

    for(int i =0, j=0; i<22; i++, j++){

        glBegin(GL_POLYGON);   // main line
        glColor3ub(59, 81, 0);
            glVertex2f(x, y);
            glVertex2f(x+0.6, y);
            glVertex2f(x+0.6, y+6);
            glVertex2f(x, y+6);
        glEnd();

        circle(0.6, x+1.5, y+7.4, 255, 247, 0);  // light

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

void lamp_post_2_night(){

    int x = -103.4, y= -1.9;

    for(int i =0, j=0; i<22; i++, j++){

        glBegin(GL_POLYGON);   // main line
        glColor3ub(59, 81, 0);
            glVertex2f(x, y);
            glVertex2f(x+0.6, y);
            glVertex2f(x+1, y+3.7);
            glVertex2f(x+0.4, y+3.7);
        glEnd();

        circle(0.366, x+2, y+4.4, 255, 247, 0);  // light



        glBegin(GL_POLYGON);   // up line
        glColor3ub(59, 81, 0);
            glVertex2f(x+0.4, y+3.7);
            glVertex2f(x+1, y+3.7);
            glVertex2f(x+2.2, y+4.9);
            glVertex2f(x+1.6, y+4.9);
        glEnd();

        x += 10;
        if(j==5){
            y+=1;
            j=0;
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
        glVertex2f(-81, 41.5);
        glVertex2f(-69.4, 40.8);
        glVertex2f(-76.1, 50);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(164, 0, 137);
        glVertex2f(-69.4, 40.8);
        glVertex2f(-52.4, 42);
        glVertex2f(-59.6, 50.5);
        glVertex2f(-76.1, 50);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-80, 33);
        glVertex2f(-69.1, 31.8);
        glVertex2f(-69.4, 40.8);
        glVertex2f(-80.1 , 41.4);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-69.1, 31.8);
        glVertex2f(-53.38, 33.64);
        glVertex2f(-53.46, 41.92);
        glVertex2f(-69.4 , 40.8);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(121, 105, 0);
        glVertex2f(-81.1, 31.5);
        glVertex2f(-69.1, 30.43);
        glVertex2f(-69.1, 31.8);
        glVertex2f(-81.1, 33);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(121, 105, 0);
        glVertex2f(-69.1, 30.3);
        glVertex2f(-52, 32.4);
        glVertex2f(-52.1, 33.8);
        glVertex2f(-69.1, 31.8);
    glEnd();



    glBegin(GL_POLYGON);   // door
	glColor3ub(212, 122, 0);
        glVertex2f(-64, 32.39);
        glVertex2f(-60, 32.87);
        glVertex2f(-60, 39.5);
        glVertex2f(-64, 39);
    glEnd();


    glBegin(GL_POLYGON);   // door
	glColor3ub(212, 122, 0);
        glVertex2f(-77, 35);
        glVertex2f(-73, 34.5);
        glVertex2f(-73, 38.5);
        glVertex2f(-77, 39);
    glEnd();

}


void house2(int r, int g, int b){

    glBegin(GL_POLYGON);   // main road
	glColor3ub(0, 14, 190);
        glVertex2f(-57, 29.4);
        glVertex2f(-41.3, 30.5);
        glVertex2f(-41.3, 38);
        glVertex2f(-57, 37.09);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(0, 14, 190);
        glVertex2f(-41.3, 30.5);
        glVertex2f(-32.8, 33);
        glVertex2f(-32.8, 39);
        glVertex2f(-38.2, 45.2);
        glVertex2f(-40.3, 38);
        glVertex2f(-41.3, 38);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-58.8, 37);
        glVertex2f(-40.3, 38);
        glVertex2f(-37.8, 47);
        glVertex2f(-54.8, 46);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(0, 8, 104);
        glVertex2f(-38.2, 45.2);
        glVertex2f(-32.8, 39);
        glVertex2f(-31.8, 40);
        glVertex2f(-37.8, 47);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(72, 58, 0);
        glVertex2f(-57.8, 29.4);
        glVertex2f(-57.8, 28);
        glVertex2f(-41.3, 29);
        glVertex2f(-41.3, 30.5);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(72, 58, 0);
        glVertex2f(-41.3, 29);
        glVertex2f(-32, 32);
        glVertex2f(-32, 33.2);
        glVertex2f(-41.3, 30.5);
    glEnd();


    glBegin(GL_POLYGON);   // door
	glColor3ub(141, 0, 163);
        glVertex2f(-51.5070, 29.7528);
        glVertex2f(-48.5013, 30.0199);
        glVertex2f(-48.5, 35);
        glVertex2f(-51.5, 35);
    glEnd();

    glBegin(GL_POLYGON);   // window
	glColor3ub(0, 120, 2);
        glVertex2f(-38.2, 34.4);
        glVertex2f(-36, 34.8);
        glVertex2f(-36, 37);
        glVertex2f(-38.2, 36.6);
    glEnd();






}


void tree1(int r, int g, int b){

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-99, 24);
        glVertex2f(-89, 24);
        glVertex2f(-91, 44);
        glVertex2f(-97, 44);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-91, 44);
        glVertex2f(-90.45, 38.54);
        glVertex2f(-80, 57);
        glVertex2f(-80, 60);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-97, 44);
        glVertex2f(-91, 44);
        glVertex2f(-93, 53);
        glVertex2f(-96, 53);
    glEnd();

    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-97, 44);
        glVertex2f(-96, 53);
        glVertex2f(-99, 64);
        glVertex2f(-101, 64);
    glEnd();


    glBegin(GL_POLYGON);   // main road
	glColor3ub(r, g, b);
        glVertex2f(-91, 44);
        glVertex2f(-87, 64);
        glVertex2f(-89, 64);
        glVertex2f(-93, 53);
    glEnd();

    circle( 6.77, -98, 68, 7, 151, 0);
    circle( 6.77, -106, 72, 7, 151, 0);
    circle( 6.77, -106, 64, 7, 151, 0);
    circle( 6.77, -96, 76, 7, 151, 0);

    circle( 6.77, -72, 60, 7, 151, 0);
    circle( 6.77, -80, 60, 7, 151, 0);
    circle( 6.77, -76, 68, 7, 151, 0);

    circle( 6.77, -88, 68, 7, 151, 0);
    circle( 6.77, -85, 76, 7, 151, 0);

    circle( 6.77, -88, 80, 7, 151, 0);



}


void house_back_side(int r, int g, int b){

    int x = 110;

    for(int i=0; i<21; i++){
        x -= 4;
        glBegin(GL_POLYGON);   // main road
        glColor3ub(r, g, b);
            glVertex2f(-x, 33.5);
            glVertex2f(-(x+1),33.5);
            glVertex2f(-(x+1), 45);
            glVertex2f(-x, 45);
        glEnd();

    }

        glBegin(GL_POLYGON);   // main road
        glColor3ub(182, 140, 0);
            glVertex2f(-109, 35);
            glVertex2f(-25,35);
            glVertex2f(-25, 36);
            glVertex2f(-109, 36);
        glEnd();


        glBegin(GL_POLYGON);   // main road
        glColor3ub(182, 140, 0);
            glVertex2f(-109, 39);
            glVertex2f(-25,39);
            glVertex2f(-25, 40);
            glVertex2f(-109, 40);
        glEnd();


        glBegin(GL_POLYGON);   // main road
        glColor3ub(182, 140, 0);
            glVertex2f(-109, 43);
            glVertex2f(-25,43);
            glVertex2f(-25, 44);
            glVertex2f(-109, 44);
        glEnd();





}




void cloud1 (int r, int g, int b){

glPushMatrix();
glTranslatef(cloud1_position_x,0.0f, 0.0f);

    circle( 4.5, 10, 80, r, g, b);
    circle( 3, 14, 79, r, g, b);
    circle( 3, 6, 79, r, g, b);

glPopMatrix();

}



void cloud2 (int r, int g, int b){

glPushMatrix();
glTranslatef(cloud2_position_x,0.0f, 0.0f);

    circle( 4.5, 30, 75, r, g, b);
    circle( 3, 35, 74, r, g, b);
    circle( 3, 23, 74, r, g, b);
    circle( 3, 25, 76, r, g, b);
    circle( 3, 26, 74, r, g, b);

glPopMatrix();

}


void sun (int r, int g, int b){


//glPushMatrix();
//glTranslatef(0.0f,sun_position_y, 0.0f);

    circle( 6, 30, 75, r, g, b);

//glPopMatrix();

}



//==============================================================================================================================================







// School Road ----- Avizit Roy
void schoolRoad() {
    // Right Road
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2f(75.8229, 1.22324);
    glVertex2f(76, 36);
    glVertex2f(72, 32);
    glVertex2f(71.8025, 1.1318);
    glEnd();

    // Center Road
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2f(76, 36);
    glVertex2f(18, 36);
    glVertex2f(22, 32);
    glVertex2f(72, 32);
    glEnd();

    // Left Road
    glBegin(GL_POLYGON);
    glColor3ub(180, 180, 180);
    glVertex2f(18, 36);
    glVertex2f(18.013168, 0.10939);
    glVertex2f(21.87264, 0.1971);
    glVertex2f(22, 32);
    glEnd();
}


// School Field Box Function ----- Avizit Roy
void schoolFieldBox(float a, float b, float c, float d, float e, float f, float g, float h) {
    glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glVertex2f(g, h);
    glVertex2f(a, b);
    glEnd();
}

// School Field ----- Avizit Roy
void schoolField() {

    // Main Outline
    glColor3ub(134, 255, 51);
    glBegin(GL_QUADS);
    glVertex2f(24.0, 30.0);
    glVertex2f(70.0, 30.0);
    glVertex2f(70.0, 10.0);
    glVertex2f(24.0, 10.0);
    glEnd();

    // Field Outside White Outline
    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(24.0, 30.0);
    glVertex2f(70.0, 30.0);
    glVertex2f(70.0, 30.0);
    glVertex2f(70.0, 10.0);
    glVertex2f(70.0, 10.0);
    glVertex2f(24.0, 10.0);
    glVertex2f(24.0, 10.0);
    glVertex2f(24.0, 30.0);
    glEnd();

    // Left First Box
    schoolFieldBox(24, 22, 26, 22, 26, 18, 24, 18);

    // Left Second Box
    schoolFieldBox(24, 24, 28, 24, 28, 16, 24, 16);

    // Left Second Box Half Moon
    drawTransparentCircle(28.5, 20, 1.5, 0.0);

    // Left Second Box Half Moon Cover
    glBegin(GL_QUADS);
    glColor3ub(134, 255, 51);
    glVertex2f(26.5, 21.5);
    glVertex2f(28, 21.5);
    glVertex2f(28, 18.5);
    glVertex2f(26.5, 18.5);
    glEnd();

    // Mid Line
    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(47, 30);
    glVertex2f(47, 10);
    glEnd();

    // Mid Line Circle
    drawTransparentCircle(47, 20, 1, 0);

    // Right Second Box Half Moon
    drawTransparentCircle(66.6, 20, 1.5, 0);

    // Right Second Box
    schoolFieldBox(66.6, 24, 70, 24, 70, 16, 66.6, 16);

    // Right Second Box Half Moon Cover
    glBegin(GL_QUADS);
    glColor3ub(134, 255, 51);
    glVertex2f(66.6, 21.5);
    glVertex2f(68.2, 21.4);
    glVertex2f(68.2, 18.4);
    glVertex2f(66.6, 18.5);
    glEnd();

    // Right First Box
    schoolFieldBox(68.6, 22, 70, 22, 70, 18, 68.6, 18);
}


// Draw Window for School Building ----- Avizit Roy
void drawWindow(float a, float b, float c, float d, float e, float f, float g, float h) {
    // Window
    glColor3ub(56,100,127);
    glBegin(GL_QUADS);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();

    // Window Outline
    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glVertex2f(g, h);
    glVertex2f(a, b);
    glEnd();
}

// School Building ----- Avizit Roy
void schoolBuilding() {

    // Main Frame
    glBegin(GL_QUADS);
    glColor3ub(255,192,73);
    glVertex2f(25, 62);
    glVertex2f(70, 62);
    glVertex2f(70, 40);
    glVertex2f(25, 40);
    glEnd();

    // Main Frame Top 1
    glBegin(GL_QUADS);
    glColor3ub(193,61,33);
    glVertex2f(24.2, 62.5);
    glVertex2f(24.2, 62);
    glVertex2f(71, 62);
    glVertex2f(71, 62.5);
    glEnd();

    // Main Frame Top 2
    glBegin(GL_QUADS);
    glColor3ub(252,94,58);
    glVertex2f(71, 64);
    glVertex2f(71, 62.5);
    glVertex2f(24.2, 62.5);
    glVertex2f(24.2, 64);
    glEnd();

    // Center Frame
    glBegin(GL_QUADS);
    glColor3ub(254,226,166);
    glVertex2f(40, 65);
    glVertex2f(56, 65);
    glVertex2f(56, 40);
    glVertex2f(40, 40);
    glEnd();

    // Center Frame Top 1
    glBegin(GL_QUADS);
    glColor3ub(193,61,33);
    glVertex2f(39, 65.5);
    glVertex2f(39, 65);
    glVertex2f(57, 65);
    glVertex2f(57, 65.5);
    glEnd();

    // Center Frame Top 2
    glBegin(GL_QUADS);
    glColor3ub(252,94,58);
    glVertex2f(57, 67);
    glVertex2f(57, 65.5);
    glVertex2f(39, 65.5);
    glVertex2f(39, 67);
    glEnd();

    // Entrace

    // Entrance Left Pillar
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(42, 46);
    glVertex2f(42.5, 46);
    glVertex2f(42.5, 40);
    glVertex2f(42, 40);
    glEnd();

    // Entrance Right Pillar
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(53.5, 46);
    glVertex2f(54, 46);
    glVertex2f(54, 40);
    glVertex2f(53.5, 40);
    glEnd();

    // Entrance Top
    glBegin(GL_QUADS);
    glColor3ub(252,94,58);
    glVertex2f(41.5, 47);
    glVertex2f(54.5, 47);
    glVertex2f(54.5, 46);
    glVertex2f(41.5, 46);
    glEnd();

    // Left Door Frame
    glBegin(GL_QUADS);
    glColor3ub(109,53,59);
    glVertex2f(43, 45);
    glVertex2f(47, 45);
    glVertex2f(47, 40);
    glVertex2f(43, 40);
    glEnd();

    // Left Door 1
    glBegin(GL_QUADS);
    glColor3ub(56,100,127);
    glVertex2f(43.2, 44.8);
    glVertex2f(44.7, 44.8);
    glVertex2f(44.7, 40);
    glVertex2f(43.2, 40);
    glEnd();

    // Left Door 2
    glBegin(GL_QUADS);
    glColor3ub(56,100,127);
    glVertex2f(45.3, 44.8);
    glVertex2f(46.7, 44.8);
    glVertex2f(46.7, 40);
    glVertex2f(45.3, 40);
    glEnd();

    // Right Door Frame
    glBegin(GL_QUADS);
    glColor3ub(109,53,59);
    glVertex2f(49, 45);
    glVertex2f(53, 45);
    glVertex2f(53, 40);
    glVertex2f(49, 40);
    glEnd();

    // Right Door 1
    glBegin(GL_QUADS);
    glColor3ub(56,100,127);
    glVertex2f(49.2, 44.8);
    glVertex2f(50.8, 44.8);
    glVertex2f(50.8, 40);
    glVertex2f(49.2, 40);
    glEnd();

    // Right Door 2
    glBegin(GL_QUADS);
    glColor3ub(56,100,127);
    glVertex2f(51.2, 44.8);
    glVertex2f(52.8, 44.8);
    glVertex2f(52.8, 40);
    glVertex2f(51.2, 40);
    glEnd();

    // Left Side Windows
    drawWindow(26, 61, 29, 61, 29, 57, 26, 57);
    drawWindow(31, 61, 34, 61, 34,57,31,57);
    drawWindow(36,61,39,61,39,57,36,57);
    drawWindow(26,53,29,53,29,49,26,49);
    drawWindow(31,53,34,53,34,49,31,49);
    drawWindow(36,53,39,53,39,49,36,49);
    drawWindow(26,45,29,45,29,41,26,41);
    drawWindow(31,45,34,45,34,41,31,41);
    drawWindow(36,45,39,45,39,41,36,41);

    // Center Windows
    drawWindow(41,64,44,64,44,60,41,60);
    drawWindow(46.5,64,49.5,64,49.5,60,46.5,60);
    drawWindow(52,64,55,64,55,60,52,60);
    drawWindow(41,58,44,58,44,54,41,54);
    drawWindow(46.5,58,49.5,58,49.5,54,46.5,54);
    drawWindow(52,58,55,58,55,54,52,54);
    drawWindow(41,52,44,52,44,48,41,48);
    drawWindow(46.5,52,49.5,52,49.5,48,46.5,48);
    drawWindow(52,52,55,52,55,48,52,48);

    // Right Side Windows
    drawWindow(57,61,60,61,60,57,57,57);
    drawWindow(61.5,61,64.5,61,64.5,57,61.5,57);
    drawWindow(66,61,69,61,69,57,66,57);
    drawWindow(57,53,60,53,60,49,57,49);
    drawWindow(61.5,53,64.5,53,64.5,49,61.5,49);
    drawWindow(66,53,69,53,69,49,66,49);
    drawWindow(57,45,60,45,60,41,57,41);
    drawWindow(61.5,45,64.5,45,64.5,41,61.5,41);
    drawWindow(66,45,69,45,69,41,66,41);

    // Base
    glBegin(GL_QUADS);
    glColor3ub(174,84,55);
    glVertex2f(24, 40);
    glVertex2f(24, 39);
    glVertex2f(71, 39);
    glVertex2f(71, 40);
    glEnd();
}


// Flag Pole ----- Avizit Roy
void flagPole() {
    // Base
    glBegin(GL_POLYGON);
    glColor3ub(174,84,55);
    glVertex2f(34.6, 37);
    glVertex2f(35.7, 37);
    glVertex2f(35.7, 36.6);
    glVertex2f(36.2, 36.6);
    glVertex2f(36.2, 36.2);
    glVertex2f(34.1, 36.2);
    glVertex2f(34.1, 36.6);
    glVertex2f(34.6, 36.6);
    glVertex2f(34.6, 37);
    glEnd();

    // Pole
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(35, 37);
    glVertex2f(35.3, 37);
    glVertex2f(35.3, 47.2);
    glVertex2f(35, 47.2);
    glEnd();

    // Flag
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex2f(35.4, 47);
    glVertex2f(38.5, 47);
    glVertex2f(38.5, 45);
    glVertex2f(35.4, 45);
    glEnd();

    circle(0.5, 37, 46, 255, 0, 0);
}


// Windmill ----- Avizit Roy
float angle = 0.0f;

void drawBlade() {
    glBegin(GL_POLYGON);
    glVertex2f(13.0, 64.0);
    glVertex2f(12.0, 70.0);
    glVertex2f(14.0, 70.0);
    glEnd();
}

// Function to draw the windmill ----- Avizit Roy
void drawWindmill() {
    glColor3f(0.5, 0.5, 0.5);

    // Draw the pole of the windmill
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(12.8, 50.2);
    glVertex2f(13.2, 50.2);
    glVertex2f(13.2, 64.0);
    glVertex2f(12.8, 64.0);
    glEnd();

    // Draw three blades of the windmill
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(13.0, 64.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-13.0, -64.0, 0.0);

    for (int i = 0; i < 3; ++i) {
        glPushMatrix();
        glTranslatef(13.0, 64.0, 0.0);
        glRotatef(i * 120.0, 0.0, 0.0, 1.0);
        glTranslatef(-13.0, -64.0, 0.0);
        drawBlade();
        glPopMatrix();
    }

    glPopMatrix();
}


// Timer function to animate the windmill ----- Avizit Roy
void windmill_animation(int value) {
    angle += 2.0f;  // Increment the rotation angle
    glutPostRedisplay();
    glutTimerFunc(16, windmill_animation, 0);  // Set the next timer
}

// Factory Roof Function ----- Avizit Roy
void factoryRoof(float a, float b, float c, float d, float e, float f, float g, float h) {
    glColor3ub(61,40,36);
    glBegin(GL_POLYGON);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

// Factory Main Code ----- Avizit Roy
void factory() {
    // Ground Floor
    glBegin(GL_QUADS);
    glColor3ub(216,125,82);
    glVertex2f(78, 25);
    glVertex2f(78, 10);
    glVertex2f(108, 10);
    glVertex2f(108, 25);
    glEnd();

    // Second Floor
    glBegin(GL_POLYGON);
    glColor3ub(216,125,82);
    glVertex2f(93, 41);
    glVertex2f(93, 25);
    glVertex2f(108, 25);
    glVertex2f(108, 41);
    glVertex2f(100.5, 46);
    glEnd();

    // Factory Chimney
    glBegin(GL_QUADS);
    glColor3ub(164,182,187);
    glVertex2f(80, 50);
    glVertex2f(84, 50);
    glVertex2f(84, 25);
    glVertex2f(80, 25);
    glEnd();

    // Factory Chimney Lines
    glColor3ub(99,105,104);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(79.5, 50);
    glVertex2f(84.5, 50);
    glEnd();

    glColor3ub(99,105,104);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(79.5, 46);
    glVertex2f(84.5, 46);
    glEnd();

    glColor3ub(99,105,104);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(79.5, 42);
    glVertex2f(84.5, 42);
    glEnd();

    glColor3ub(99,105,104);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(79.5, 38);
    glVertex2f(84.5, 38);
    glEnd();

    glColor3ub(99,105,104);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(79.5, 34);
    glVertex2f(84.5, 34);
    glEnd();

    glColor3ub(99,105,104);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(79.5, 30);
    glVertex2f(84.5, 30);
    glEnd();

    // Ground Floor Roof
    factoryRoof(78,27,78,25,83,23,83,25);
    factoryRoof(83,27,83,25,88,23,88,25);
    factoryRoof(88,27,88,25,93,23,93,25);
    factoryRoof(93,27,93,25,98,23,98,25);
    factoryRoof(98,27,98,25,103,23,103,25);
    factoryRoof(103,27,103,25,108,23,108,25);

    // Ground Floor Windows
    drawWindow(82,20,86,20,86,14,82,14);
    drawWindow(88,20,92,20,92,14,88,14);
    drawWindow(94,20,98,20,98,14,94,14);
    drawWindow(100,20,104,20,104,14,100,14);

    // Second Floor Roof
    glBegin(GL_POLYGON);
    glColor3ub(61,40,36);
    glVertex2f(93, 41);
    glVertex2f(100.5, 46);
    glVertex2f(108, 41);
    glVertex2f(108, 41.5);
    glVertex2f(100.5, 46.5);
    glVertex2f(93, 41.5);
    glEnd();

    // Second Floor Window
    glBegin(GL_QUADS);
    glColor3ub(93,73,83);
    glVertex2f(97, 37);
    glVertex2f(97, 30);
    glVertex2f(103, 30);
    glVertex2f(103, 37);
    glEnd();

    circle(3, 100, 37, 93, 73, 83);

    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(100, 39.5);
    glVertex2f(100.0, 30.0);
    glEnd();

    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(97, 32.0);
    glVertex2f(103.0, 32.0);
    glEnd();

    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(97, 35.0);
    glVertex2f(103.0, 35.0);
    glEnd();

    glColor3ub(255, 255, 255);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(97, 37.0);
    glVertex2f(103.0, 37.0);
    glEnd();
}



// Rain Simulation ----- Avizit Roy
struct Raindrop {
    float x, y, speed;

    Raindrop(float x, float y, float speed) : x(x), y(y), speed(speed) {}
};

vector<Raindrop> raindrops; // Vector to store raindrops



void display_rain() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(7.5);

    fild(64, 200, 0);
    river(168, 241, 255);
    river_wave(147, 224, 240);
    sky(61, 96, 112);
    up_fild(94, 250, 89);

    road();
    road_mid_line(180,180,180);
    car1(188, 0, 0);
    lamp_post_night();

    grass(-106, -66);
    grass(-95, -66);
    grass(-100, -64);
    grass(-111, -70);
    grass(-104, -71);

    grass(-91, -68);
    sun(223, 234, 0);
    cloud1(231, 231, 231);
    cloud2(231, 231, 231);

    boat1();

    boat2();

    house_back_side(212, 164, 0);
    house1(0, 179, 200);
    house2(99, 0, 91);
    tree1(121, 105, 0);

    schoolRoad();
    schoolField();
    schoolBuilding();
    flagPole();
    factory();
    drawWindmill();

    lamp_post_2_night();
    car2(255, 216, 0);




    // Draw raindrops
    glColor3f(1.0, 1.0, 1.0); // White color for raindrops
    glPointSize(2.0);

    glBegin(GL_POINTS);
    for (const auto& raindrop : raindrops) {
        glVertex2f(raindrop.x, raindrop.y);
    }
    glEnd();

    // Initialize a few raindrops
    for (int i = 0; i < 10; ++i) {
        float speed = static_cast<float>(rand() % 2 + 1);
        raindrops.push_back(Raindrop(rand() % 220 - 110, rand() % 230 - 70, speed));
    }





    glFlush();  // Render now
}

// Function to update the position of raindrops
void rain_animation(int value) {
    for (auto& raindrop : raindrops) {
        // Update y-coordinate of raindrop
        raindrop.y -= raindrop.speed;

        // Reset raindrop position if it goes out of the screen
        if (raindrop.y < 0) {
            raindrop.y = 600.0; // Reset to the top of the screen
        }
    }

    // Redraw the scene
    glutPostRedisplay();

    // Call update function again after 16 milliseconds (60 FPS)
    glutTimerFunc(30, rain_animation, 0);
}




void display_night() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(7.5);

    fild(64, 200, 0);
    river(168, 241, 255);
    river_wave(147, 224, 240);
    sky(61, 96, 112);
    up_fild(94, 250, 89);

    road();
    road_mid_line(180,180,180);
    car1(188, 0, 0);
    lamp_post_night();

    grass(-106, -66);
    grass(-95, -66);
    grass(-100, -64);
    grass(-111, -70);
    grass(-104, -71);

    grass(-91, -68);
    sun(223, 234, 0);
    cloud1(231, 231, 231);
    cloud2(231, 231, 231);

    boat1();

    boat2();

    house_back_side(212, 164, 0);
    house1(0, 179, 200);
    house2(99, 0, 91);
    tree1(121, 105, 0);

    schoolRoad();
    schoolField();
    schoolBuilding();
    flagPole();
    factory();
    drawWindmill();

    lamp_post_2_night();
    car2(255, 216, 0);


    glFlush();  // Render now
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
    lamp_post();

    grass(-106, -66);
    grass(-95, -66);
    grass(-100, -64);
    grass(-111, -70);
    grass(-104, -71);

    grass(-91, -68);

    cloud1(231, 231, 231);
    cloud2(231, 231, 231);


    boat1();

    boat2();

    house_back_side(212, 164, 0);
    house1(0, 179, 200);
    house2(99, 0, 91);
    tree1(121, 105, 0);
    sun(223, 234, 0);


    // Avizit Roy
    schoolRoad();
    schoolField();
    schoolBuilding();
    flagPole();
    factory();
    drawWindmill();




    lamp_post_2();
    car2(255, 216, 0);






    glFlush();  // Render now
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
        case 'n':
            glutDisplayFunc(display_night);
            break;
        case 'N':
            glutDisplayFunc(display_night);
            break;
        case 'd':
            glutDisplayFunc(display);
            break;
        case 'D':
            glutDisplayFunc(display);
            break;
        case 'r':
            glutDisplayFunc(display_rain);
            break;
        case 'R':
            glutDisplayFunc(display_rain);
            break;
        glutPostRedisplay();
    }

}


// Mouse Event ----- Avizit Roy
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
        glutDisplayFunc(display_night);
	}
    if (button == GLUT_RIGHT_BUTTON) {
        glutDisplayFunc(display_rain);
    }
    glutPostRedisplay();
}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);// Set the window's initial width & height         // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test");

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);// Register display callback handler for window re-paint
    glutTimerFunc(100, boat_animation_1, 0);
    glutTimerFunc(100, boat_animation_2, 0);
    glutTimerFunc(100, car_animation_1, 0);
    glutTimerFunc(100, car_animation_2, 0);
    glutTimerFunc(100, cloud_animation_1, 0);
    glutTimerFunc(100, cloud_animation_2, 0);
    glutTimerFunc(100, sun_animation, 0);

    // Windmill ----- Avizit Roy
    glutTimerFunc(0, windmill_animation, 0);

    // Rain ----- Avizit Roy
    glutTimerFunc(25, rain_animation, 0); // Call update function after 25 milliseconds

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);

    gluOrtho2D(-110.0, 110.0, -70.0, 90.0);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
