#include "Bintree.h"
#include <iostream>
#include <vector>
#include <..\he.h>

void Bintree::showtree(int xnew, int ynew)
{
    showtree(rootleaf, xnew, ynew, 0);
}
void Bintree::showtree(leaf* root, int xnew, int ynew, double level)
{
    ++level;
    int xleft, xright, y;
    quant(xnew, ynew, xleft, xright, y, root->number, level, root->color);
    if (root->childleft != nullptr)
        showtree(root->childleft, xleft, y, level);
    if (root->childright != nullptr)
        showtree(root->childright, xright, y,level);
}
void Bintree::makechilds(leaf* root)
{
    static leaf* p;
        p = new leaf {};
        root->childleft = p;
        p->parent = root;
        p->color = col::black;
        p->number = 0;
        p = new leaf {};
        root->childright = p;
        p->parent = root;
        p->color = col::black;
        p->number = 0;
}
void Bintree:: insert_case1(leaf* n)
{
    if (n->parent == nullptr)
		n->color = col::black;
	else
		insert_case2(n);
}
void insert_case2(leaf* n)
{
	if (n->parent->color == col::black)
		return;
	else
		insert_case3(n);
}
void Bintree::add(int x)
{
    add(x, rootleaf, nullptr);
}
void Bintree::add(int x, leaf* root, leaf* father)
{
    leaf** ptemp;
if (root == nullptr)
{

        rootleaf = new leaf {};
        rootleaf->number = x;
        rootleaf->parent = nullptr;
        rootleaf->color = col::black;
        makechilds(rootleaf);
        return;
}
  if (root->number == 0)
{
        root->number = x;
        root->parent = father;
        makechilds(root);
        if (root->parent->color == col::black)
        root->color = col::red;
        else
                {root->color = col::red;
               if (p->parent->parent->childleft->color == col::red && p->parent->parent->childright->color == col::red)
                }
     //   }
     return;
}
    if (x == root->number) {
        cout << x << "is already in table \n";
        return;
    }
    if (x > root->number)
        ptemp = &root->childright;
    else ptemp = &root->childleft;
        add(x, *ptemp, root);


}
Bintree b;
