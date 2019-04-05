#include <iostream>
#include <cstring>

using namespace std;

char* concat(const char* m, const char* n)
{
    int x = strlen(m)+strlen(n);
    char *p = new char[x];
    strcpy(p, m);
    strcat(p, n);
    return p;
}

int main()
{
    const char* a="Hello";
    const char* b="World";
    char* c=concat(a,b);
    cout << c;
    return 0;
}
