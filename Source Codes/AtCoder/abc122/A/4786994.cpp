#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    char b;
    scanf("%c", &b);
    if (b == 'A')
    {
        printf("T\n");
    }
    else if (b == 'C')
    {
        printf("G\n");
    }
    else if (b == 'G')
    {
        printf("C\n");
    }
    else
    {
        printf("A\n");
    }
    return 0;
}