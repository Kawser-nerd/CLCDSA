#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char                SINT8;
typedef unsigned char       UINT8;
typedef short               SINT16;
typedef unsigned short      UINT16;
typedef int                 SINT32;
typedef unsigned int        UINT32;
typedef long long           SINT64;
typedef unsigned long long  UINT64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void quick_sort (int array[], int left, int right);
void swap_int (int *x,  int *y);
int partition (int array[], int left, int right);



void swap_int (int *x,  int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int partition (int array[], int left, int right) {
    int i, j, pivot;
    i = left;
    j = right + 1;
    pivot = left;   // ?????pivot???
 
    do {
        do { i++; } while (array[i] < array[pivot]);
        do { j--; } while (array[pivot] < array[j]);
        // pivot???????????????????
        if (i < j) {
            swap_int(&array[i], &array[j]);
        }
    } while (i < j);
 
    swap_int(&array[pivot], &array[j]);   //pivot???
    return j;
}
 

void quick_sort (int array[], int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partition(array, left, right);
        // pivot??????????????
        quick_sort(array, left, pivot-1);
        quick_sort(array, pivot+1, right);
    }
}



SINT32 main() {
    SINT32 ans = 0;
    SINT32 max = 10;

    SINT32 a,b;
    scanf("%d%d",&a,&b);

    SINT32 *sabun = malloc(sizeof(SINT32)*a);
    
    SINT32 *data = malloc(sizeof(SINT32)*a);
    for (SINT32 i = 0; i < a; i++) {
        scanf("%d", &data[i]);
    }

    quick_sort(data, 0, a-1);

    for (SINT32 i = 1; i < a; i++) {
        sabun[i] = data[i] - data[i-1];
    }

/*    for (SINT32 i = 0; i < a; i++) {
        printf("%d ",sabun[i]);
    }
    printf("\n");
    */

    for (SINT32 i = 1; i < b; i++) {
        ans = ans+sabun[i];
    }




    SINT32 buf = ans;
    for (SINT32 i = b; i < a; i++) {
        buf = buf - sabun[i-b+1] + sabun[i];
 //       printf("%d ",buf);
        if (buf < ans) {
            ans = buf;
        }
    }
//    printf("\n");



    printf("%d\n",ans);
    free(data);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:74:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &data[i]);
         ^