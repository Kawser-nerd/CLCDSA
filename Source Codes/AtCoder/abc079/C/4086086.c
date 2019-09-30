#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{  int a,b,c,d,k;

            while(~scanf("%d",&k))
            {   d=k%10;
                c=(k/10)%10;
                b=(k/100)%10;
                a=(k/1000)%10;
                if(a+b+c+d==7) {printf("%d+%d+%d+%d=7\n",a,b,c,d);return 0;}
                if(a+b-c+d==7) {printf("%d+%d-%d+%d=7\n",a,b,c,d);return 0;}
                if(a+b-c-d==7) {printf("%d+%d-%d-%d=7\n",a,b,c,d);return 0;}
                if(a+b+c-d==7) {printf("%d+%d+%d-%d=7\n",a,b,c,d);return 0;}
                if(a-b+c+d==7) {printf("%d-%d+%d+%d=7\n",a,b,c,d);return 0;}
                if(a-b-c+d==7) {printf("%d-%d-%d+%d=7\n",a,b,c,d);return 0;}
                if(a-b+c-d==7) {printf("%d-%d+%d-%d=7\n",a,b,c,d);return 0;}
                if(a-b-c-d==7) {printf("%d=%d-%d-%d=7\n",a,b,c,d);return 0;}



            }



}