#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int main()
{
    char s[20];
    cin>>s;
    for(int i=0;s[i];i++)
    {
        if(s[i]==',')
            s[i]=' ';
    }
    cout<<s;
}