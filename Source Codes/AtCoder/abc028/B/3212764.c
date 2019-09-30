#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int cnt[6]= {0,0,0,0,0,0};
    char str[100],ch;

    while((ch = getchar()) != EOF){
        ++cnt[ch - 'A'];
    }
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ",cnt[i]);
    }
    printf("%d\n",cnt[5]);
    return 0;
}