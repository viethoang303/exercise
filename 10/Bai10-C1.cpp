#include <iostream>
#include <cstring>

using namespace std;

struct String
{
    int n;
    char* p = new char[n];
    String (const char* a){
        n = strlen(a);
        for (int i=0; i<n; i++){
            *(p+i) = a[i];
        }
    }
    void Destructor(){
        delete [] p;
    }
    void print(){
        cout << p << endl;
    }
    void append(const char* s){
        int m = strlen(p)+strlen(s);
        char* temp = new char[m];
        for(int i=0; i<strlen(p); i++){
            *(temp+i)=*(p+i);
        }
        for(int i=strlen(p); i<m; i++){
            *(temp+i)=*(s+i-strlen(p));
        }
        char* s1;
        s1 = p;
        delete [] s1;
        p = new char[m];
        for(int i=0; i<m; i++){
            *(p+i) = *(temp+i);
        }
    }
};
int main ()
{
    String a("hello");
    a.print();
    a.append(" there");
    a.print();
    a.Destructor();
    return 0;
}
