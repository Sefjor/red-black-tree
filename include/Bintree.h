#ifndef BINTREE_H
#define BINTREE_H
using namespace std;


class Bintree {
    enum class col {black, red};
    struct leaf {
        int number;
        leaf* childleft;
        leaf* childright;
        leaf* parent;
        col color;
    };
leaf* rootleaf;
public:
    Bintree(int x);
    ~Bintree();
    void showtree( int xnew = 400, int ynew = 25);
    void add(int x, bool recurs = false);
private:
     void showtree(leaf* root, int xnew , int ynew, double level);
};
#endif // BINTREE_H
