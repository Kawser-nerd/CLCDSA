#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int b[],int l,int r);
void quicksort(int a[],int b[],int l,int r);

int main(void){
    int N,*S,*E,i,*OS,*OE,count=0;
    scanf("%d",&N);
    S = (int*)malloc(sizeof(int)*N);
    E = (int*)malloc(sizeof(int)*N);
    OS = (int*)malloc(sizeof(int)*N);
    OE = (int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d-%d",&S[i],&E[i]);
        S[i] -= S[i] % 5;
        if(E[i]%5!=0) E[i] += 5-E[i]%5;
        if(E[i]%100==60) E[i] += 40;
    }
    quicksort(S,E,0,N-1);
    OS[count] = S[0];
    OE[count] = E[0];
    for(i=1;i<N;i++){
        if(OE[count]>=S[i]){
            if(OE[count]<E[i]){
                OE[count] = E[i];
            }
        }else{
            count++;
            OS[count] = S[i];
            OE[count] = E[i];
        } 
    }
    for(i=0;i<=count;i++){
        if(OS[i]<960){
            if(OS[i]<60){
                if(OS[i]<10){
                    printf("000%d-",OS[i]);
                }else{
                    printf("00%d-",OS[i]);
                }
            }else{
                printf("0%d-",OS[i]);
            }
        }else printf("%d-",OS[i]);

        if(OE[i]<960){
            if(OE[i]<60){
                if(OE[i]<10){
                    printf("000%d\n",OE[i]);
                }else{
                    printf("00%d\n",OE[i]);
                }
            }else{
                printf("0%d\n",OE[i]);
            }
        }else printf("%d\n",OE[i]);
    }
    return 0;
}

int partition(int a[],int b[],int l,int r){
    int i=l,j=r;
    while(1){
        for(;i<r;i++){
            if(a[i]>=a[r]) break;
        }
        for(;j>=0;j--){
            if(a[j]<a[r]) break;
        }
        if(i<j){
            int tmp,tmp2;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            tmp2 = b[i];
            b[i] = b[j];
            b[j] = tmp2;
        }else{
            int tmp,tmp2;
            tmp = a[r];
            a[r] = a[i];
            a[i] = tmp;
            tmp2 = b[r];
            b[r] = b[i];
            b[i] = tmp2;
            break;
        }
    }
    return i;
}

void quicksort(int a[],int b[],int l,int r){
    int i;
    if(r<=l) return;
    i = partition(a,b,l,r);
    quicksort(a,b,l,i-1);
    quicksort(a,b,i+1,r);
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d-%d",&S[i],&E[i]);
         ^