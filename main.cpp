#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);
void display(void);
void drawCircle(float r, int num_lines, bool full, int x, int y);
void drawCrux();
void drawQuads();
void drawTriangles();

void drawCircle(float r, int num_lines, bool full, int x, int y){
    int i;
    GLfloat angle;
    glColor3f(0.0, 1.0, 0.0);
   
    angle = 2 * M_PI / num_lines;
 
    if(full)
        glBegin(GL_TRIANGLE_FAN);         
    else glBegin(GL_LINE_LOOP);
    
    for(i = 1; i <= num_lines; i++)
    {
		glVertex2f((r*(cos(i * angle))+x) , (r*(sin(i * angle))+y));  
	}
    glEnd();
	glFlush(); 
}

void drawCrux(){
	
	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		
		glVertex2f(0, 200);
		glVertex2f(0, 256);
		
		glVertex2f(-25, 240);
		glVertex2f(25, 240);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		
		glVertex2f(-150, 100);
		glVertex2f(-150, 156);
		
		glVertex2f(-175, 140);
		glVertex2f(-125, 140);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		
		glVertex2f(150, 100);
		glVertex2f(150, 156);
		
		glVertex2f(175, 140);
		glVertex2f(125, 140);
	glEnd();
	
    glFlush();
}

void drawQuads(){
	
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		
		glVertex2f(-100, 0);
		glVertex2f(-100, -200);
		glVertex2f(100, -200);
		glVertex2f(100, 0);
 	 glEnd();
 	 
	glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 1.0);
		
		glVertex2f(-200, 0);
		glVertex2f(-200, -200);
		glVertex2f(-100, -200);
		glVertex2f(-100, 0);
    	
		glVertex2f(100, 0);
		glVertex2f(100, -200);
		glVertex2f(200, -200);
		glVertex2f(200, 0);
 	 glEnd();
    	
 	glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		
		glVertex2f(-50, -75);
		glVertex2f(-50, -200);
		glVertex2f(50, -200);
		glVertex2f(50, -75);	
    glEnd();
    
    glFlush();
}

void drawTriangles(){
  glColor3f(1.0, 0.0, 0.0);
  
	glBegin(GL_TRIANGLES);
		glVertex2f(0, 200);
		glVertex2f(-100, 0);
		glVertex2f(100, 0);

		glVertex2f(-150, 100);
		glVertex2f(-200, 0);
		glVertex2f(-100, 0);

		glVertex2f(150, 100);
		glVertex2f(200, 0);
		glVertex2f(100, 0);
    glEnd();
    
    glFlush();
}

void reshape(int width, int height){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	
	glOrtho (-(width/2), (width/2),-(height/2),(height/2), -1 ,1);
	glMatrixMode(GL_MODELVIEW);
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
		case 27:
			exit(1);
			
//    	case GLUT_KEY_RIGHT:
   
 	 break;
    }
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	
	drawTriangles();
	drawQuads();
	drawCrux();
	drawCircle(40, 30, true, -150, -60);
	drawCircle(40, 30, true, 150, -60);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 512);
	glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-640)/2,
                       	   (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
	glutCreateWindow("First window");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

    return 0;
}