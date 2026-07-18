#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float r = 10.0;
float f = 70.0;
float t = 0.0003;
float radarRotation = 0.0;
float bg_x_pos = 0.0;
float bg_y_pos = 0.0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 500.0, -1.0, 1.0);
}

float rgb(float rgb)
{
    float x = rgb / 255;
    return floorf(x * 100) / 100;
}

void drawRotatingRadar(float posX, float posY, float rotation)
{
    glPushMatrix();

    glTranslatef(posX, posY, 0.0f);

    //tower stand
    glBegin(GL_POLYGON);
    glColor3f(rgb(170), rgb(170), rgb(170));
    glVertex2i(0, 0);
    glVertex2i(25, 0);
    glVertex2i(25, 80);
    glVertex2i(0, 80);
    glEnd();

    //the tower top connector
    glBegin(GL_POLYGON);
    glColor3f(rgb(150), rgb(150), rgb(150));
    glVertex2i(5, 80);
    glVertex2i(20, 80);
    glVertex2i(30, 110);
    glVertex2i(-5, 110);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(12.5, 110);
    glVertex2f(12.5, 130);
    glEnd();

    glTranslatef(12.5f, 130.0f, 0.0f);

    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    glRotatef(rotation * 0.5f, 1.0f, 0.0f, 0.0f);


    glColor3f(rgb(100), rgb(100), rgb(100));
    glLineWidth(2);
    // Top band
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 10 * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
    // Draw vertical meridian lines
    for (int angle = 0; angle < 360; angle += 45) {
        float rad = angle * 3.1416f / 180.0f;
        glBegin(GL_LINES);
        glVertex2f(25 * cosf(rad), 25 * sinf(rad));
        glVertex2f(-25 * cosf(rad), -25 * sinf(rad));
        glEnd();
    }

    glPopMatrix();
}

void drawProva()
{
    drawRotatingRadar(300.0f, 100.0f, radarRotation);

    // drawing tower
    glBegin(GL_QUADS);
    glColor3f(rgb(92), rgb(141), rgb(148));
    glVertex2i(450, 100);
    glVertex2i(480, 100);
    glVertex2i(480, 240);
    glVertex2i(450, 240);
    glEnd();

    // 2 lines at the top
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(460, 260);
    glVertex2f(460, 290);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(470, 260);
    glVertex2f(470, 310);
    glEnd();

    // Circle at the top
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(465, 259);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + 465, y + 259);
        }
    glEnd();

    // drawing runway
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(0, 50);
    glVertex2f(50, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(100, 50);
    glVertex2f(150, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(200, 50);
    glVertex2f(250, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(300, 50);
    glVertex2f(350, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(400, 50);
    glVertex2f(450, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(500, 50);
    glVertex2f(550, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(600, 50);
    glVertex2f(650, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(700, 50);
    glVertex2f(750, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(800, 50);
    glVertex2f(850, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(900, 50);
    glVertex2f(950, 50);
    glEnd();

    glPushMatrix();
    glTranslatef(r, f, 0.0f);

    //Jet
    glBegin(GL_POLYGON);
    glColor3f(rgb(40), rgb(50), rgb(65));
    glVertex2i(-20, 55);
    glVertex2i(10, 55);
    glVertex2i(-10, 90);
    glVertex2i(-30, 90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(55), rgb(65), rgb(80));
    glVertex2i(-30, 40);
    glVertex2i(-20, 55);
    glVertex2i(40, 55);
    glVertex2i(90, 35);
    glVertex2i(30, 25);
    glVertex2i(-10, 25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(30), rgb(40), rgb(50));
    glVertex2i(-10, 30);
    glVertex2i(30, 30);
    glVertex2i(10, 10);
    glVertex2i(-20, 10);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(rgb(176), rgb(224), rgb(230));
    glVertex2i(40, 55);
    glVertex2i(55, 50);
    glVertex2i(40, 45);
    glEnd();

    glPopMatrix();
}

void drawMeher()
{
    // drawing sky
    glBegin(GL_POLYGON);
    glColor3f(rgb(228), rgb(247), rgb(254));
    glVertex2i(0, 100);
    glVertex2i(1000, 100);

    glColor3f(rgb(47), rgb(199), rgb(236));
    glVertex2i(1000, 500);
    glVertex2i(0, 500);
    glEnd();

    //Building
    glBegin(GL_QUADS);
    glColor3f(rgb(109), rgb(137), rgb(144));
    glVertex2i(550, 250);
    glVertex2i(870, 230);
    glVertex2i(870, 250);
    glVertex2i(550, 270);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(rgb(175), rgb(182), rgb(184));
    glVertex2i(650, 180);
    glVertex2i(850, 230);
    glVertex2i(550, 250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(211), rgb(157), rgb(61));
    glVertex2i(650, 220);
    glVertex2i(850, 220);
    glVertex2i(850, 230);
    glVertex2i(650, 230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(rgb(128), rgb(184), rgb(218));
    glVertex2i(650, 100);
    glVertex2i(850, 100);
    glVertex2i(850, 220);
    glVertex2i(650, 220);
    glEnd();

    // glass window
    glBegin(GL_POLYGON);
    glColor3f(rgb(220), rgb(242), rgb(247));
    glVertex2i(670, 110);
    glVertex2i(740, 110);
    glVertex2i(740, 200);
    glVertex2i(670, 200);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(220), rgb(242), rgb(247));
    glVertex2i(760, 110);
    glVertex2i(830, 110);
    glVertex2i(830, 200);
    glVertex2i(760, 200);
    glEnd();

    glPushMatrix();
    glTranslatef(bg_x_pos, bg_y_pos, 0.0f);

    // Drawing cloud
    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 400);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + 0, y + 400);
    }
    glEnd();

    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(30, 410);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + 30, y + 410);
    }
    glEnd();

    glColor3f(0.5f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(60, 400);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + 60, y + 400);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex2i(0, 380);
    glVertex2i(60, 380);
    glVertex2i(60, 400);
    glVertex2i(0, 400);
    glEnd();

    glPopMatrix();
}

void timer(int value)
{
    if (r <= 1000)
    {
        r = r + 2.0;
        f = f + t;
        t = t + 0.0015;
    }
    else {
        r = -200;
        f = 70;
        t = 0.0003;
    }

    bg_x_pos += 1;
    if (bg_x_pos > 1000) {
    bg_x_pos = -1000;
    }

    radarRotation += 0.5f;
    if (radarRotation >= 360.0f) {
        radarRotation -= 360.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(16, timer, 0);
}

void Draw(){

    glClear(GL_COLOR_BUFFER_BIT);

    drawMeher();

    drawProva();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1400, 680);
    glutCreateWindow("Computer Graphics Project:Airport Runway");
    init();
    glutDisplayFunc(Draw);
    glutTimerFunc(16, timer, 0);
    glutMainLoop();
    return 0;
}
