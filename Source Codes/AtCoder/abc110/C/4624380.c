#include <stdio.h>

int r(char in);
void quick_sort (int array[], int left, int right);
int partition (int array[], int left, int right);
void swap (int *x,  int *y);

int main(){
    char s[200001] = {'0'};
    char t[200001] = {'0'};

    int ar_s[26] = {0};
    int ar_[26] = {0};

    scanf("%s",s);
    scanf("%s",t);


    for (int i = 0; i < 200001; i++) {
        if (r(s[i]) != -1) {
            ar_s[r(s[i])]++;
        }
        if (r(t[i]) != -1) {
            ar_[r(t[i])]++;
        }
    }

/*
    for (int i = 0; i < 26; i++) {
        printf("%d ",ar_s[i]);
    }
    printf("\n");

    for (int i = 0; i < 26; i++) {
        printf("%d ",ar_[i]);
    }
    printf("\n");
    */


    quick_sort(ar_s,0,25);
    quick_sort(ar_,0,25);

/*    for (int i = 0; i < 26; i++) {
        printf("%d ",ar_s[i]);
    }
    */

   int buf = 0;
    for (int i = 0; i < 26; i++) {
        if (ar_s[i] != ar_[i]) {
            buf = 1;
        }
    }

    if (buf == 1) {
        printf("No");
    } else {
        printf("Yes");
    }
    
    return 0; 
    
	
}

int r(char in){
    switch (in) {
        case 'a':
        return 0;
        case 'b':
        return 1;
        case 'c':
        return 2;
        case 'd':
        return 3;
        case 'e':
        return 4;
        case 'f':
        return 5;
        case 'g':
        return 6;
        case 'h':
        return 7;
        case 'i':
        return 8;
        case 'j':
        return 9;
        case 'k':
        return 10;
        case 'l':
        return 11;
        case 'm':
        return 12;
        case 'n':
        return 13;
        case 'o':
        return 14;
        case 'p':
        return 15;
        case 'q':
        return 16;
        case 'r':
        return 17;
        case 's':
        return 18;
        case 't':
        return 19;
        case 'u':
        return 20;
        case 'v':
        return 21;
        case 'w':
        return 22;
        case 'x':
        return 23;
        case 'y':
        return 24;
        case 'z':
        return 25;

        default:
        return -1;
    }

}



 
void swap (int *x,  int *y) {
  int temp;    // ??????????
 
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
    if (i < j) { swap(&array[i], &array[j]);}
  } while (i < j);
 
  swap(&array[pivot], &array[j]);   //pivot???
 
  return j;
}
 
/* ??????? */
void quick_sort (int array[], int left, int right) {
  int pivot;
 
  if (left < right) {
    pivot = partition(array, left, right);
    quick_sort(array, left, pivot-1);   // pivot??????????????
    quick_sort(array, pivot+1, right);
  }
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t);
     ^