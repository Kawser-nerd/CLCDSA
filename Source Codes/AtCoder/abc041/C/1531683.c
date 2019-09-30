#include <stdio.h>
#include <math.h>

struct data {
    long n;
    unsigned long h;
};

void sort(struct data a[], long l, long r);


int main(void){
    long N;
    scanf("%ld",&N);
    struct data d[N];
    int i;
    for(i=0;i<N;i++){
        d[i].n = i+1;
        scanf("%lu",&d[i].h);
    }
    
    sort(d, 0, N-1);
    
    for(i=0;i<N;i++){
        printf("%ld\n",d[i].n);
    }
    return 0;
}

void sort(struct data a[], long l, long r){
    long i, j;
    struct data x, y;
    
    if(l < r){
        i = l;
        j = r;
        x = a[(l+r)/2];
        do{
            while(a[i].h > x.h)
                i++;
            while(x.h > a[j].h)
                j--;
            
            if(i <= j){
                if(i < j){
                    y = a[i]; a[i] = a[j]; a[j] = y;
                }
                i++; j--;
            }
        }while(i <= j);
        
        if(l < j)
            sort(a, l, j);
        if(i < r)
            sort(a, i, r);
    }
    
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&N);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lu",&d[i].h);
         ^