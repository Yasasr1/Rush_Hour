//#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int FPS = 60;
//to move the road
int roadDivTopMost = 0;
int roadDivLeft1 = 0;
int roadDivLeft3 = 0;
int roadDivLeft5 = 0;
int roadDivRight1 = 0;
int roadDivRight3 = 0;
int roadDivRight5 = 0;
//to move buildings
int l1 = 0;
int l2 = 0;
int l3 = 0;
int r1 = 0;
int r2 = 0;

//to move the tree
int t = 0;
//to steer the car
int steer = 0;
//boost
int boost = 0;
//move oppsite car
float oc1 = 30;
//move oppsite car2
float oc2 = 0;
//move oppsite car3
float oc3 = 0;
//track game status 
int startIndex = 0;
int gameOver = 0;
//track score
int score = 0;

//opposite car1 colors
float red1 = 0.5;
float green1 =0.12;
float blue1 = 0.3;

//opposite car2 colors
float red2 = 0.8;
float green2 =0.12;
float blue2= 0.6;

//opposite car3 colors
float red3 = 0.1;
float green3 =0.12;
float blue3 = 0.9;

const int font=(int)GLUT_BITMAP_9_BY_15;
const int font2=(int)GLUT_BITMAP_HELVETICA_18;
const int font3 =(int)GLUT_BITMAP_TIMES_ROMAN_24;

void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++){
        glutBitmapCharacter(font, *c);
    }
}

void display();
void startGame();
void displayMenu();
void menuKeys(unsigned char key, int x, int y);
void timer(int);
void spe_key(int key, int x, int y);

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,650);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Rush Hour");
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(menuKeys);
    gluOrtho2D(0,100,0,100);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
    return 0;
}

void display(){
    if(startIndex == 1){
        startGame();
    }   
    else{ 
        displayMenu();
    }   	
}

void menuKeys(unsigned char key, int x, int y) {
    switch (key){
        case ' ':
            if(startIndex==0){
                startIndex = 1;
                roadDivTopMost = 0;
                roadDivLeft1 = 0;
                roadDivLeft3 = 0;
                roadDivLeft5 = 0;
                roadDivRight1 = 0;
                roadDivRight3 = 0;
                roadDivRight5 = 0;
                gameOver = 0;
                score = 0;
            }
            break;
		case 27:
            exit(0);
            break;
        default:
            break;
        }
        glutPostRedisplay();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}

void spe_key(int key, int x, int y){
        switch (key){
	        case GLUT_KEY_LEFT:
	            if(steer>0){
	               steer = steer - 2;
	            }
	            break;
	        case GLUT_KEY_RIGHT:
	            if(steer<40){
	               steer = steer + 2; 
	            }
	            break;
            case GLUT_KEY_UP:
                boost = 4;
                break;    
	        default:
	            break;
        }
}

void displayMenu(){
    glClearColor( 0.196078, 0.6, 0.8,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //left
    glColor3f(0.337, 0.659, 0.196);
    glBegin(GL_POLYGON);
    glVertex2f(0,80);
    glVertex2f(50,80);
    glVertex2f(0,0);
    glEnd();

    //right
    glColor3f(0.337, 0.659, 0.196);
    glBegin(GL_POLYGON);
    glVertex2f(100,80);
    glVertex2f(50,80);
    glVertex2f(100,0);
    glEnd();

    //Mountain
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(0,82);
    glVertex2f(14,83);
    glVertex2f(24,85);
    glVertex2f(32,81);
    glVertex2f(36,84);
    glVertex2f(56,82);
    glVertex2f(64,83);
    glVertex2f(72,85);
    glVertex2f(80,81);
    glVertex2f(84,82);
    glVertex2f(88,85);
    glVertex2f(100,83);
    glVertex2f(100,80);
    glVertex2f(0,80); 
    glEnd();

    //R
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(4,84);
    glVertex2f(4,96);
    glVertex2f(5,96);
    glVertex2f(5,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(5,96);
    glVertex2f(12,96);
    glVertex2f(12,95);
    glVertex2f(5,95);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(12,96);
    glVertex2f(12,90);
    glVertex2f(11,90);
    glVertex2f(11,96);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(12,96);
    glVertex2f(12,90);
    glVertex2f(11,90);
    glVertex2f(11,96);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11,91);
    glVertex2f(11,90);
    glVertex2f(5,90);
    glVertex2f(5,91);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(4,91);
    glVertex2f(12,88);
    glVertex2f(12,87);
    glVertex2f(4,90);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(12,88);
    glVertex2f(12,84);
    glVertex2f(11,84);
    glVertex2f(11,88);
    glEnd();

    //U
    glBegin(GL_POLYGON);
    glVertex2f(16,96);
    glVertex2f(17,96);
    glVertex2f(17,84);
    glVertex2f(16,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(17,85);
    glVertex2f(23,85);
    glVertex2f(23,84);
    glVertex2f(17,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(23,96);
    glVertex2f(24,96);
    glVertex2f(24,84);
    glVertex2f(23,84);
    glEnd();

     //S
    glBegin(GL_POLYGON);
    glVertex2f(28,96);
    glVertex2f(36,96);
    glVertex2f(36,95);
    glVertex2f(28,95);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(28,96);
    glVertex2f(29,96);
    glVertex2f(29,90);
    glVertex2f(28,90);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(29,91);
    glVertex2f(29,90);
    glVertex2f(36,90);
    glVertex2f(36,91);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(36,90);
    glVertex2f(36,84);
    glVertex2f(35,84);
    glVertex2f(35,90);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(36,85);
    glVertex2f(36,84);
    glVertex2f(28,84);
    glVertex2f(28,85);
    glEnd();

    //H
    glBegin(GL_POLYGON);
    glVertex2f(40,96);
    glVertex2f(41,96);
    glVertex2f(41,84);
    glVertex2f(40,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(40,91);
    glVertex2f(40,90);
    glVertex2f(48,90);
    glVertex2f(48,91);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(47,96);
    glVertex2f(48,96);
    glVertex2f(48,84);
    glVertex2f(47,84);
    glEnd();

    //H(2)
    glBegin(GL_POLYGON);
    glVertex2f(52,96);
    glVertex2f(53,96);
    glVertex2f(53,84);
    glVertex2f(52,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(52,91);
    glVertex2f(52,90);
    glVertex2f(60,90);
    glVertex2f(60,91);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(59,96);
    glVertex2f(60,96);
    glVertex2f(60,84);
    glVertex2f(59,84);
    glEnd();

    //O
    glBegin(GL_POLYGON);
    glVertex2f(64,96);
    glVertex2f(65,96);
    glVertex2f(65,84);
    glVertex2f(64,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(71,96);
    glVertex2f(72,96);
    glVertex2f(72,84);
    glVertex2f(71,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(64,96);
    glVertex2f(72,96);
    glVertex2f(72,95);
    glVertex2f(64,95);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(64,85);
    glVertex2f(72,85);
    glVertex2f(72,84);
    glVertex2f(64,84);
    glEnd();

    //U(2)
    glBegin(GL_POLYGON);
    glVertex2f(76,96);
    glVertex2f(77,96);
    glVertex2f(77,84);
    glVertex2f(76,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(77,85);
    glVertex2f(83,85);
    glVertex2f(83,84);
    glVertex2f(77,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(83,96);
    glVertex2f(84,96);
    glVertex2f(84,84);
    glVertex2f(83,84);
    glEnd();

    //R(2)
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(88,84);
    glVertex2f(88,96);
    glVertex2f(89,96);
    glVertex2f(89,84);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(89,96);
    glVertex2f(96,96);
    glVertex2f(96,95);
    glVertex2f(89,95);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(96,96);
    glVertex2f(96,90);
    glVertex2f(95,90);
    glVertex2f(95,96);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(96,96);
    glVertex2f(96,90);
    glVertex2f(95,90);
    glVertex2f(95,96);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(95,91);
    glVertex2f(95,90);
    glVertex2f(89,90);
    glVertex2f(89,91);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(88,91);
    glVertex2f(96,88);
    glVertex2f(96,87);
    glVertex2f(88,90);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(96,88);
    glVertex2f(96,84);
    glVertex2f(95,84);
    glVertex2f(95,88);
    glEnd();
 

    //Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(50,80);
    glVertex2f(100,0);
    glVertex2f(0,0);
    glEnd();
    
    //1st
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(37, 8);
    glVertex2f(43, 40);
    glVertex2f(57, 40);
    glVertex2f(63, 8);
    glEnd();
    //2nd
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(45, 46);
    glVertex2f(46, 60);
    glVertex2f(54, 60);
    glVertex2f(55, 46);
    glEnd();
    //3rd
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(47, 64);
    glVertex2f(49, 72);
    glVertex2f(51, 72);
    glVertex2f(53, 64);
    glEnd();
    //4th
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(49.5, 74);
    glVertex2f(50, 80);
    glVertex2f(50, 80);
    glVertex2f(50.5, 74);
    glEnd();
      
    if(gameOver == 1){
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex2f(22,76);
        glVertex2f(78,76);
        glVertex2f(78,64);
        glVertex2f(22,64);
        glEnd();

        glColor3f(0.098, 0.098, 0.439);
        glBegin(GL_POLYGON);
        glVertex2f(23,75);
        glVertex2f(77,75);
        glVertex2f(77,65);
        glVertex2f(23,65);
        glEnd();

        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(38,70,(void *)font3,"Game Over");

        char buffer [50];
        sprintf (buffer, "SCORE: %d", score);
        glColor3f(0.000, 1.000, 1.000);
        renderBitmapString(43,67,(void *)font,buffer);
    }

    glColor3f(0.000,0.000, 0.000);
  
    renderBitmapString(10,50,(void *)font3,"PRESS SPACE TO START");
    renderBitmapString(10,40,(void *)font3,"PRESS LEFT TO GO LEFT");
    renderBitmapString(10,30,(void *)font3,"PRESS RIGHT TO GO RIGHT");
    renderBitmapString(10,20,(void *)font3,"PRESS UP TO BOOST");

    

    glFlush();
	glutSwapBuffers();
}

void startGame(){
	glClearColor(0.337, 0.659, 0.196,1);
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
    glVertex2f(21,100);
    glVertex2f(21,0);
    glEnd();

    //Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(79,0);
    glVertex2f(79,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Road middle left lines
    //1st
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(39,roadDivLeft1+81);
    glVertex2f(39,roadDivLeft1+99);
    glVertex2f(41,roadDivLeft1+99);
    glVertex2f(41,roadDivLeft1+81);
    glEnd();

    roadDivLeft1 = roadDivLeft1 - 1 - boost;
    if(roadDivLeft1<-100){
        roadDivLeft1 =19;
    }
    

    //3rd
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(39,roadDivLeft3+41);
    glVertex2f(39,roadDivLeft3+59);
    glVertex2f(41,roadDivLeft3+59);
    glVertex2f(41,roadDivLeft3+41);
    glEnd();

    roadDivLeft3 = roadDivLeft3 - 1 - boost;
    if(roadDivLeft3<-60){
        roadDivLeft3 =59;
    }

    //5th
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(39,roadDivLeft5+1);
    glVertex2f(39,roadDivLeft5+19);
    glVertex2f(41,roadDivLeft5+19);
    glVertex2f(41,roadDivLeft5+1);
    glEnd();

    roadDivLeft5 = roadDivLeft5 - 1 - boost;
    if(roadDivLeft5<-20){
        roadDivLeft5 =99;
    }

    //Road Middel Right lines
    //1st
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(59,roadDivRight1+81);
    glVertex2f(59,roadDivRight1+99);
    glVertex2f(61,roadDivRight1+99);
    glVertex2f(61,roadDivRight1+81);
    glEnd();
    
    roadDivRight1 = roadDivRight1 - 1 - boost;
    if(roadDivRight1<-100){
        roadDivRight1 =19;
    }

    //3rd
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(59,roadDivRight3+41);
    glVertex2f(59,roadDivRight3+59);
    glVertex2f(61,roadDivRight3+59);
    glVertex2f(61,roadDivRight3+41);
    glEnd();

    roadDivRight3 = roadDivRight3 - 1 - boost;
    if(roadDivRight3<-60){
        roadDivRight3 =59;
    }

    //5th
     glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(59,roadDivRight5+1);
    glVertex2f(59,roadDivRight5+19);
    glVertex2f(61,roadDivRight5+19);
    glVertex2f(61,roadDivRight5+1);
    glEnd();

    roadDivRight5 = roadDivRight5 - 1 - boost;
    if(roadDivRight5<-20){
        roadDivRight5 =99;
    }

 // Tree------------------------------------------------------------------
     t = t - 1 - boost;
    if(t<-20)
        t = 100;

    glPushMatrix();
    glTranslatef(0,t,0);
    
	glColor3f(0, 0.5,0);
    	glBegin(GL_QUADS);                      
	glVertex3f(84.0f, 13.0f, 0.0f);              
    	glVertex3f( 94.0f, 13.0f, 0.0f);             
    	glVertex3f( 94.0f,3.0f, 0.0f);              
    	glVertex3f(84.0f,3.0f, 0.0f);             
    	glEnd(); 


	glColor3f(0, 1, 0);
    	glBegin(GL_POLYGON);
   	glVertex2f(89.0f,16.0f);
    	glVertex2f(91.0f, 10.0f);
    	glVertex2f(97.0f,8.0f);
    	glVertex2f(91.0f,6.0f);
	glVertex2f(89.0f,0.0f);
	glVertex2f(87.0f,6.0f);
	glVertex2f(81.0f,8.0f);
	glVertex2f(87.0f, 10.0f);
    	glEnd();





	glColor3f(1, 0.5,1);
    	glBegin(GL_QUADS);                      
	glVertex3f(87.0f, 10.0f, 0.0f);              
    	glVertex3f( 91.0f, 10.0f, 0.0f);             
    	glVertex3f( 91.0f,6.0f, 0.0f);              
    	glVertex3f(87.0f,6.0f, 0.0f);             
    	glEnd(); 	

    glPopMatrix();


    
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(80,95,(void *)font,buffer);




//Tree ends--------------------------------------------------------------
   

//Buildings--------------------------------------------------
    l1 = l1 - 1 - boost;
    if(l1<-20)
        l1 = 100;

    glPushMatrix();
    glTranslatef(0,l1,0);

	//Building L1
    //l
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(7.5f, 12.0f, 0.0f);              
    glVertex3f( 7.5f, 4.0f, 0.0f);             
    glVertex3f( 1.0f,1.0f, 0.0f);              
    glVertex3f(1.0f,15.0f, 0.0f);   
    glEnd();
     
    //r
	glColor3f(0.7, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(15.0f, 15.0f, 0.0f);              
    glVertex3f( 15.0f, 1.0f, 0.0f);             
    glVertex3f( 7.5f,4.0f, 0.0f);              
    glVertex3f(7.5f,12.0f, 0.0f);             
    glEnd();  
    //u
    glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(1.0f, 15.0f, 0.0f);              
    glVertex3f( 15.0f, 15.0f, 0.0f);             
    glVertex3f( 7.5f,12.0f, 0.0f);                          
    glEnd();                            
    //d
    glColor3f(0.9, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(1.0f, 1.0f, 0.0f);              
    glVertex3f( 15.0f, 1.0f, 0.0f);             
    glVertex3f( 7.5f,4.0f, 0.0f);                         
    glEnd();   
    glPopMatrix(); 
//------------------------------------------------------
	//Building L2

    l2 = l2 - 1 - boost;
    if(l2<-50)
        l2 = 100;

    glPushMatrix();
    glTranslatef(0,l2,0);
    //l
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(7.5f, 52.0f, 0.0f);              
    glVertex3f( 7.5f, 44.0f, 0.0f);             
    glVertex3f( 1.0f,41.0f, 0.0f);              
    glVertex3f(1.0f,55.0f, 0.0f);             
    glEnd();  
    //r
	glColor3f(0.7, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(15.0f, 55.0f, 0.0f);              
    glVertex3f( 15.0f, 41.0f, 0.0f);             
    glVertex3f( 7.5f,44.0f, 0.0f);              
    glVertex3f(7.5f,52.0f, 0.0f);             
    glEnd();  
    //u
    glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(1.0f, 55.0f, 0.0f);              
    glVertex3f( 15.0f, 55.0f, 0.0f);             
    glVertex3f( 7.5f,52.0f, 0.0f);                          
    glEnd();                            
    //d
    glColor3f(0.9, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(1.0f, 41.0f, 0.0f);              
    glVertex3f( 15.0f, 41.0f, 0.0f);             
    glVertex3f( 7.5f,44.0f, 0.0f);                         
    glEnd();
    glPopMatrix(); 
      
//------------------------------------------------------------
 //Building L3

    l3 = l3 - 1 - boost;
    if(l3<-95)
        l3 = 100;

    glPushMatrix();
    glTranslatef(0,l3,0);
    //l
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(7.5f, 92.0f, 0.0f);              
    glVertex3f( 7.5f, 84.0f, 0.0f);             
    glVertex3f( 1.0f,81.0f, 0.0f);              
    glVertex3f(1.0f,95.0f, 0.0f);             
    glEnd();  
    //r
	glColor3f(0.7, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(15.0f, 95.0f, 0.0f);              
    glVertex3f( 15.0f, 81.0f, 0.0f);             
    glVertex3f( 7.5f,84.0f, 0.0f);              
    glVertex3f(7.5f,92.0f, 0.0f);             
    glEnd();  
    //u
    glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(1.0f, 95.0f, 0.0f);              
    glVertex3f( 15.0f, 95.0f, 0.0f);             
    glVertex3f( 7.5f,92.0f, 0.0f);                          
    glEnd();                            
    //d
    glColor3f(0.9, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(1.0f, 81.0f, 0.0f);              
    glVertex3f( 15.0f, 81.0f, 0.0f);             
    glVertex3f( 7.5f,84.0f, 0.0f);                         
    glEnd();
    glPopMatrix();             
//-------------------------------------------------------------------
    //Building R1
    r1 = r1 - 1 - boost;
    if(r1<-35)
        r1 = 100;

    glPushMatrix();
    glTranslatef(0,r1,0);
    //l
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(91.5f, 32.0f, 0.0f);              
    glVertex3f( 91.5f, 24.0f, 0.0f);             
    glVertex3f( 84.0f,21.0f, 0.0f);              
    glVertex3f(84.0f,35.0f, 0.0f);             
    glEnd();  
    //r
	glColor3f(0.7, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(99.0f, 35.0f, 0.0f);              
    glVertex3f( 99.0f, 21.0f, 0.0f);             
    glVertex3f( 91.5f,24.0f, 0.0f);              
    glVertex3f(91.5f,32.0f, 0.0f);             
    glEnd();  
    //u
    glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(84.0f, 35.0f, 0.0f);              
    glVertex3f( 99.0f, 35.0f, 0.0f);             
    glVertex3f( 91.5f,32.0f, 0.0f);                          
    glEnd();                            
    //d
    glColor3f(0.9, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(84.0f, 21.0f, 0.0f);              
    glVertex3f( 99.0f, 21.0f, 0.0f);             
    glVertex3f( 91.5f,24.0f, 0.0f);                         
    glEnd();   
    glPopMatrix();          
	
//-----------------------------------------------------------------------
//Building R2
    r2 = r2 - 1 - boost;
    if(r2<-70)
        r2 = 100;

    glPushMatrix();
    glTranslatef(0,r2,0);
    //l
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(91.5f, 72.0f, 0.0f);              
    glVertex3f( 91.5f, 64.0f, 0.0f);             
    glVertex3f( 84.0f,61.0f, 0.0f);              
    glVertex3f(84.0f,75.0f, 0.0f);             
    glEnd();  
    //r
	glColor3f(0.7, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(99.0f, 75.0f, 0.0f);              
    glVertex3f( 99.0f, 61.0f, 0.0f);             
    glVertex3f( 91.5f,64.0f, 0.0f);              
    glVertex3f(91.5f,72.0f, 0.0f);             
    glEnd();  
    //u
    glColor3f(0.8, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(84.0f, 75.0f, 0.0f);              
    glVertex3f( 99.0f, 75.0f, 0.0f);             
    glVertex3f( 91.5f,72.0f, 0.0f);                          
    glEnd();                            
    //d
    glColor3f(0.9, 0, 0);
	glBegin(GL_TRIANGLES);                      
	glVertex3f(84.0f, 61.0f, 0.0f);              
    glVertex3f( 99.0f, 61.0f, 0.0f);             
    glVertex3f( 91.5f,64.0f, 0.0f);                         
    glEnd();     
    glPopMatrix();        
	
	//Building Ends---------------------------------------------

//CAR-----------------------------------------------------------
    //body
    glPushMatrix();
    glTranslatef(steer,0,0);

    glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);                      
	glVertex3f(24.0f, 14.0f, 0.0f);
	glVertex3f(25.0f, 15.0f, 0.0f);
	glVertex3f(35.0f, 15.0f, 0.0f);              
    glVertex3f(36.0f, 14.0f, 0.0f); 
    glVertex3f(36.0f, 2.0f, 0.0f);
    glVertex3f(35.0f, 1.0f, 0.0f);
     glVertex3f(25.0f, 1.0f, 0.0f);
    glVertex3f( 24.0f,2.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(23.0f, 12.0f, 0.0f);              
    glVertex3f( 24.0f, 12.0f, 0.0f);             
    glVertex3f( 24.0f, 9.0f, 0.0f);              
    glVertex3f(23.0f,9.0f, 0.0f);             
    glEnd();  
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(23.0f, 6.0f, 0.0f);              
    glVertex3f( 24.0f, 6.0f, 0.0f);             
    glVertex3f( 24.0f, 3.0f, 0.0f);              
    glVertex3f(23.0f,3.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(36.0f, 12.0f, 0.0f);              
    glVertex3f( 37.0f, 12.0f, 0.0f);             
    glVertex3f( 37.0f, 9.0f, 0.0f);              
    glVertex3f(36.0f,9.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(36.0f, 6.0f, 0.0f);              
    glVertex3f( 37.0f, 6.0f, 0.0f);             
    glVertex3f( 37.0f, 3.0f, 0.0f);              
    glVertex3f(36.0f,3.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 10.0f, 0.0f);              
    glVertex3f( 34.0f, 10.0f, 0.0f);             
    glVertex3f( 32.0f, 8.5f, 0.0f);              
    glVertex3f(28.0f, 8.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 4.0f, 0.0f);              
    glVertex3f( 34.0f, 4.0f, 0.0f);             
    glVertex3f( 32.0f, 5.5f, 0.0f);              
    glVertex3f(28.0f, 5.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 9.5f, 0.0f);              
    glVertex3f( 26.0f, 4.5f, 0.0f);             
    glVertex3f( 28.0f, 6.0f, 0.0f);              
    glVertex3f(28.0f, 8.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(34.0f, 9.5f, 0.0f);              
    glVertex3f( 34.0f, 4.5f, 0.0f);             
    glVertex3f( 32.0f, 6.0f, 0.0f);              
    glVertex3f(32.0f, 8.0f, 0.0f);             
    glEnd();  
    glPopMatrix();

//CAR1-----------------------------------------------------------
    //body
    oc1 = oc1 - 0.5 - boost;
    if(oc1<-100)
    {
        oc1 = 10;
        score++;
        red1 = rand() / double(RAND_MAX);
        green1 =rand() / double(RAND_MAX);
        blue1 = rand() / double(RAND_MAX);

    }    
    glPushMatrix();
    glTranslatef(0,oc1,0);
    glColor3f(red1,green1,blue1);
	glBegin(GL_POLYGON);                      
	glVertex3f(24.0f, 99.0f, 0.0f);
	glVertex3f(25.0f, 100.0f, 0.0f);
	glVertex3f(35.0f, 100.0f, 0.0f);              
    glVertex3f(36.0f, 99.0f, 0.0f); 
    glVertex3f(36.0f, 87.0f, 0.0f);
    glVertex3f(35.0f, 86.0f, 0.0f);
     glVertex3f(25.0f, 86.0f, 0.0f);
    glVertex3f( 24.0f,87.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(23.0f, 97.0f, 0.0f);              
    glVertex3f( 24.0f, 97.0f, 0.0f);             
    glVertex3f( 24.0f, 94.0f, 0.0f);              
    glVertex3f(23.0f, 94.0f, 0.0f);             
    glEnd();  
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(23.0f, 91.0f, 0.0f);              
    glVertex3f( 24.0f, 91.0f, 0.0f);             
    glVertex3f( 24.0f, 88.0f, 0.0f);              
    glVertex3f(23.0f, 88.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(36.0f, 97.0f, 0.0f);              
    glVertex3f( 37.0f, 97.0f, 0.0f);             
    glVertex3f( 37.0f, 94.0f, 0.0f);              
    glVertex3f(36.0f, 94.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(36.0f, 91.0f, 0.0f);              
    glVertex3f( 37.0f, 91.0f, 0.0f);             
    glVertex3f( 37.0f, 88.0f, 0.0f);              
    glVertex3f(36.0f, 88.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 95.0f, 0.0f);              
    glVertex3f( 34.0f, 95.0f, 0.0f);             
    glVertex3f( 32.0f, 93.5f, 0.0f);              
    glVertex3f(28.0f, 93.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 89.0f, 0.0f);              
    glVertex3f( 34.0f, 89.0f, 0.0f);             
    glVertex3f( 32.0f, 90.5f, 0.0f);              
    glVertex3f(28.0f, 90.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 94.5f, 0.0f);              
    glVertex3f( 26.0f, 89.5f, 0.0f);             
    glVertex3f( 28.0f, 91.0f, 0.0f);              
    glVertex3f(28.0f, 93.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(34.0f, 94.5f, 0.0f);              
    glVertex3f( 34.0f, 89.5f, 0.0f);             
    glVertex3f( 32.0f, 91.0f, 0.0f);              
    glVertex3f(32.0f, 93.0f, 0.0f);             
    glEnd(); 
    glPopMatrix(); 

    //collision detection CAR Vs CAR1
    if(oc1 < -71){
	    if(37+steer > 23 && 23+steer < 37)
	    {
	        startIndex = 0;
	        oc1 = 10;
            gameOver = 1;
	    } 
	}    

//CAR2-----------------------------------------------------------
    //body
    oc2 = oc2 - 0.4 - boost;
    if(oc2<-100)
    {
        oc2=100;
        score++;
        red2 = rand() / double(RAND_MAX);
        green2 =rand() / double(RAND_MAX);
        blue2 = rand() / double(RAND_MAX);
    }
    	
    glPushMatrix();
    glTranslatef(0,oc2,0);
    glColor3f(red2,green2,blue2);
	glBegin(GL_POLYGON);                      
	glVertex3f(44.0f, 99.0f, 0.0f);
	glVertex3f(45.0f, 100.0f, 0.0f);
	glVertex3f(55.0f, 100.0f, 0.0f);              
    glVertex3f(56.0f, 99.0f, 0.0f); 
    glVertex3f(56.0f, 87.0f, 0.0f);
    glVertex3f(55.0f, 86.0f, 0.0f);
     glVertex3f(45.0f, 86.0f, 0.0f);
    glVertex3f( 44.0f,87.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(43.0f, 97.0f, 0.0f);              
    glVertex3f( 44.0f, 97.0f, 0.0f);             
    glVertex3f( 44.0f, 94.0f, 0.0f);              
    glVertex3f(43.0f, 94.0f, 0.0f);             
    glEnd();  
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(43.0f, 91.0f, 0.0f);              
    glVertex3f( 44.0f, 91.0f, 0.0f);             
    glVertex3f( 44.0f, 88.0f, 0.0f);              
    glVertex3f(43.0f, 88.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(56.0f, 97.0f, 0.0f);              
    glVertex3f( 57.0f, 97.0f, 0.0f);             
    glVertex3f( 57.0f, 94.0f, 0.0f);              
    glVertex3f(56.0f, 94.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(56.0f, 91.0f, 0.0f);              
    glVertex3f( 57.0f, 91.0f, 0.0f);             
    glVertex3f( 57.0f, 88.0f, 0.0f);              
    glVertex3f(56.0f, 88.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(46.0f, 95.0f, 0.0f);              
    glVertex3f( 54.0f, 95.0f, 0.0f);             
    glVertex3f( 52.0f, 93.5f, 0.0f);              
    glVertex3f(48.0f, 93.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(46.0f, 89.0f, 0.0f);              
    glVertex3f( 54.0f, 89.0f, 0.0f);             
    glVertex3f( 52.0f, 90.5f, 0.0f);              
    glVertex3f(48.0f, 90.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(46.0f, 94.5f, 0.0f);              
    glVertex3f( 46.0f, 89.5f, 0.0f);             
    glVertex3f( 48.0f, 91.0f, 0.0f);              
    glVertex3f(48.0f, 93.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(54.0f, 94.5f, 0.0f);              
    glVertex3f( 54.0f, 89.5f, 0.0f);             
    glVertex3f( 52.0f, 91.0f, 0.0f);              
    glVertex3f(52.0f, 93.0f, 0.0f);             
    glEnd();
    glPopMatrix();  

    //collision detection CAR Vs CAR2
	if(oc2 < -71){
	    if(37+steer > 43 && 23+steer < 57)
	    {
	        startIndex = 0;
	        oc2 = 15;
            gameOver = 1;
	    } 
	}   

//CAR3-----------------------------------------------------------
    //body
    oc3 = oc3 - 0.2 - boost;
    if(oc3<-100)
    {
        oc3 = 50;
        score++;
        red3 = rand() / double(RAND_MAX);
        green3 =rand() / double(RAND_MAX);
        blue3 = rand() / double(RAND_MAX);
    }   
    glPushMatrix();
    glTranslatef(0,oc3,0);
    glColor3f(red3,green3,blue3);
	glBegin(GL_POLYGON);                      
	glVertex3f(64.0f, 99.0f, 0.0f);
	glVertex3f(65.0f, 100.0f, 0.0f);
	glVertex3f(75.0f, 100.0f, 0.0f);              
    glVertex3f(76.0f, 99.0f, 0.0f); 
    glVertex3f(76.0f, 87.0f, 0.0f);
    glVertex3f(75.0f, 86.0f, 0.0f);
     glVertex3f(65.0f, 86.0f, 0.0f);
    glVertex3f( 64.0f,87.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(63.0f, 97.0f, 0.0f);              
    glVertex3f( 64.0f, 97.0f, 0.0f);             
    glVertex3f( 64.0f, 94.0f, 0.0f);              
    glVertex3f(63.0f, 94.0f, 0.0f);             
    glEnd(); 
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(63.0f, 91.0f, 0.0f);              
    glVertex3f( 64.0f, 91.0f, 0.0f);             
    glVertex3f( 64.0f, 88.0f, 0.0f);              
    glVertex3f(63.0f, 88.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(76.0f, 97.0f, 0.0f);              
    glVertex3f( 77.0f, 97.0f, 0.0f);             
    glVertex3f( 77.0f, 94.0f, 0.0f);              
    glVertex3f(76.0f, 94.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(76.0f, 91.0f, 0.0f);              
    glVertex3f( 77.0f, 91.0f, 0.0f);             
    glVertex3f( 77.0f, 88.0f, 0.0f);              
    glVertex3f(76.0f, 88.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(66.0f, 95.0f, 0.0f);              
    glVertex3f( 74.0f, 95.0f, 0.0f);             
    glVertex3f( 72.0f, 93.5f, 0.0f);              
    glVertex3f(68.0f, 93.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(66.0f, 89.0f, 0.0f);              
    glVertex3f( 74.0f, 89.0f, 0.0f);             
    glVertex3f( 72.0f, 90.5f, 0.0f);              
    glVertex3f(68.0f, 90.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(66.0f, 94.5f, 0.0f);              
    glVertex3f( 66.0f, 89.5f, 0.0f);             
    glVertex3f( 68.0f, 91.0f, 0.0f);              
    glVertex3f(68.0f, 93.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(74.0f, 94.5f, 0.0f);              
    glVertex3f( 74.0f, 89.5f, 0.0f);             
    glVertex3f( 72.0f, 91.0f, 0.0f);              
    glVertex3f(72.0f, 93.0f, 0.0f);             
    glEnd(); 
    glPopMatrix();

    //collision detection CAR Vs CAR3
    if(oc3 < -71){
	    if(37+steer > 63 && 23+steer < 77)
	    {
	        startIndex = 0;
	        oc3 = 20;
            gameOver = 1;
	    } 
	}   

    glFlush();
	glutSwapBuffers();
    boost = 0;

}
