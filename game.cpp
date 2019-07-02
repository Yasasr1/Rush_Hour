#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include <conio.h>
#include <stdlib.h>
#include<string.h>
//#include<glut.h>
#include<iostream>//for strlen
#include<stdlib.h>

int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;

void display();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,650);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Car Game");

    glutDisplayFunc(display);
   // glutSpecialFunc(spe_key);
    //glutKeyboardFunc(processKeys );

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0.184, 0.310, 0.310,1);

   // glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}

void display(){
 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	

	//Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Road Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(23,100);
    glVertex2f(23,0);
    glEnd();

    //Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77,0);
    glVertex2f(77,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Road Middel Border
      //TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,roadDivTop+80);
    glVertex2f(48,roadDivTop+100);
    glVertex2f(52,roadDivTop+100);
    glVertex2f(52,roadDivTop+80);
    glEnd();
    
        //Midle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,roadDivMdl+40);
    glVertex2f(48,roadDivMdl+60);
    glVertex2f(52,roadDivMdl+60);
    glVertex2f(52,roadDivMdl+40);
    glEnd();

    //BOTTOM
     glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,roadDivBtm+0);
    glVertex2f(48,roadDivBtm+20);
    glVertex2f(52,roadDivBtm+20);
    glVertex2f(52,roadDivBtm+0);
    glEnd();



    

    glFlush();
	glutSwapBuffers();

}
