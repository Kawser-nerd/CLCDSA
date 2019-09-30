#include<stdio.h>
char show_sign(int m)
{
    if (m==0) return '+';
    else return '-';
}

int main()
{
    int a[8]={0},sign[8],i,j,result=0;
    int temp;
    scanf("%d",&temp);
    for (i=0;i<4;i++)
    {
        a[3-i]=temp%10;
        temp/=10;
    }
    for (i=0;i<8;i++)
    {
        sign[0]=i%2;
        sign[1]=(i/2)%2;
        sign[2]=(i/4)%2;
        result=a[0];
        for (j=0;j<3;j++)
        {
            if (sign[j]==0) result+=a[j+1];
            if (sign[j]==1) result-=a[j+1];
        }
        if (result==7){
            printf("%d%c%d%c%d%c%d=7\n",a[0],show_sign(sign[0]),a[1],show_sign(sign[1]),a[2],show_sign(sign[2]),a[3]);
            break;
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&temp);
     ^