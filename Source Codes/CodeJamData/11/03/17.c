#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int *target, int len){
  int i, j, OK = 1;
  if(len <= 1) return;
  for(i = 0; i < len; i++){
    OK = 1;
    for(j = 1; j < len; j++){
      if(target[j-1] > target[j]){
	target[j-1] ^= target[j];
	target[j] ^= target[j-1];
	target[j-1] ^= target[j];
	OK = 0;
      }
    }
    if(OK) return;
  }
}

int main(int argc, char **argv){
  FILE *f;
  if(!(f = fopen(argv[1], "r"))){ perror("FILE-RELATED OOPS"); exit(-1);}
  fseek(f, 0L, SEEK_END);
  int size = ftell(f);
  char *data = (char *)malloc(size);
  fseek(f, 0L, SEEK_SET);
  fread(data, size, 1, f);
  int i,j,k;
  for(i = 0; i < size; i++)  if(data[i] == '\n' || data[i] == ' ') data[i] = 0;
  
  char *p = data;
  int rounds = atoi(p);
  p += strlen(p)+1;
  for(i = 0; i < rounds; i++){

    int N = atoi(p);
    p += strlen(p)+1;
    int *candies = malloc(sizeof(int)*N);
    for(j = 0; j < N; j++){
      candies[j] = atoi(p);
      p += strlen(p)+1;
    }
    
    int OK = 0;
    for(j = 0; j < N; j++)OK ^= candies[j];
    if(OK) printf("Case #%d: NO\n", i+1);
    else{
      bubble_sort(candies, N);
      int answer = 0;
      for(j = 1; j < N; j++) answer += candies[j];
      printf("Case #%d: %d\n", i+1, answer);
    }
    free(candies);
  }
  free(data);
}
