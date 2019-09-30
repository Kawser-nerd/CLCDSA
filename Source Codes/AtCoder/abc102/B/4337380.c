#include <stdio.h>

int main(void)
{
        int n,a[100],min,max,i;

        scanf("%d",&n);

        for (i=0;i<n;i++){
                scanf("%d",&a[i]);
        }

        min=a[0];
        max=a[0];

        for (i=1;i<n;i++){
                if(min>a[i])
                        min=a[i];
                if (max<a[i])
                        max=a[i];
        }

        printf("%d\n",max-min);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^
./Main.c:10:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d",&a[i]);
                 ^