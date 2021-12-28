#include <windows.h>
#include <GL/glut.h>

    //Initializes 3D rendering
    void initRendering() {
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_LIGHTING); //Enable lighting
     glEnable(GL_LIGHT0); //Enable light #0
     glEnable(GL_LIGHT1); //Enable light #1
     glEnable(GL_NORMALIZE); //Automatically normalize normals
     glShadeModel(GL_SMOOTH); //Enable smooth shading
    }

    //Called when the window is resized
    void handleResize(int w, int h) {
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    }

    float _angle = -70.0f;
    int main(int argc, char** argv) {
     //Initialize GLUT
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(600, 600);

     //Create the window
     glutCreateWindow("Lighting");
     initRendering();

     //Set handler functions
     glutDisplayFunc(drawScene);

     glutReshapeFunc(handleResize);

     update(0);

     glutMainLoop();
     return 0;
    }
