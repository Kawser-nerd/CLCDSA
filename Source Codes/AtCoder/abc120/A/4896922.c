#include<stdio.h>

void input(int*,int*,int*);
int min(int,int);
int main(void){
    int a,b,c;
    int ans;
    input(&a,&b,&c);
    ans=min(c,b/a);
    printf("%d\n",ans);
    return 0;
}
void input(int* a,int* b,int* c){
    scanf("%d %d %d",a,b,c);
}
int min(int p,int q){
    int min;
    if(p<q){
        min=p;
    }
    else{
        min=q;
    }
    return min;
} ./Main.c: In function ‘input’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",a,b,c);
     ^