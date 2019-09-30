#include <stdio.h>
int retlen(char a[]);
int check_have_r(char word[], int len);
int main(void)
{
    char table[12][15];
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            table[i][j] = 0;
        }
    }
    for(int i = 0; i < 12; i++)
    {
        gets(table[i]);
    }
    int count_r = 0;
    for(int i = 0; i < 12; i++)
    {
        int len = retlen(table[i]);
        count_r += check_have_r(table[i], len);
    }
    printf("%d\n",count_r);
    return 0;
}

int retlen(char a[])
{
    int len = 0;
    while (a[len] != 0)
    {
        len++;
    }
    return len;
}

int check_have_r(char word[], int len)
{
    int iter = 0;
    while(iter < len)
    {
        if(word[iter] == 'r')
        {
            return 1;
        }
        iter++;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:9: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
         gets(table[i]);
         ^
/tmp/ccbY9ut9.o: In function `main':
Main.c:(.text.startup+0x4a): warning: the `gets' function is dangerous and should not be used.