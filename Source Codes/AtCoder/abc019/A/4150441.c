#include <stdio.h>

int partition(int a[],int l,int r);
void quicksort(int a[],int l,int r);

int main(void){
    int num[3],i;
    for(i=0;i<3;i++)    scanf("%d",&num[i]);
    quicksort(num,0,2);
    printf("%d\n",num[1]);
    return 0;
}

int partition(int a[],int l,int r){
    int i=l,j=r;
    while(1){
        for(;i<r;i++){
            if(a[i]>=a[r]) break;
        }
        for(;j>=0;j--){
            if(a[j]<a[r]) break;
        }
        if(i<j){
            int tmp;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }else{
            int tmp;
            tmp = a[r];
            a[r] = a[i];
            a[i] = tmp;
            break;
        }
    }
    return i;
}

void quicksort(int a[],int l,int r){
    int i;
    if(r<=l) return;
    i = partition(a,l,r);
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
} ./Main.c: In function ‘main’:
./Main.c:8:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<3;i++)    scanf("%d",&num[i]);
                         ^