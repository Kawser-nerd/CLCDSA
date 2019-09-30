#include<stdio.h>
int main(void){
    int n,i;
    double sum=0;
    char r[100];
    scanf("%d",&n);
    scanf("%s",r);
    for(i=0;i<n;i++){
        switch(r[i]){
            case 'A': sum+=4; break;
            case 'B': sum+=3; break;
            case 'C': sum+=2; break;
            case 'D': sum+=1; break;
            case 'F': sum+=0; break;
        }
    }
    if(sum)
        printf("%.14f\n",sum/n);
    else
        printf("0\n");
	return 0;		
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",r);
     ^