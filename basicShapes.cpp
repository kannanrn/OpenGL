#include <iostream>
#include <stdlib.h> //Needed for "exit" function

#include <GL/gl.h>
#include <GL/glu.h>
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

//Draws the 3D scene
void drawScene()
{
    //Background color
    glClearColor(0.62,0.44,0.66,1);   // RGBA

    //Clear information from last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the Model View
    glLoadIdentity(); //Reset the view

    glBegin(GL_QUADS); //Begin quadrilateral coordinates

    //Trapezoid
    glVertex3f(-0.7f, -1.5f, -5.0f);
    glVertex3f(0.7f, -1.5f, -5.0f);
    glVertex3f(0.4f, -0.5f, -5.0f);
    glVertex3f(-0.4f, -0.5f, -5.0f);

    glEnd(); //End quadrilateral coordinates

    glBegin(GL_TRIANGLES); //Begin triangle coordinates

    //Pentagon (made up of 3 triangles)
    glVertex3f(0.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 0.5f, -5.0f);
    glVertex3f(0.5f, 1.0f, -5.0f);

    glVertex3f(0.5f, 1.0f, -5.0f);
    glVertex3f(1.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 1.0f, -5.0f);

    glVertex3f(0.5f, 1.0f, -5.0f);
    glVertex3f(1.5f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.5f, -5.0f);

    //Triangle
    glVertex3f(-0.5f, 0.5f, -5.0f);
    glVertex3f(-1.0f, 1.5f, -5.0f);
    glVertex3f(-1.5f, 0.5f, -5.0f);

    glEnd(); //End triangle coordinates

    // Swaps the frame and display buffers
    glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(1000,250);
    glutInitWindowSize(400, 400); //Set the window size

    //Create the window
    glutCreateWindow("Basic Shapes");
    initRendering(); //Initialize 3D rendering

    //Set handler functions for drawing, keypresses, and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);

    glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
    return 0; //This line is never reached
}









