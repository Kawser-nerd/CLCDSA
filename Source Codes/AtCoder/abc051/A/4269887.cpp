#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] == ',')printf(" ");
        else printf("%c", s[i]);
    }


    return 0;
}