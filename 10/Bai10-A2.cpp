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

void print1(Point& a)
{
    cout << &a << endl;
}

void print2(Point b)
{
    cout << &b << endl;
}

int main ()
{
    Point p;
    p.get(1,2);
    print1(p);
    print2(p);
    return 0;
}
//Khi chương trình chạy xong ta thấy chương trình in ra 2 địa chỉ khác nhau//
