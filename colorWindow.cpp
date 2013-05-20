#include <GL/glut.h>

//Drawing funciton
void draw(void)
{
    //Background color
    glClearColor(0.62,0.44,0.66,1);   // RGBA
    glClear(GL_COLOR_BUFFER_BIT );
    //Draw order
    glFlush();
}

//Main program
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowPosition(50,250);
    glutInitWindowSize(500,250);
    glutCreateWindow("Green window");

    //Call to the drawing function
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

















