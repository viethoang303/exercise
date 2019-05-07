#include <iostream>
using namespace std;

struct Point
{
    float x;
    float y;
    void get(float _x, float _y){
        x = _x;
        y = _y;
    }
    void print(){
        cout << "(" << x << ", " << y << ")";
    }
};

int main ()
{
    Point p;
    p.get(1,2);
    p.print();
    return 0;
}
