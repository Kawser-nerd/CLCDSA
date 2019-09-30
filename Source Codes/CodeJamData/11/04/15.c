#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
  srand((unsigned)time(NULL));
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
    int K = 0;
    for(j = 0; j < N; j++){
      candies[j] = atoi(p) - 1;
      p += strlen(p)+1;
      if(j != candies[j]) K++;
    }

    double answer = ((double)K);
    printf("Case #%d: %lf\n", i+1, answer);
    
    free(candies);
  }
  free(data);
}
