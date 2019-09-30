#include <stdio.h>

int main(void){
    int a,b,c,ans=0;
    scanf("%d%d%d",&a,&b,&c);
    int af=a,bf=b,cf=c;
    while(1){
        int a1,b1,c1;
        a1=a;
        b1=b;
        c1=c;
        if (a%2==1 || b%2==1|| c%2==1){
            printf("%d\n",ans);
            break;
        } else {
            a=b1/2+c1/2;
            b=c1/2+a1/2;
            c=a1/2+b1/2;
            ans++;
            if (a==af && b==bf && c==cf){
                printf("-1\n");
                break;
            }
        }
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^