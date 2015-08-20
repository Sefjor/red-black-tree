#ifndef BINTREE_H
#define BINTREE_H
using namespace std;
 enum class col{black, red};
class Bintree {
    struct leaf {
        int number;
        leaf* childleft;
        leaf* childright;
        leaf* parent;
        col color;
    };
leaf* rootleaf;
public:
    void showtree( int xnew = 400, int ynew = 25);
    void add(int x);
private:
    void showtree(leaf* root, int xnew , int ynew, double level);
    void add(int x, leaf* root, leaf* father);
    void makechilds(leaf* root);
};
#endif // BINTREE_H
