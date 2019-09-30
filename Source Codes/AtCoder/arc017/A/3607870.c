#include<stdio.h>
#include<math.h>
int find(int m)
{
    int a=m/2;
    int flag=0;
    for(int i=2;i<=a;i++)
    {
        if(m%i==0)		
        {
            flag=1;	break;	
        }
        else	continue;
    }
    return flag;	
}
int main()
{
    int m;
    scanf("%d",&m);
    int b=find(m);
    if(b==1)	printf("NO\n");
    else		printf("YES\n");
    return 0;	
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^