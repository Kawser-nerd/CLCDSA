#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;


int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}


int main(void){
    char s[100000];
    cin >> s;
    int rez=strlen(s);
    for (int i=1; i<strlen(s); i++)
    {
        if (s[i]!=s[i-1])
                 {
                    rez=min(rez,max(i,strlen(s)-i));
                 }
    }
    cout << rez;
    return 0;
}