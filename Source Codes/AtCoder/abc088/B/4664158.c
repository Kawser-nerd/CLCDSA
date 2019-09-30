#include<stdio.h>
#include<stdlib.h>
int conpar(const int *val1, const int *val2);
int n,a[100],i,alice,bob;
int m = sizeof(a)/sizeof(a[0]);
int main(void){
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),conpar);
    for(i = 0;i < n;i++){
        if(i%2 == 0||i == 0){
      alice += a[i];
        }else{
            bob += a[i];
        }
    }
    printf("%d",alice-bob);

    return EXIT_SUCCESS;
}
int conpar(const int *vall,const int *val2){
    if (*vall < *val2){
        return 1;
    }else if( *vall ==*val2){
        return 0;
    }else{
        return -1;
    }
} ./Main.c: In function ‘main’:
./Main.c:11:27: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
     qsort(a,n,sizeof(int),conpar);
                           ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘int (*)(const int *, const int *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^