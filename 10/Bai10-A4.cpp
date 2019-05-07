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
    cout << &a.x << endl << &a.y << endl << &a;
}
int main ()
{
    Point a;
    a.get(3,4);
    address(a);
    return 0;
}
/* Địa chỉ của Point a và a.x giống nhau
Trong khi đó địa chỉ của a.x và a.y cách nhau 4 bit -> ô nhớ cạnh nhau*/
