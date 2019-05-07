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

Point mid_point(const Point a, const Point b)
{
    Point midPoint;
    midPoint.x = (a.x + b.x)/2;
    midPoint.y = (a.y + b.y)/2;
    return midPoint;
}

int main ()
{
    Point a;
    Point b;
    Point p;
    a.get(1,2);
    b.get(3,4);
    p = mid_point(a,b);
    p.print();
    return 0;
}
