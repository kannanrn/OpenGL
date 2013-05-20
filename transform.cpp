#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>

using namespace std;


//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
                    int x, int y)     //The current mouse coordinates
{
    switch (key)
    {
    case 27: //Escape key
        exit(0); //Exit the program
    }
}

//Initializes 3D rendering
void initRendering()
{
    //Makes 3D drawing work when something is in front of something else
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    glLoadIdentity(); //Reset the camera

    //Set the camera perspective
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}


float angle = 30.0f;
float cameraAngle = 0.0f;

//Draws the 3D scene
void drawScene()
{
    //Background color
    glClearColor(0.2,0.44,0.16,1);   // RGBA
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

    glRotatef(-cameraAngle, 0.0f, 1.0f, 0.0f); //Rotate the camera about Y-axis
    glTranslatef(0.0f, 0.0f, -5.0f); //Move forward 5 units in Z direction
	
	glPushMatrix(); //Save the transformations performed thus far

    // *ALWAYS* move to the center of a shape before rotating it about an axis
	glTranslatef(0.0f, -1.0f, 0.0f); //Move to the center of the trapezoid
    glRotatef(angle, 0.0f, 0.0f, 1.0f); //Rotate about the z-axis
	
	glBegin(GL_QUADS);
	
    //Trapezoid (rotating about Z-axis)
	glVertex3f(-0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.4f, 0.5f, 0.0f);
	glVertex3f(-0.4f, 0.5f, 0.0f);
	
	glEnd();
	
	glPopMatrix(); //Undo the move to the center of the trapezoid
	glPushMatrix(); //Save the current state of transformations

	glTranslatef(1.0f, 1.0f, 0.0f); //Move to the center of the pentagon
    glRotatef(angle, 0.0f, 1.0f, 0.0f); //Rotate about the y-axis
	glScalef(0.7f, 0.7f, 0.7f); //Scale by 0.7 in the x, y, and z directions
	
	glBegin(GL_TRIANGLES);
	
    //Pentagon (rotating about Y-axis)
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	
	glEnd();
	
	glPopMatrix(); //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.0f, 1.0f, 0.0f); //Move to the center of the triangle
    glRotatef(angle, 1.0f, 1.0f, 0.0f); //Rotate about the the vector (1, 1, 0)
	
	glBegin(GL_TRIANGLES);
	
    //Triangle (rotating about x+y=1)
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	
	glEnd();
	
	glPopMatrix(); //Undo the move to the center of the triangle
	
	glutSwapBuffers();
}

// Continuously rotate the shapes
void update(int value)
{
    angle += 2.0f;
    if (angle > 360) // to handle floating pt precision, reset angle to 0
    {
        angle -= 360;
	}
	
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(1000,250);
	glutInitWindowSize(400, 400);
	
	//Create the window
    glutCreateWindow("Transformations and Timers");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //Add a timer
	
	glutMainLoop();
	return 0;
}









