#include<stdio.h>
int main(void){
    int i,j,sum=0,bn=0,e[6],l[6],b;
    for(i=0;i<6;i++)
        scanf("%d",&e[i]);
    scanf("%d",&b);
    for(i=0;i<6;i++)
        scanf("%d",&l[i]);
    for(i=0;i<6;i++){
        if(l[i]==b)
            bn=1;
        for(j=0;j<6;j++){
            if(e[i]==l[j])
                sum++;
        }
    }
    switch(sum){
        case 6 : printf("1\n"); break;
        case 5 : if(bn)
                    printf("2\n");  
                 else
                    printf("3\n");    
                 break;
        case 4 : printf("4\n"); break;
        case 3 : printf("5\n"); break;
        default : printf("0\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&e[i]);
         ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&l[i]);
         ^