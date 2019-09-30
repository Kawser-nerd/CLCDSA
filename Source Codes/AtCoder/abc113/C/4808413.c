#include <stdio.h>
#include <stdlib.h>

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


void quick_sort (int array[],int sub_array1[],int sub_array2[], int left, int right);
void swap_int (int *x,  int *y);
int partition (int array[],int sub_array1[],int sub_array2[], int left, int right);



void swap_int (int *x,  int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int partition (int array[],int sub_array1[],int sub_array2[], int left, int right) {
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
            swap_int(&sub_array1[i], &sub_array1[j]);
            swap_int(&sub_array2[i], &sub_array2[j]);
        }
    } while (i < j);
 
    swap_int(&array[pivot], &array[j]);   //pivot???
    swap_int(&sub_array1[pivot], &sub_array1[j]);   //pivot???
    swap_int(&sub_array2[pivot], &sub_array2[j]);   //pivot???
    return j;
}
 

void quick_sort (int array[],int sub_array1[],int sub_array2[], int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partition(array,sub_array1,sub_array2, left, right);
        // pivot??????????????
        quick_sort(array,sub_array1,sub_array2, left, pivot-1);
        quick_sort(array,sub_array1,sub_array2, pivot+1, right);
    }
}


SINT32 main() {
    SINT32 n,m;
    scanf("%d%d",&n,&m);
    int *year = malloc(sizeof(int)*100001);
    int *city = malloc(sizeof(int)*100001);
    int *num = malloc(sizeof(int)*100001);
    int *haya2 = malloc(sizeof(int)*100001);

    int *haya = malloc(sizeof(int)*100001);

    for (SINT32 i = 0; i < 100001; i++) {
        city[i] = 0;
        year[i] = 0;
        num[i] = 0;
        haya[i] = 0;
        haya2[i] = 0;
    }


    for (SINT32 i = 0; i < m; i++) {
        scanf("%d%d", &city[i],&year[i]);
        num[i] = i;
    }

    quick_sort(year,city,num, 0, m-1);

    for (SINT32 i = 0; i < m; i++) {
        haya[city[i]] = haya[city[i]] + 1;
        haya2[i] = haya[city[i]];
    }
/*
    for (SINT32 i = 0; i < m; i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
    */

    quick_sort(num,city,haya2, 0, m-1);
/*
    for (SINT32 i = 0; i < m; i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
    */


    for (SINT32 i = 0; i < m; i++) {
        printf("%06d%06d\n",city[i],haya2[i]);
    } 

    
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:86:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &city[i],&year[i]);
         ^