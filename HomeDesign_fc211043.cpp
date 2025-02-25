#include <glut.h>
#include <cmath>


void setupLighting() {
    //light properties
    GLfloat light_position[] = { 5.0, 8.0, 5.0, 1.0 };  //light source at some height
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };   //ambient light
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };   //diffuse light
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };  //specular light

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}
//set material properties
void setMaterialProperties(GLfloat r, GLfloat g, GLfloat b) {
    GLfloat material_ambient[] = { r * 0.2f, g * 0.2f, b * 0.2f, 1.0f };
    GLfloat material_diffuse[] = { r, g, b, 1.0f };
    GLfloat material_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat material_shininess[] = { 50.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}




void drawSky() {
    setMaterialProperties(0.53f, 0.81f, 0.92f); //sky blue

    float skyWidth = 0.01f; //for thin quads

    //back side of the house
    for (float x = -2.5; x <= 4.0; x += 0.001) { 
        glBegin(GL_QUADS);
        glVertex3f(x - skyWidth / 2, 0.0, -2.0); //bottom-left
        glVertex3f(x + skyWidth / 2, 0.0, -2.0); //bottom-right
        glVertex3f(x + skyWidth / 2, 5.0, -2.0); //top-right
        glVertex3f(x - skyWidth / 2, 5.0, -2.0); //top-left
        glEnd();
    }

    //left side of the house 
    for (float z = -2.0; z <= 4.0; z += 0.001) { 
        glBegin(GL_QUADS);
        glVertex3f(-1.8 - skyWidth / 2, 0.0, z); //bottom-left
        glVertex3f(-1.8 + skyWidth / 2, 0.0, z); //bottom-right
        glVertex3f(-1.8 + skyWidth / 2, 5.0, z); //top-right
        glVertex3f(-1.8 - skyWidth / 2, 5.0, z); //top-left
        glEnd();
    }
}
void drawSandFloor() {
    setMaterialProperties(0.839, 0.796, 0.878); //color

    glBegin(GL_QUADS);

    //left side of the house
    glVertex3f(-1.4, -0.01, -2.0);
    glVertex3f(-1.4, -0.01, -2.0);
    glVertex3f(-1.4, -0.01, 4.5);
    glVertex3f(-1.4, -0.01, 4.5);

    //right side of the house
    glVertex3f(1.5, -0.01, -2.0);
    glVertex3f(4.0, -0.01, -2.0);
    glVertex3f(4.0, -0.01, 4.0);
    glVertex3f(1.5, -0.01, 4.0);

    //front side of the house
    glVertex3f(-1.8, -0.01, 1.5);
    glVertex3f(1.5, -0.01, 1.5);
    glVertex3f(1.5, -0.01, 4.0);
    glVertex3f(-1.8, -0.01, 4.0);

    //back side of the house
    glVertex3f(1.5, -0.01, -2.0);
    glVertex3f(1.45, -0.01, -2.0);
    glVertex3f(1.45, -0.01, -1.5);
    glVertex3f(1.5, -0.01, -1.5);

    glEnd();
}
void drawGrassFence() {
    setMaterialProperties(0.02, 0.459, 0.125); //green color

    float fenceWidth = 0.04f; //for thin quads

    //back side of the house
    for (float x = 1.3; x <= 3.0; x += 0.01) { //range for a longer fence
        glBegin(GL_QUADS);
        glVertex3f(x - fenceWidth / 2, 0.0, -1.6); //bottom-left
        glVertex3f(x + fenceWidth / 2, 0.0, -1.6); //bottom-right
        glVertex3f(x + fenceWidth / 2, 1.0, -1.6); //top-right
        glVertex3f(x - fenceWidth / 2, 1.0, -1.6); //top-left
        glEnd();
    }

    //left side of the house 
    for (float z = 1.3; z <= 3.0; z += 0.01) { 
        glBegin(GL_QUADS);
        glVertex3f(-1.5 - fenceWidth / 2, 0.0, z); //bottom-left
        glVertex3f(-1.5 + fenceWidth / 2, 0.0, z); //bottom-right
        glVertex3f(-1.5 + fenceWidth / 2, 1.0, z); //top-right
        glVertex3f(-1.5 - fenceWidth / 2, 1.0, z); //top-left
        glEnd();

    }

                        /*                            GRASS FENCE IN WIREFRAME - WITH GL_LINES
                        glColor3f(0.0, 0.5, 0.0); //fence color
                        glBegin(GL_LINES);

                        //back side of the house
                        for (float x = 1.3; x <= 2.5; x += 0.1) { //range for a longer fence
                            glVertex3f(x, 0.0, -2.0); //bottom of the fence
                            glVertex3f(x, 1.0, -2.0); //top of the fence
                        }

                        //left side of the house
                        for (float z = 1.3; z <= 3.0; z += 0.1) { 
                            glVertex3f(-1.8, 0.0, z);
                            glVertex3f(-1.8, 1.0, z);
                        }

                        glEnd(); */
}
void drawBaseOutsideFloor() {
    setMaterialProperties(0.741, 0.741, 0.749); //color

    glBegin(GL_QUADS);
    //right side of the house
    glVertex3f(1.5, 0.0, -2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(1.5, 0.0, 2.0);

    //front side of the house
    glVertex3f(-2.0, 0.0, 1.5);
    glVertex3f(1.5, 0.0, 1.5);
    glVertex3f(1.5, 0.0, 2.0);
    glVertex3f(-2.0, 0.0, 2.0);

    glEnd();
}
void drawBase() {
    setMaterialProperties(0.718, 0.631, 0.8);  //color
  
    glBegin(GL_QUADS);

    //wall 1 (back wall)
    glVertex3f(1.5, 0.0, -1.5); //bottom-right
    glVertex3f(1.5, 2.0, -1.5); //top-right
    glVertex3f(-1.5, 2.0, -1.5); //top-left
    glVertex3f(-1.5, 0.0, -1.5); //bottom-left 

    //wall 2 (right wall)
    glVertex3f(1.5, 0.0, 1.5); //bottom-right
    glVertex3f(1.5, 2.0, 1.5); //top-right
    glVertex3f(1.5, 2.0, -1.5); //top-left
    glVertex3f(1.5, 0.0, -1.5); //bottom-left

    //wall 3 (front wall)
    glVertex3f(-1.5, 0.0, 1.5); //bottom-right
    glVertex3f(-1.5, 2.0, 1.5); //top-right
    glVertex3f(1.5, 2.0, 1.5); //top-left
    glVertex3f(1.5, 0.0, 1.5); //bottom-left   
    
    //wall 4 (left wall)
    glVertex3f(-1.5, 0.0, -1.5); //bottom-right
    glVertex3f(-1.5, 2.0, -1.5); //top-right
    glVertex3f(-1.5, 2.0, 1.5); //top-left
    glVertex3f(-1.5, 0.0, 1.5); //bottom-left  

    glEnd();
    
    
    
                            /*                               WALLS IN WIREFRAME - WITH GL_LINES
                            glColor3f(0.6f, 0.4f, 0.2f); //color for walls
                            glBegin(GL_LINES);
                            //base outline
                            //glVertex3f(-1.5, 0.0, -1.5); glVertex3f(1.5, 0.0, -1.5);
                            glVertex3f(1.5, 0.0, -1.5); glVertex3f(1.5, 0.0, 1.5);
                            glVertex3f(1.5, 0.0, 1.5); glVertex3f(-1.5, 0.0, 1.5);
                            //glVertex3f(-1.5, 0.0, 1.5); glVertex3f(-1.5, 0.0, -1.5);

                            //walls (corners)
                            //glVertex3f(-1.5, 0.0, -1.5); glVertex3f(-1.5, 2.0, -1.5);
                            glVertex3f(1.5, 0.0, -1.5); glVertex3f(1.5, 2.0, -1.5);
                            glVertex3f(1.5, 0.0, 1.5); glVertex3f(1.5, 2.0, 1.5);
                            glVertex3f(-1.5, 0.0, 1.5); glVertex3f(-1.5, 2.0, 1.5);

                            glEnd(); */
}
void drawBalcony() {
    setMaterialProperties(0.859, 0.533, 0.345); //color
    glBegin(GL_LINES);

    //balcony outline
    glVertex3f(-1.5, 2.0, -1.5); glVertex3f(1.5, 2.0, -1.5);
    glVertex3f(1.5, 2.0, -1.5); glVertex3f(1.5, 2.0, 1.5);
    glVertex3f(1.5, 2.0, 1.5); glVertex3f(-1.5, 2.0, 1.5);
    glVertex3f(-1.5, 2.0, 1.5); glVertex3f(-1.5, 2.0, -1.5);

    //vertical bars
    for (float x = -1.5; x <= 1.5; x += 0.1) {
        glVertex3f(x, 2.0, -1.5); glVertex3f(x, 2.5, -1.5);
        glVertex3f(x, 2.0, 1.5); glVertex3f(x, 2.5, 1.5);
    }
    for (float z = -1.5; z <= 1.5; z += 0.1) {
        glVertex3f(-1.5, 2.0, z); glVertex3f(-1.5, 2.5, z);
        glVertex3f(1.5, 2.0, z); glVertex3f(1.5, 2.5, z);
    }

    //balcony vertical bar upside outline
    glVertex3f(-1.5, 2.5, -1.5); glVertex3f(1.5, 2.5, -1.5);
    glVertex3f(1.5, 2.5, -1.5); glVertex3f(1.5, 2.5, 1.5);
    glVertex3f(1.5, 2.5, 1.5); glVertex3f(-1.5, 2.5, 1.5);
    glVertex3f(-1.5, 2.5, 1.5); glVertex3f(-1.5, 2.5, -1.5);

    glEnd();
}
void drawPillars() {
    setMaterialProperties(0.62, 0.286, 0.263); //wooden pillars 
    glBegin(GL_QUADS);

    //pillar thickness
    float width = 0.1;

    //front-left pillar
    glVertex3f(-1.5 - width, 2.0, 1.5);
    glVertex3f(-1.5 + width, 2.0, 1.5);
    glVertex3f(-1.5 + width, 3.0, 1.5);
    glVertex3f(-1.5 - width, 3.0, 1.5);

    //front-right pillar
    glVertex3f(1.5 - width, 2.0, 1.5);
    glVertex3f(1.5 + width, 2.0, 1.5);
    glVertex3f(1.5 + width, 3.0, 1.5);
    glVertex3f(1.5 - width, 3.0, 1.5);

    //back-left pillar
    glVertex3f(-1.5 - width, 2.0, -1.5);
    glVertex3f(-1.5 + width, 2.0, -1.5);
    glVertex3f(-1.5 + width, 2.5, -1.5);
    glVertex3f(-1.5 - width, 2.5, -1.5);

    //back-right pillar
    glVertex3f(1.5 - width, 2.0, -1.5);
    glVertex3f(1.5 + width, 2.0, -1.5);
    glVertex3f(1.5 + width, 3.0, -1.5);
    glVertex3f(1.5 - width, 3.0, -1.5);

    glEnd();
}
void drawRoof() {
    setMaterialProperties(0.612, 0.055, 0.016); //roof color

    //roof base
    glBegin(GL_QUADS);
    glVertex3f(-1.7, 3.0, -1.7); //bottom-left
    glVertex3f(1.7, 3.0, -1.7);  //bottom-right
    glVertex3f(1.7, 3.0, 1.7);   //top-right
    glVertex3f(-1.7, 3.0, 1.7);  //top-left
    glEnd();

    //roof sides (triangles)
    glBegin(GL_TRIANGLES);
    //front side
    glVertex3f(-1.7, 3.0, -1.7); //bottom-left
    glVertex3f(1.7, 3.0, -1.7);  //bottom-right
    glVertex3f(0.0, 4.5, 0.0);   //peak of the roof

    //right side
    glVertex3f(1.7, 3.0, -1.7);  //bottom-left
    glVertex3f(1.7, 3.0, 1.7);   //bottom-right
    glVertex3f(0.0, 4.5, 0.0);   //peak of the roof

    //back side
    glVertex3f(1.7, 3.0, 1.7);   //bottom-left
    glVertex3f(-1.7, 3.0, 1.7);  //bottom-right
    glVertex3f(0.0, 4.5, 0.0);   //peak of the roof

    //left side
    glVertex3f(-1.7, 3.0, 1.7);  //bottom-left
    glVertex3f(-1.7, 3.0, -1.7); //bottom-right
    glVertex3f(0.0, 4.5, 0.0);   //peak of the roof
    glEnd();


                                        /*                       ROOF IN WIREFRAME - WITH GL_LINES
                                        glBegin(GL_LINES);

                                        // Roof base
                                        //glVertex3f(-1.7, 3.0, -1.7);
                                        //glVertex3f(1.7, 3.0, -1.7);

                                        glVertex3f(1.7, 3.0, -1.7);
                                        glVertex3f(1.7, 3.0, 1.7);

                                        glVertex3f(1.7, 3.0, 1.7);
                                        glVertex3f(-1.7, 3.0, 1.7);

                                        //glVertex3f(-1.7, 3.0, 1.7);
                                        //glVertex3f(-1.7, 3.0, -1.7)

                                        // Roof peak
                                        //glVertex3f(0.0, 4.5, 0.0);
                                        //glVertex3f(-1.7, 3.0, -1.7);

                                        glVertex3f(0.0, 4.5, 0.0);
                                        glVertex3f(1.7, 3.0, -1.7);

                                        glVertex3f(0.0, 4.5, 0.0);
                                        glVertex3f(1.7, 3.0, 1.7);

                                        glVertex3f(0.0, 4.5, 0.0);
                                        glVertex3f(-1.7, 3.0, 1.7);

                                        glEnd(); */

}
void drawFrontSideWindows() {
    setMaterialProperties(0.859, 0.533, 0.345); //wooden color
    glLineWidth(6.0); //thick outlines

    //window 1 (left front side)
    glBegin(GL_LINES);
    glVertex3f(-1.0, 0.2, 1.5); //bottom-left
    glVertex3f(-1.0, 1.2, 1.5); //top-left

    glVertex3f(-1.0, 1.2, 1.5); //top-left
    glVertex3f(-0.6, 1.2, 1.5); //top-right

    glVertex3f(-0.6, 1.2, 1.5); //top-right
    glVertex3f(-0.6, 0.2, 1.5); //bottom-right

    glVertex3f(-0.6, 0.2, 1.5); //bottom-right
    glVertex3f(-1.0, 0.2, 1.5); //bottom-left

    //horizontal line in the middle of window 1
    glVertex3f(-0.6, 0.6, 1.5); //bottom-middle
    glVertex3f(-1.0, 0.6, 1.5); //top-middle
    glEnd(); 



    //window 2 (right front side)
    glBegin(GL_LINES);
    glVertex3f(0.2, 0.2, 1.5); //bottom-left
    glVertex3f(0.2, 1.2, 1.5); //top-left

    glVertex3f(0.2, 1.2, 1.5); //top-left
    glVertex3f(0.6, 1.2, 1.5); //top-right

    glVertex3f(0.6, 0.2, 1.5); //top-right
    glVertex3f(0.6, 1.2, 1.5); //tottom-right

    glVertex3f(0.6, 0.2, 1.5); //tottom-right
    glVertex3f(0.2, 0.2, 1.5); //tottom-left

    //horizontal line in the middle of window 2
    glVertex3f(0.2, 0.6, 1.5); //bottom-middle
    glVertex3f(0.6, 0.6, 1.5); //top-middle
    glEnd();  
} 
void colorFrontSideWindows() {
    setMaterialProperties(0.961, 0.886, 0.478); //yellow color

    //window 01
    glBegin(GL_QUADS);
    glVertex3f(-1.0, 0.21, 1.501); //bottom-left
    glVertex3f(-0.6, 0.21, 1.501); //bottom-right
    glVertex3f(-0.6, 1.19, 1.501); //top-right
    glVertex3f(-1.0, 1.19, 1.501); //top-left
    glEnd();

    //window 02
    glBegin(GL_QUADS);
    glVertex3f(0.2, 0.21, 1.501); //bottom-left
    glVertex3f(0.6, 0.21, 1.501); //bottom-right
    glVertex3f(0.6, 1.19, 1.501); //top-right
    glVertex3f(0.2, 1.19, 1.501); //top-left
    glEnd();
}
void drawRightSideDoorAndWindow() {
    setMaterialProperties(0.859, 0.533, 0.345); //wooden
    glLineWidth(6.0); //thick outlines

    //door
    glBegin(GL_LINES);
    glVertex3f(1.5, 0.1, -0.2); //bottom-left
    glVertex3f(1.5, 1.2, -0.2); //top-left

    glVertex3f(1.5, 1.2, -0.2); //top-left
    glVertex3f(1.5, 1.2, -0.8); //top-right

    glVertex3f(1.5, 1.2, -0.8); //top-right
    glVertex3f(1.5, 0.1, -0.8); //bottom-right

    glVertex3f(1.5, 0.1, -0.8); //bottom-right
    glVertex3f(1.5, 0.1, -0.2); //bottom-left
    glEnd();

    //window
    glBegin(GL_LINES);
    glVertex3f(1.5, 0.3, 0.8); //bottom-left
    glVertex3f(1.5, 1.3, 0.8); //top-left

    glVertex3f(1.5, 1.3, 0.8); //top-left
    glVertex3f(1.5, 1.3, 0.4); //top-right

    glVertex3f(1.5, 1.3, 0.4); //top-right
    glVertex3f(1.5, 0.3, 0.4); //bottom-right

    glVertex3f(1.5, 0.3, 0.4); //bottom-right
    glVertex3f(1.5, 0.3, 0.8); //bottom-left

    //horizontal line in the middle of the window
    glVertex3f(1.5, 0.7, 0.4); //bottom-middle
    glVertex3f(1.5, 0.7, 0.8); //top-middle
    glEnd();
}
void colorRightSideDoorAndWindow() {
    setMaterialProperties(0.961, 0.886, 0.478); //yellow color

    //window 01
    glBegin(GL_QUADS);
    glVertex3f(1.501, 0.3, 0.8); //bottom-left
    glVertex3f(1.501, 0.3, 0.4); //bottom-right
    glVertex3f(1.501, 1.3, 0.4); //top-right
    glVertex3f(1.501, 1.3, 0.8); //top-left
    glEnd();

    //door
    glBegin(GL_QUADS);
    glVertex3f(1.501, 0.1, -0.2); //bottom-left
    glVertex3f(1.501, 0.1, -0.8); //bottom-right
    glVertex3f(1.501, 1.2, -0.8); //top-right
    glVertex3f(1.501, 1.2, -0.2); //top-left
    glEnd();
}




void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glLoadIdentity();

    //set camera
    gluLookAt(6.0, 4.0, 8.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);

    //set solid rendering mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //enable depth testing
    glEnable(GL_DEPTH_TEST);

    //set line thickness - in wireframe
    glLineWidth(2.0);

    //draw components
    drawSky();
    drawSandFloor();     
    drawGrassFence();
    drawBaseOutsideFloor();
    drawBase();
    drawBalcony();
    drawPillars();
    drawRoof();
    colorFrontSideWindows();
    drawFrontSideWindows(); 
    colorRightSideDoorAndWindow();
    drawRightSideDoorAndWindow();

    glFlush();
    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Home Structure");

    setupLighting();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}