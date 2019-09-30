#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    while(~scanf("%d %d %d",&a,&b,&c))
    {
        int sum = a+b+c;
        if(sum == 17)
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
}