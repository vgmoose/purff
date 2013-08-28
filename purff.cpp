#include <GLUT/glut.h>

void initialize()
{
    float ambientLight[] = { 0.2, 0.2, 0.2, 1.0 };
    float specularLight[] = { 1.0, 1.0, 1.0, 1.0 };
    float specularity[] = { 1.0, 1.0, 1.0, 1.0 };
    float shininess[] = { 60.0 };
    float lightPosition[] = { 0.0, 50.0, 50.0, 1.0 };
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    
    // Enable lighting with one light source
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glEnable(GL_DEPTH_TEST);
    
    // Objects have their color affected by the lighting
    glShadeModel(GL_SMOOTH);
    
    // Properties of the objects' materials
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);   // Reflectance
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);    // Shininess
    
    // Enable ambient light usage
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    
    // Position of the light source
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
}

void resize(int width, int height)
{
    // Avoid division by 0 (zero)
    if (height == 0)
        height = 1;
    
    // Set the viewport to be the entire window
    glViewport(0, 0, width, height);
    
    // Calculate the aspect ratio of the window
    float aspectRatio = (float) width / (float) height;
    
    // Use the projection matrix
    glMatrixMode(GL_PROJECTION);
    
    // Defines the perspective projection
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 1, 500);
    
    // Use the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    
    // Defines the position of the camera and the target
    glLoadIdentity();
    gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);

}

void paint()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(6.7, -3.0, -12.0);

  //  glRotatef(15.0, 1.0, 0.0, 0.0);
    glRotatef(85, 0.0, 100.0, 0.0);
    glRotatef(20, 0.0, 0.0, 1.0);

  //  glRotatef(15, 0.0, 0.0, 1.0);
   
    glEnable(GL_POLYGON_SMOOTH);
    
    glTranslatef(3.0, 0, 0);

    glutWireSphere(.5,100,100);
    
    glTranslatef(-2.0, 0, 0);
    glutWireSphere(.5,100,100);
    glTranslatef(2.0, 0, 0);

    
    for (int x=0; x<7;x++)
    {
        glTranslatef(0.0, 0.0, -2.0);
        glutWireSphere(.5,100,100);
        
        glTranslatef(-2.0, 0, 0);
        glutWireSphere(.5,100,100);
        glTranslatef(2.0, 0, 0);

    }


    glTranslatef(8.0, 0, 0);
    
    glutWireSphere(.5,100,100);
    
    glTranslatef(2.0, 0, 0);
    glutWireSphere(.5,100,100);
    glTranslatef(-2.0, 0, 0);

    for (int x=0; x<7;x++)
    {

        glTranslatef(0.0, 0.0, 2.0);
        glutWireSphere(.5,100,100);
        
        glTranslatef(2.0, 0, 0);
        glutWireSphere(.5,100,100);
        glTranslatef(-2.0, 0, 0);
        
    }


    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    
    // Display settings for the window
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    
    // Create the actual window
    glutCreateWindow("purff");
    
    initialize();
    
    // Register the drawing function "paint()"
    glutDisplayFunc(paint);
    
    // Register the resizing function "resize()"
    glutReshapeFunc(resize);
    
    // Start the GLUT main loop
    glutMainLoop();
    
    return 0;
}