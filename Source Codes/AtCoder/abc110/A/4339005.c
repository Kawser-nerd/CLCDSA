#include <stdio.h>

int main(void)
{
    int n[3];
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    n[0] = A,n[1]=B,n[2]=C;
    for (int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if (i<j){
                if (n[i]<n[j]){
                    int a = n[i];
                    n[i] = n[j];
                    n[j] = a;
                }
            }
        }
    } 
    printf("%d",n[0]*10+n[1]+n[2]);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^