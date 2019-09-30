#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    char c;
    cin>>c;
    if(c == 'a' || c=='e' || c=='i'|| c=='o'||c=='u'){
        printf("vowel");
    }
    else printf("consonant");



    return 0;
}