#include<stdio.h>
int main(){
    int l[3];
    for(int i=0;i<3;i++){
        scanf("%d",&l[i]);
    }
    if(l[0] == l[1])printf("%d\n",l[2]);
    else if(l[0] == l[2])printf("%d\n",l[1]);
    else printf("%d\n",l[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&l[i]);
         ^