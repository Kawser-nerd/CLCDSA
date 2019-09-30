#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number[4],i,j,result;
    char op_1,op_2,op_3;
    for(i=0; i<4; i++)
        scanf("%1d",&number[i]);
    for(i=0; i<8; i++)
    {
        j=i;
        result=number[0];
        if(j/4==0)
        {
            result+=number[1];
            op_1='+';
        }
        else
        {
            result-=number[1];
            op_1='-';
        }
        j=j%4;
        if(j/2==0)
        {
            result+=number[2];
            op_2='+';
        }
        else
        {
            result-=number[2];
            op_2='-';
        }
        j=j%2;
        if(j==0)
        {
            result+=number[3];
            op_3='+';
        }
        else
        {
            result-=number[3];
            op_3='-';
        }
        if(result==7)
            break;
    }
    printf("%d%c%d%c%d%c%d=7\n",number[0],op_1,number[1],op_2,number[2],op_3,number[3]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%1d",&number[i]);
         ^