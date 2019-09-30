#include<iostream>
#include<cstdio>
#include<map>
//#include<>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
        if(test<1200)
            printf("ABC\n");
        else if(test>=1200 && test<2800)
            printf("ARC\n");
        else if(test>=2800)
            printf("AGC\n");
    return 0;
}