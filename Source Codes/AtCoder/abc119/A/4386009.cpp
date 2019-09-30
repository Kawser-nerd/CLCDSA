#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    string s1;
    cin>>s1;
    string s2="2019/04/30";
    int j=s1.compare(s2);
    if(j>0)
        printf("TBD\n");
    else
        printf("Heisei\n");
    return 0;
}