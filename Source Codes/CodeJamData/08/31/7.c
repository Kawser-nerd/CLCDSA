/* 
 * File:   text.c
 * Author: Duong
 *
 * Created on July 27, 2008, 5:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

int N, P, K, L;
int frequency[1000000];
int sorted_frequency[1000000];
int temp_frequency[1000000];
int keypad[1000][1000];

void sort(int *frequency, int *sorted_frequency) {
  int i, j, temp;
  for (i = 0; i < L; ++i) {
    temp_frequency[i] = frequency[i];
  }
  for (i = 1; i < L; ++i) {
    for (j = i; j > 0; --j) {
      if (temp_frequency[j] > temp_frequency[j - 1]) {
        temp = sorted_frequency[j];
        sorted_frequency[j] = sorted_frequency[j - 1];
        sorted_frequency[j - 1] = temp;
        temp = temp_frequency[j];
        temp_frequency[j] = temp_frequency[j - 1];
        temp_frequency[j - 1] = temp;
      }
    }
  }
}

int main(int argc, char** argv) {
  int i, j, k;
  double result;
  scanf("%d\n", &N);
  for (i = 0; i < N; ++i) {
    scanf("%d %d %d", &P, &K, &L);
    for (j = 0; j < L; ++j) {
      scanf("%d", &frequency[j]);
      sorted_frequency[j] = j;      
    }
    sort(frequency, sorted_frequency);
    /*for (k = 0; k < L; ++k) {
      printf("%d ", sorted_frequency[k]);
    }
    printf("\n");*/
    int counter = 0;
    result = 0;
    for (k = 0; k < P; ++k) {
      if (counter >= L) break;
      for (j = 0; j < K; ++j) {
        if (counter >= L) break;        
        keypad[j][k] = sorted_frequency[counter];
        result += frequency[keypad[j][k]] * (k + 1);
        //printf("%d ", keypad[j][k]);
        counter++;        
      }
      //printf("\n");
    }
    if (counter < L) {};
    printf("Case #%d: %0.0f\n", i + 1, result);
  }
  /*L = 3;
  frequency[0] = 4; frequency[1] = 5; frequency[2] = 6;
  sorted_frequency[0] = 0; sorted_frequency[1] = 1; sorted_frequency[2] = 2;
  sort(frequency, sorted_frequency);
  printf("%d %d %d", sorted_frequency[0], sorted_frequency[1], sorted_frequency[2]);*/
  return (EXIT_SUCCESS);
}

