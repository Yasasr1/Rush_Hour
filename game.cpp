 #include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int FPS = 60;
//to move the road
int roadDivTopMost = 0;
int roadDivLeft1 = 0;
//int roadDivLeft2 = 0;
int roadDivLeft3 = 0;
//int roadDivLeft4 = 0;
int roadDivLeft5 = 0;
int roadDivRight1 = 0;
//int roadDivRight2 = 0;
int roadDivRight3 = 0;
//int roadDivRight4 = 0;
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
    glutCreateWindow("Car Game");
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(menuKeys );
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
                //roadDivLeft2 = 0;
                roadDivLeft3 = 0;
                //roadDivLeft4 = 0;
                roadDivLeft5 = 0;
                roadDivRight1 = 0;
                //roadDivRight2 = 0;
                roadDivRight3 = 0;
                //roadDivRight4 = 0;
                roadDivRight5 = 0;
                gameOver = 0;
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
                boost = 5;
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

    //left
    glColor3f(0.337, 0.659, 0.196);
    glBegin(GL_POLYGON);
    glVertex2f(100,80);
    glVertex2f(50,80);
    glVertex2f(100,0);
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

	/*
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
    glVertex2f(100,80);
    glVertex2f(100,83);
    glVertex2f(0,80);  
    glEnd();
    */

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

    if(gameOver == 1)
    {
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(20,90,(void *)font2,"Game Over");

        char buffer [50];
        sprintf (buffer, "SCORE: %d", score);
        glColor3f(0.000, 1.000, 1.000);
        renderBitmapString(20,80,(void *)font,buffer);


    }

    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(42,90,(void *)font,"RUSH HOUR");
    renderBitmapString(20,50,(void *)font,"PRESS SPACE TO START");
    renderBitmapString(20,40,(void *)font,"PRESS LEFT TO GO LEFT");
    renderBitmapString(20,30,(void *)font,"PRESS RIGHT TO GO RIGHT");
    renderBitmapString(20,20,(void *)font,"PRESS UP TO BOOST");

    

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
    if(roadDivLeft1<-101){
        roadDivLeft1 =20;
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
    if(roadDivLeft3<-61){
        roadDivLeft3 =60;
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
    if(roadDivLeft5<-21){
        roadDivLeft5 =100;
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
    if(roadDivRight1<-101){
        roadDivRight1 =20;
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
    if(roadDivRight3<-61){
        roadDivRight3 =60;
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
    if(roadDivRight5<-21){
        roadDivRight5 =100;
    }

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

//CAR2-----------------------------------------------------------
    //body
    oc1 = oc1 - 0.5 - boost;
    if(oc1<-100)
    {
        oc1 = 10;
        score++;
    }    
    glPushMatrix();
    glTranslatef(0,oc1,0);
    glColor3f(0, 1, 1);
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

    //collision detection CAR Vs CAR2
    if(oc1 < -71){
	    if(37+steer > 23 && 23+steer < 37)
	    {
	        startIndex = 0;
	        oc1 = 10;
            gameOver = 1;
	    } 
	}    

//CAR3-----------------------------------------------------------
    //body
    oc2 = oc2 - 0.4 - boost;
    if(oc2<-100)
    {
        oc2=100;
        score++;
    }
    	
    glPushMatrix();
    glTranslatef(0,oc2,0);
    glColor3f(0, 1, 1);
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

    //collision detection CAR Vs CAR3
	if(oc2 < -71){
	    if(37+steer > 43 && 23+steer < 57)
	    {
	        startIndex = 0;
	        oc2 = 15;
            gameOver = 1;
	    } 
	}   

//CAR4-----------------------------------------------------------
    //body
    oc3 = oc3 - 0.2 - boost;
    if(oc3<-100)
    {
        oc3 = 50;
        score++;
    }   
    glPushMatrix();
    glTranslatef(0,oc3,0);
    glColor3f(0, 1, 1);
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

    //collision detection CAR Vs CAR4
    if(oc3 < -71){
	    if(37+steer > 63 && 23+steer < 77)
	    {
	        startIndex = 0;
	        oc3 = 20;
            gameOver = 1;
	    } 
	}   

    /*
    //CAR2(INCOMING)-----------------------------------------------------------
    //body
    glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);                      
	glVertex3f(24.0f, 100.0f, 0.0f);
	glVertex3f(25.0f, 86.0f, 0.0f);
	glVertex3f(35.0f, 86.0f, 0.0f);              
    glVertex3f(36.0f, 87.0f, 0.0f); 
    glVertex3f(36.0f, 99.0f, 0.0f);
    glVertex3f(35.0f, 100.0f, 0.0f);
     glVertex3f(25.0f, 100.0f, 0.0f);
    glVertex3f( 24.0f,99.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(23.0f, 89.0f, 0.0f);              
    glVertex3f( 24.0f, 89.0f, 0.0f);             
    glVertex3f( 24.0f, 92.0f, 0.0f);              
    glVertex3f(23.0f, 92.0f, 0.0f);             
    glEnd();  
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(23.0f, 95.0f, 0.0f);              
    glVertex3f( 24.0f, 95.0f, 0.0f);             
    glVertex3f( 24.0f, 98.0f, 0.0f);              
    glVertex3f(23.0f, 98.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(36.0f, 89.0f, 0.0f);              
    glVertex3f( 37.0f, 89.0f, 0.0f);             
    glVertex3f( 37.0f, 92.0f, 0.0f);              
    glVertex3f(36.0f, 92.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(36.0f, 95.0f, 0.0f);              
    glVertex3f( 37.0f, 95.0f, 0.0f);             
    glVertex3f( 37.0f, 98.0f, 0.0f);              
    glVertex3f(36.0f, 98.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 91.0f, 0.0f);              
    glVertex3f( 34.0f, 91.0f, 0.0f);             
    glVertex3f( 32.0f, 92.5f, 0.0f);              
    glVertex3f(28.0f, 92.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 97.0f, 0.0f);              
    glVertex3f( 34.0f, 97.0f, 0.0f);             
    glVertex3f( 32.0f, 95.5f, 0.0f);              
    glVertex3f(28.0f, 95.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(26.0f, 91.5f, 0.0f);              
    glVertex3f( 26.0f, 96.5f, 0.0f);             
    glVertex3f( 28.0f, 95.0f, 0.0f);              
    glVertex3f(28.0f, 93.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(34.0f, 91.5f, 0.0f);              
    glVertex3f( 34.0f, 96.5f, 0.0f);             
    glVertex3f( 32.0f, 95.0f, 0.0f);              
    glVertex3f(32.0f, 93.0f, 0.0f);             
    glEnd();  
    */
    /*
    //CAR3(INCOMING)-----------------------------------------------------------
    //body
    glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);                      
	glVertex3f(44.0f, 87.0f, 0.0f);
	glVertex3f(45.0f, 86.0f, 0.0f);
	glVertex3f(55.0f, 86.0f, 0.0f);              
    glVertex3f(56.0f, 87.0f, 0.0f); 
    glVertex3f(56.0f, 99.0f, 0.0f);
    glVertex3f(55.0f, 100.0f, 0.0f);
     glVertex3f(45.0f, 100.0f, 0.0f);
    glVertex3f( 44.0f,99.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(43.0f, 89.0f, 0.0f);              
    glVertex3f( 44.0f, 89.0f, 0.0f);             
    glVertex3f( 44.0f, 92.0f, 0.0f);              
    glVertex3f(43.0f, 92.0f, 0.0f);             
    glEnd();  
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(43.0f, 95.0f, 0.0f);              
    glVertex3f( 44.0f, 95.0f, 0.0f);             
    glVertex3f( 44.0f, 98.0f, 0.0f);              
    glVertex3f(43.0f, 98.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(56.0f, 89.0f, 0.0f);              
    glVertex3f( 57.0f, 89.0f, 0.0f);             
    glVertex3f( 57.0f, 92.0f, 0.0f);              
    glVertex3f(56.0f, 92.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(56.0f, 95.0f, 0.0f);              
    glVertex3f( 57.0f, 95.0f, 0.0f);             
    glVertex3f( 57.0f, 98.0f, 0.0f);              
    glVertex3f(56.0f, 98.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(46.0f, 91.0f, 0.0f);              
    glVertex3f( 54.0f, 91.0f, 0.0f);             
    glVertex3f( 52.0f, 92.5f, 0.0f);              
    glVertex3f(48.0f, 92.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(46.0f, 97.0f, 0.0f);              
    glVertex3f( 54.0f, 97.0f, 0.0f);             
    glVertex3f( 52.0f, 95.5f, 0.0f);              
    glVertex3f(48.0f, 95.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(46.0f, 91.5f, 0.0f);              
    glVertex3f( 46.0f, 96.5f, 0.0f);             
    glVertex3f( 48.0f, 95.0f, 0.0f);              
    glVertex3f(48.0f, 93.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(54.0f, 91.5f, 0.0f);              
    glVertex3f( 54.0f, 96.5f, 0.0f);             
    glVertex3f( 52.0f, 95.0f, 0.0f);              
    glVertex3f(52.0f, 93.0f, 0.0f);             
    glEnd(); 
    */ 
	/*
	//CAR4(INCOMING)-----------------------------------------------------------
    //body
    glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);                      
	glVertex3f(64.0f, 87.0f, 0.0f);
	glVertex3f(65.0f, 86.0f, 0.0f);
	glVertex3f(75.0f, 86.0f, 0.0f);              
    glVertex3f(76.0f, 87.0f, 0.0f); 
    glVertex3f(76.0f, 99.0f, 0.0f);
    glVertex3f(75.0f, 100.0f, 0.0f);
     glVertex3f(65.0f, 100.0f, 0.0f);
    glVertex3f( 64.0f,99.0f, 0.0f);                       
    glEnd();      
    //tireLEFTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(63.0f, 89.0f, 0.0f);              
    glVertex3f( 64.0f, 89.0f, 0.0f);             
    glVertex3f( 64.0f, 92.0f, 0.0f);              
    glVertex3f(63.0f, 92.0f, 0.0f);             
    glEnd(); 
    //tireLEFTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(63.0f, 95.0f, 0.0f);              
    glVertex3f( 64.0f, 95.0f, 0.0f);             
    glVertex3f( 64.0f, 98.0f, 0.0f);              
    glVertex3f(63.0f, 98.0f, 0.0f);             
    glEnd();  
    //tireRIGHTUP
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(76.0f, 89.0f, 0.0f);              
    glVertex3f( 77.0f, 89.0f, 0.0f);             
    glVertex3f( 77.0f, 92.0f, 0.0f);              
    glVertex3f(76.0f, 92.0f, 0.0f);             
    glEnd();  
    //tireRIGHTDOWN
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(76.0f, 95.0f, 0.0f);              
    glVertex3f( 77.0f, 95.0f, 0.0f);             
    glVertex3f( 77.0f, 98.0f, 0.0f);              
    glVertex3f(76.0f, 98.0f, 0.0f);             
    glEnd();  
    //frontWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(66.0f, 91.0f, 0.0f);              
    glVertex3f( 74.0f, 91.0f, 0.0f);             
    glVertex3f( 72.0f, 92.5f, 0.0f);              
    glVertex3f(68.0f, 92.5f, 0.0f);             
    glEnd();  
    //backWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(66.0f, 97.0f, 0.0f);              
    glVertex3f( 74.0f, 97.0f, 0.0f);             
    glVertex3f( 72.0f, 95.5f, 0.0f);              
    glVertex3f(68.0f, 95.5f, 0.0f);             
    glEnd();  
    //leftWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(66.0f, 91.5f, 0.0f);              
    glVertex3f( 66.0f, 96.5f, 0.0f);             
    glVertex3f( 68.0f, 95.0f, 0.0f);              
    glVertex3f(68.0f, 93.0f, 0.0f);             
    glEnd();  
    //rightWINDOW
    glColor3f(0, 0, 0);
	glBegin(GL_QUADS);                      
	glVertex3f(74.0f, 91.5f, 0.0f);              
    glVertex3f( 74.0f, 96.5f, 0.0f);             
    glVertex3f( 72.0f, 95.0f, 0.0f);              
    glVertex3f(72.0f, 93.0f, 0.0f);             
    glEnd();  
    */

    glFlush();
	glutSwapBuffers();
    boost = 0;

}
