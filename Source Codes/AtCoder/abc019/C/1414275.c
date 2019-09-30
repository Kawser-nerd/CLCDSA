#include <stdlib.h>
#include <stdio.h>
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(void){
    int t,i,j,n,ans=1;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        while(a[i]%2==0){
            a[i]=a[i]/2;
        }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int crnt=a[0];
    for(i=1;i<n;i++){
        if(crnt!=a[i])ans++;
        crnt=a[i];
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^