#include "he.h"
#include <cmath>
#include <sstream>
#include <string>
//enum class col;
extern Bintree b;
void printtext(string txt, float num, float posX, float posY)
{
    stringstream s;
    s << txt << num;
    txt = s.str();
    unsigned int str_pel_width = 0;
    const unsigned int str_len = txt.size ();
    for (unsigned int i = 0; i < str_len; i++)
        str_pel_width += glutBitmapWidth (GLUT_BITMAP_HELVETICA_12, txt [i]);
    glRasterPos2f(posX - str_pel_width/2, posY + 4);
    glutBitmapString (GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char*>(txt.c_str()));
}
void mycircle(int dx, int dy, double r)
{
    static double x, y;
    static double PI = 3.14;
    glBegin(GL_LINES);
    x = dx + (float)r * cos(359 * PI/180.0f);
    y = dy + (float)r * sin(359 * PI/180.0f);
    for(int j = 0; j < 360; j++) {
        glVertex2f(x,y);
        x = dx + (float)r * cos(j * PI/180.0f);
        y = dy + (float)r * sin(j * PI/180.0f);
        glVertex2f(x,y);
    }
    glEnd();
}
void myline (int xfrom, int yfrom, int xto, int yto)
{
    glBegin(GL_LINES) ;
    glVertex2d(xfrom, yfrom);
    glVertex2d(xto, yto);
    glEnd();
}
void quant(int x, int y, int& xleft, int& xright, int& yboth, int printnum, double level, col color)
{
    printtext("", printnum, x, y);
    int r = 12;
    float dx = 8-level;
    xright = x + r * dx;
    yboth = y + r * 2.5;
    xleft = x - r * dx;
    if (color == col::red)  glColor3f(1, 0, 0);
    else glColor3f(0, 0, 0);
    mycircle(x, y, r);
    if (printnum != 0)
    {
    glColor3f(0, 0, 0);
    mycircle(xright, yboth, r);
    mycircle(xleft, yboth, r);
    myline(x + 0.8 * r, y + 0.6 * r, xright - 0.3 * r, yboth - 0.9 * r);
    myline(x - 0.8 * r, y + 0.6 * r, xleft + 0.3 * r, yboth - 0.9 * r);
    }
}
void myglinit()
{
    double w = 800.0;
    double h = 800.0;
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowPosition(900,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("w");
    glLoadIdentity();
    gluOrtho2D(0.0, w, h, 0.0);
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
}

void idle(void)
{
     glutPostRedisplay();
}
void key(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y )
{

}
void renderScene(void)
{
    glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     b.showtree();
    glutSwapBuffers();
    int i;
    cin >> i;
    b.add(i);
}
