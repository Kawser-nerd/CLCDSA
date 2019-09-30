#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

char str[5000];
char arr[5000];

int main(void) {

  int t, T;
  int start;
  int end;
  int len;
  int i;

  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");

  fscanf(in,"%d",&T);
  
  for (t=1; t <= T; t++) {
    fscanf(in,"%s",str);
    len = strlen(str);
    fprintf(out, "Case #%d: ", t);
    start = end = 2500;
    arr[start] = str[0];
    for (i=1; i < len; ++i) {
      if (str[i] >= arr[start]) {
        start--;
        arr[start] = str[i];
      } else {
        end++;
        arr[end] = str[i];
      }
    }
    arr[end + 1] = 0;
    fprintf(out, "%s\n", arr + start);
  }

  fclose(in);
  fclose(out);
}