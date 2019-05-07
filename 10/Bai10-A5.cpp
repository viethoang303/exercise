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

void address(Point& a)
{
    cout << &a.x << endl << &a.y << endl << &a << endl;
}
int main ()
{
    Point a;
    Point b[3];
    a = b[1];
    address(a);
    address(b[1]);
    return 0;
}
//Địa chỉ của Struct bị sao chép vs địa chỉ của Struct sao chép là khác nhau
