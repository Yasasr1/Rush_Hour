#include <stdlib.h>
#include <GL/glut.h>   /* includes the necissarie libaries, etc*/

static GLfloat spin = 0.0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(spin, 0.0, 0.0, 1.0);
   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
		glVertex2f(-25.0, -25.0);
		glVertex2f(-25.0, 25.0);
		glVertex2f(25.0, 25.0);
		glVertex2f(25.0, -25.0);
		glVertex2f(0.0, 40.0);
   glEnd();
   glPopMatrix();
   glutSwapBuffers();
}

void spinDisplay(void)
{
   spin = spin + 0.10;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void spinDisplay2(void)
{
   spin = spin - 0.10;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void tasten (unsigned char key, int xmouse, int ymouse)
{	
	switch (key){
		case 'w':
			glClearColor (1.0, 0.0, 0.0, 0.0);
			break;

		case 'r': 
			glClearColor (0.0, 1.0, 0.0, 0.0);
		break;

		default:
         break;
	}
}

void motionleft (int mousex,int mousey)
{
	
	static int lx, ly;
		//if (!lx) lx=mousex;			//worng : only choosen first time 
		if (!ly) ly=mousey;
		int dy;
		//dy=ly-mousey;        //wrong: only measures movments 
		spin=spin+dy*0.1;

}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
	  case GLUT_LEFT_BUTTON:
		  if(state == GLUT_DOWN);
			glutIdleFunc(spinDisplay);
		 if (state == GLUT_DOWN)
			 glutMotionFunc(motionleft);
		 if (state == GLUT_UP)
			 glutIdleFunc(NULL);
		 if (state == GLUT_UP)
			 glutMotionFunc(NULL);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay2);
		 if (state == GLUT_UP)
			 glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}


		
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Julia Gaa - Assignment 2");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutKeyboardFunc(tasten);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}





