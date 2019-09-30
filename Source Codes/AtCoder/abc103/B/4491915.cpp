#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    a = a+a;

    if(a.find(b) != string::npos) puts("Yes");
    else puts("No");
    return 0;
}