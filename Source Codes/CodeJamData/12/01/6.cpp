/*
Author: Shu LIN
Data: 2012/4/14
language: C++
*/

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

const string chset = "yhesocvxduiglbkrztnwjpfmaq";

int count[26];
int p[26], match[26];
char str[100 + 5];

int main()
{
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    int t;
    int i, j, k;

    scanf("%d", &t);
    gets(str);
    for (i = 0; i < t; ++i) {
        gets(str);
        printf("Case #%d: ", i + 1);
        for (j = 0; str[j] != '\0'; ++j)
            if ('a' <= str[j] && str[j] <= 'z')
                printf("%c", chset[str[j] - 'a']);
            else
                printf("%c", str[j]);
        printf("\n");
    }

    return 0;
}