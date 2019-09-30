#include <stdio.h>
#include <stdlib.h>
typedef struct{

int price;
int maximum;


}store;
int com(const void *a,const void *b){
 int n=((store *)a)->price;
 int m=((store *)b)->price;
 if(n<m)
    return -1;
 if(n>m)
    return 1;
 return 0;
}
int main(void){
 int n;
 int m;
 store a[100000];
 long long minimum=0;
 int i;
 scanf("%d %d",&n,&m);
 for(i=0;i<n;i++){
    scanf("%d %d",&a[i].price,&a[i].maximum);
 }
 qsort(a,n,sizeof(store),com);
 for(i=0;i<n;i++){
    if(a[i].maximum>=m){
        minimum+=(long long)a[i].price*m;
        break;
    }
    minimum+=(long long)(a[i].price)*a[i].maximum;
    m-=a[i].maximum;
 }
printf("%lld",minimum);
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i].price,&a[i].maximum);
     ^