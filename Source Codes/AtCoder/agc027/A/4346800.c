#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//standard
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define abs(a) ((a)>(0)?(a):-(a))

//Prototype
void quicksort(long list[], long left, long right);

int main() {
    long n,x,count = 0;
    long array[101];

    //input
    scanf("%ld%ld",&n,&x);

    for(int i = 0; i < n; i++){
        scanf("%ld",&array[i]);
    }

    //calculation
    quicksort(array, 0, n-1);


    for(int i = 0;x > 0 && i < n ;i++){
        x -=array[i];
        count++;
    }

    if(x != 0)count--;
    //Output
    printf("%ld\n",count);

    return 0;
}

void quicksort(long list[], long left, long right)
{
    long i, last;
    long temp;

    if (left >= right)
        return;

    last = left;
    for (i=left+1; i <= right; i++){
        if (list[i] < list[left] ){
            last++;
            temp=list[last];
            list[last]=list[i];
            list[i]=temp;
        }
    }

    temp=list[left];
    list[left]=list[last];
    list[last]=temp;

    quicksort(list, left, last-1);
    quicksort(list, last+1, right);
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&n,&x);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&array[i]);
         ^