#include <GL/glut.h>
#include <stdlib.h>

// Variables globales
double ty = 0;
double tx = 0;
double rotate_x = 0;
double rotate_y = 0;
bool arribaiz = false;
bool arribader = false;
double tamano = 1.0;
double longitud1 = 0;
double longitud2 = 0;
bool anch = true;
double ancho = 1.0;

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = {1.0, 1.0, 0.5, 0.0}; // Posición de la luz
    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0}; // Componente ambiente de la luz
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0}; // Componente difusa de la luz
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0}; // Componente especular de la luz

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glScalef(1.5,1.5,1.5);
    glTranslatef(0.0, 0.0, 0.6);

    //Piso madera
    glColor3f(0.827, 0.686, 0.533);
    glRectf(-1.0, -1.0, 1.0, 0.0);

    //Techo
    glColor3f(0.4, 0.5, 0.2);
    glRectf(-1.0, 0.5, 1.0, 1.0);

    //Pared verde
    glPushMatrix();
    glTranslatef(0.0,0.0,-0.01);
    glColor3f(0.5, 0.8, 0.6);
    glRectf(0.33, -0.1, 1.0, 1.0);
    glTranslatef(0.0,0.0,-0.01);

    // Puerta de madera oscura
    glColor3f(0.2, 0.1, 0.0);
    glRectf(0.6, -0.1, 0.8, 0.5);
    glColor3f(1.0, 0.5, 0.0);
    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.8, -0.1);
    glVertex2f(0.8, 0.5);
    glVertex2f(0.6, 0.5);
    glEnd();
    glPopMatrix();

    // Pared en el fondo
    glColor3f(0.7, 0.7, 0.7); // Color de la nueva pared
    glRectf(-1.0, -1.0, 0.33, 1.0);

    // Puerta de madera oscura
    glPushMatrix();
    glTranslatef(0.0,0.0,-0.01);
    glColor3f(0.2, 0.1, 0.0);
    glRectf(0.0, -0.1, 0.33, 0.5);
    glColor3f(1.0, 0.5, 0.0);
    glLineWidth(0.1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, -0.1);
    glVertex2f(0.33, -0.1);
    glVertex2f(0.33, 0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glTranslatef(tx, 0.0, 0.0);
    glTranslatef(0.0, ty, 0.0);
    glScalef(tamano, tamano, tamano);


    float naranja[3] = {1.0f, 0.4f, 0.0f};
    float blanco[3] = {1.0f, 1.0f, 1.0f};
    float negro[3] = {0.0f, 0.0f, 0.0f};
    float cafe[3] = {0.5f, 0.2f, 0.07f};
    float skin[3] = {1.0f, 0.87f, 0.68f};

    //Cabeza
    glPushMatrix();
    glTranslatef(0.0, -0.35, -0.2);
    glColor3fv(naranja);
    glutSolidSphere(0.2, 50, 50);
    glPopMatrix();

    //Cuerpo
    glPushMatrix();
    glTranslatef(0.0, -0.47, -0.2);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3fv(naranja);
    GLUquadric* quadratic5 = gluNewQuadric();
    gluQuadricDrawStyle(quadratic5, GLU_FILL);
    gluCylinder(quadratic5, 0.15, 0.15, 0.2, 50, 50);
    GLUquadric* quadraticDisk = gluNewQuadric();
    gluQuadricDrawStyle(quadraticDisk, GLU_FILL);
    glTranslatef(0.0, 0.0, 0.2);
    gluDisk(quadraticDisk, 0.0, 0.15, 50, 50);
    glPopMatrix();

    //brazo izquierdo
    glPushMatrix();
    glTranslatef(0.1, -0.55, -0.2);
    glRotatef(90, 1.0, 0.0, 0.0);
    if(arribaiz){
        glRotatef(135, 0.0, 1.0, 0.0);
    }else{
        glRotatef(45, 0.0, 1.0, 0.0);
    }
    glColor3fv(naranja);
    GLUquadric* quadratic = gluNewQuadric();
    gluQuadricDrawStyle(quadratic, GLU_FILL);
    gluCylinder(quadratic, 0.03, 0.03, 0.15, 50, 50);
    glTranslatef(0.0, 0.0, 0.15);
    glColor3fv(cafe);
    glutSolidSphere(0.05, 50, 50);
    glPopMatrix();

    //brazo derecho
    glPushMatrix();
    glTranslatef(-0.1, -0.55, -0.2);
    glRotatef(90, 1.0, 0.0, 0.0);
    if(arribader){
    	glRotatef(-135, 0.0, 1.0, 0.0);
    }else{
        glRotatef(-45, 0.0, 1.0, 0.0);
    }
    glColor3fv(naranja);
    GLUquadric* quadratic2 = gluNewQuadric();
    gluQuadricDrawStyle(quadratic2, GLU_FILL);
    gluCylinder(quadratic2, 0.03, 0.03, 0.15, 50, 50);
    glTranslatef(0.0, 0.0, 0.15);
    glColor3fv(cafe);
    glutSolidSphere(0.05, 50, 50);
    glPopMatrix();

    //pierna izquierda
    glPushMatrix();
    glTranslatef(0.075, -0.67, -0.2);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3fv(naranja);
    GLUquadric* quadratic3 = gluNewQuadric();
    gluQuadricDrawStyle(quadratic3, GLU_FILL);
    gluCylinder(quadratic3, 0.075, 0.075, 0.15, 50, 50);
    glTranslatef(0.0, 0.0, 0.15);
    glColor3fv(cafe);
    GLUquadric* quadraticDisk1 = gluNewQuadric();
    gluQuadricDrawStyle(quadraticDisk1, GLU_FILL);
    glTranslatef(0.01, 0.0, 0.0);
    gluDisk(quadraticDisk1, 0.0, 0.08, 50, 50);
    glPopMatrix();

    //pierna derecha
    glPushMatrix();
    glTranslatef(-0.075, -0.67, -0.2);
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3fv(naranja);
    GLUquadric* quadratic4 = gluNewQuadric();
    gluQuadricDrawStyle(quadratic4, GLU_FILL);
    gluCylinder(quadratic4, 0.075, 0.075, 0.15, 50, 50);
    glTranslatef(0.0, 0.0, 0.15);
    glColor3fv(cafe);
    GLUquadric* quadraticDisk2 = gluNewQuadric();
    gluQuadricDrawStyle(quadraticDisk2, GLU_FILL);
    glTranslatef(-0.01, 0.0, 0.0);
    gluDisk(quadraticDisk2, 0.0, 0.08, 50, 50);
    glPopMatrix();

    //Gorro
    glPushMatrix();
    glTranslatef(0.0, -0.35, -0.355);
    glScalef(1.0, 1.0, 0.3);
    glColor3fv(naranja);
    glutSolidSphere(0.14, 50, 50);
    glTranslatef(0.0, 0.0, -0.03);
    glColor3fv(cafe);
    glutSolidSphere(0.13, 50, 50);
    //Rostro
    glPushMatrix();
    glScalef(0.8, 1.0, 1.0);
    glTranslatef(0.0, 0.0, -0.03);
    glColor3fv(skin);
    glutSolidSphere(0.12, 50, 50);
    glPopMatrix();
    //Ojos
    glTranslatef(0.048, 0.0, -0.1);
    glColor3fv(blanco);
    glScalef(1.0, ancho, 1.0);
    glutSolidSphere(0.06, 50, 50);
    glColor3fv(negro);
    glTranslatef(0.0, 0.0, -0.06);
    glutSolidSphere(0.01, 50, 50);
    glTranslatef(-0.096, 0.0, 0.06);
    glColor3fv(blanco);
    glutSolidSphere(0.06, 50, 50);
    glColor3fv(negro);
    glTranslatef(0.0, 0.0, -0.06);
    glutSolidSphere(0.01, 50, 50);
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        tx += 0.03;
    else if (key == GLUT_KEY_LEFT)
        tx -= 0.03;
    else if (key == GLUT_KEY_UP)
        ty += 0.03;
    else if (key == GLUT_KEY_DOWN)
        ty -= 0.03;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '+') {
        tamano += 0.1;
    }else if (key == 'w')
        rotate_x += 5;
    else if(key == 's')
        rotate_x -= 5;
    else if(key == 'a')
        rotate_y += 5;
    else if(key == 'd')
        rotate_y -= 5;
    else if(key == '-')
        tamano -=0.1;

    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            arribaiz = !arribaiz;
        glutPostRedisplay();
    }else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            arribader = !arribader;
        glutPostRedisplay();
    }
}




int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Escenario 3D");
    glutReshapeWindow(1920,1080);

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    glutMainLoop();

    return 0;
}
