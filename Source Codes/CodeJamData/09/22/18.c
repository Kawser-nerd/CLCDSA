#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char digits[201];

long long N;

void init()
{
    int i;
    for (i = 0 ; i < 201 ; i++)
        digits[i] = '\0';
    scanf("%s", &(digits[1]));
    digits[0] = '0';
}

void execute()
{
    int i,j,k, len = strlen(digits);
    //printf("leng:%d\n",len);
    for (i = len-1 ; i > 0 ; i--)
    {
        if (digits[i] > digits[i-1])
            break;
    }
    char temp[200]={'\0'};
    for (j = 0 ; j < len - i ; j++)
    {
        temp[j] = digits[len-1-j];
    //    printf("%c",temp[j]);
    }
    for (j = 0 ; j < strlen(temp) ; j++)
        if ( digits[i-1] < temp[j])
            break;
    char pp;
    pp = digits[i-1];
    digits[i-1] = temp[j];
    for(k=0;k<j;k++)
        digits[i+k] = temp[k];
    digits[i+j] = pp;
    for(k=j+1;k<strlen(temp);k++)
        digits[i+k] = temp[k];
}

int main()
{
    int cases, i, j;

    scanf("%d\n", &cases);
    for (i = 1 ; i <= cases ; i++)
    {
        init();
        execute();
        if (digits[0] == '0')
            printf("Case #%d: %s\n", i, digits+1);
        else 
            printf("Case #%d: %s\n", i, digits);
    }
}
