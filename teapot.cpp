#include <GL/gl.h>
#include <GL/glut.h>

//void handleResize(int w, int h)
//{
//    //Tell OpenGL how to convert from coordinates to pixel values
//    glViewport(0, 0, w, h);

//    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
//    glLoadIdentity(); //Reset the camera

//    //Set the camera perspective
//    gluPerspective(45.0,                  //The camera angle
//                   (double)w / (double)h, //The width-to-height ratio
//                   1.0,                   //The near z clipping coordinate
//                   200.0);                //The far z clipping coordinate
//}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: //Escape key
        exit(0);
    }
}

//Initializes 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

float angle = 30.0f;
float cameraAngle = 40.0f;

void display () {

    /* clear window */
//    glClearColor(0.2,0.44,0.16,1);   // RGBA
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
//    glLoadIdentity(); //Reset the drawing perspective

//    glRotatef(-cameraAngle, 0.0f, 0.0f, 1.0f); //Rotate the camera about Y-axis
//    glTranslatef(0.0f, 0.0f, 0.3f); //Move forward 5 units in Z direction

//    glPushMatrix(); //Save the transformations performed thus far


    /* draw scene */
    glutSolidTeapot(0.1);
//    glutWireTeapot(0.7);

    /* flush drawing routines to the window */
    glFlush();
//        glutSwapBuffers();


}

int main ( int argc, char * argv[] )
{

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(1000,400);
    glutInitWindowSize(700,700);


    /* create and set up a window */
    glutCreateWindow("Teapot!");
    initRendering();


    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    //    glutReshapeFunc(handleResize);

    /* tell GLUT to wait for events */
    glutMainLoop();

    return 0;
}
