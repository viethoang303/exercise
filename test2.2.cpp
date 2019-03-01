#include <iostream>
using namespace std;
int  factorial(int n)
{
    cout << “n = “ << n << “ at ” << &n << endl;
    if (n>1) return n*factorial(n-1);
    else if (n==1) return 1;
    else if (n==0) return 1;
}

int main ()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
// Dãy giá trị giảm dần cách đều nhau nên kích thước của 1 stack frame cho hàm là 48 bytes //
