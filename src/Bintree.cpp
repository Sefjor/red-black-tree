#include "Bintree.h"
#include <iostream>
#include <vector>
#include <..\he.h>
Bintree::Bintree(int x) :  rootleaf {new leaf {}} {
    rootleaf->number = x;
}

Bintree::~Bintree()
{
    delete rootleaf;
}
void Bintree::showtree(int xnew, int ynew)
{
 showtree(rootleaf, xnew, ynew, 0);
}
void Bintree::showtree(leaf* root, int xnew, int ynew, double level)
{
    ++level;
    int xleft, xright, y;
    quant(xnew, ynew, xleft, xright, y, root->number, level);
    if (root->childleft != nullptr)
        showtree(root->childleft, xleft, y, level);
    if (root->childright != nullptr)
        showtree(root->childright, xright, y,level);
}

void Bintree::add(int x, bool recurs)
{
    static leaf* p;
    static leaf* root;
    if (!recurs) {
        p = new leaf {};
        root = rootleaf;
        p->number = x;
    }
if (x == root->number)
{
    cout << x << " is already in table \n";
    return;
}
    if (x > root->number) {
        if (root->childright == nullptr) {
            root->childright = p;

        } else {
            root = root->childright;
            add(x, true);
        }
    } else {
        if (root->childleft == nullptr) {
            root->childleft = p;

        } else {
            root = root->childleft;
            add(x, true);
        }
    }

}
 Bintree b (15);
