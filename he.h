using namespace std;
#include <GL/freeglut.h>
#include <iostream>
#include "Bintree.h"
extern Bintree b;
void myglinit();
void changeSize(int w, int h);
void idle(void);
void key(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y );
void renderScene(void);
void quant(int x, int y, int& xleft, int& xright, int& yboth, int printnum, double level);
