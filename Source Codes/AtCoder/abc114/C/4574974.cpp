#include <stdio.h>
int count1=0;
int num;
void xiandan(long long n,unsigned char flag)
{
    if(n<=num)
    {
        if(flag==07)

        count1++;

            xiandan(n*10+3,flag|01);
            xiandan(n*10+5,flag|02);
            xiandan(n*10+7,flag|04);




    }

}
int main()
{
    scanf("%d",&num);
    xiandan(0,0);
    printf("%d",count1);
    return 0;
}