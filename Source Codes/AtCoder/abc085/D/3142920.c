#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//1 2 3 4 100 1
/*
a b???b??????????
ab?????????
???????????a???????
a????????H???????????
???????a??????
N?10^5  NlogN???????

*/

#define max 2147483647

typedef struct _atk{
    char tp;
    int dam;
}atk;

//?????
void merge(atk *a,int left,int mid,int right){
    int n1 = mid-left,n2 = right-mid;
    atk *L = (atk*)malloc(sizeof(atk)*(n1+1)),*R = (atk*)malloc(sizeof(atk)*(n2+1));
    int i;
    for(i=0;i<n1;i++){
        L[i].tp = a[left+i].tp;
        L[i].dam = a[left+i].dam;
    }
    for(i=0;i<n2;i++){
        R[i].tp = a[mid+i].tp;
        R[i].dam = a[mid+i].dam;
    }
    L[n1].dam = -2147483648;
    R[n2].dam = -2147483648;
    int j=0,k=0;
    for(i = left;i<right;i++){
        if(L[j].dam>R[k].dam){
            a[i].dam = L[j].dam;
            a[i].tp = L[j].tp;
            j++;
        }else{
            a[i].dam = R[k].dam;
            a[i].tp = R[k].tp;
            k++;
        }
    }
}

void merge_sort(atk *a,int left,int right){
    int middle;
    if(left + 1 < right){
        middle = (left+right)/2;
        merge_sort(a,left,middle);
        merge_sort(a,middle,right);
        merge(a,left,middle,right);
    }
}


int main(void){
    int N,H;
    scanf("%d %d",&N,&H);
    atk *a = (atk*)malloc(sizeof(atk)*2*N);
    int i;
    for(i=0;i<2*N;i+=2){
        scanf("%d %d",&a[i].dam,&a[i+1].dam);
        a[i].tp = 'a';
        a[i+1].tp = 'b';
    }
    merge_sort(a,0,2*N);
    int first_a,flag = 1,total = 0;
    for(i=0;i<2*N;i++){
        if(a[i].tp == 'a'){
            first_a = i;
            break;
        }
        total += a[i].dam;
        if(total>=H){
            printf("%d\n",i+1);
            flag = 0;
            break;
        }
    }
    if(flag){
        if((H-total)%a[first_a].dam == 0){
        printf("%d\n",first_a + (H-total)/a[first_a].dam);
        }else{
            printf("%d\n",first_a + 1 +(H-total)/a[first_a].dam);
        }
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:65:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&H);
     ^
./Main.c:69:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a[i].dam,&a[i+1].dam);
         ^