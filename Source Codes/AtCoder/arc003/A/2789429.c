#include <stdio.h>

int main(void) {
    int n,i,j=4,sum=0,a[5]={0};
    double d;
    char r[100];

    scanf("%d",&n);
    scanf("%s",r);

    for(i=0;i<n;i++){
        switch(r[i]){
            case 'A': a[0]++; break;
            case 'B': a[1]++; break;
            case 'C': a[2]++; break;
            case 'D': a[3]++; break;
            case 'F': a[4]++; break;
        }
    }
    
    for(i=0;i<5;i++){
        sum+=(j*a[i]);
        j--;
    }

    if(sum==0){printf("0\n"); return 0;}
    d=(double)sum / (double)n;

    printf("%.14f\n",d);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",r);
     ^