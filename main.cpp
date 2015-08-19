#include "Bintree.h"
#include "he.h"
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
    myglinit();
    for (auto x : {6, 7, 4, 2, 11, 8, 13, 14, 21, 1} )
       b.add(x);
    b.showtree();
    glutMainLoop();
    return 0;
}

