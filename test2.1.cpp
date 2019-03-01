#include <iostream>

using namespace std;

int main ()
{
    int c = 7;
    int *pc = &c;
    char d = 'd';
    char *pd = &d;
    int a[] = {12,4,6};
    char b[] = {'t','f','r'};
    int c1 = 8;
    char d1 = 'e';
    int *pa = a;
    char *pb = b;
    cout << &pc << " " << &pd << endl;
    cout << &pa << " " << &pa+1 << " " << &pa+2 << endl;
    cout << &pb << " " << &pb+1 << " " << &pb+2 << endl;
}
// Nhận xét: int chiếm 4 bits, còn char chiếm 1 bit.
