#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable: 4996)

char *fileNameIn= "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;

// sigh... a super hack, but no time to spend on this, and I don't want to deal with bignums :(
// inspiration from: http://www.fengyuan.com/palindrome.html
int numFairSquares = 39;
long long fair_squares[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};

int main(void) {

  int T,t;
  long long A,B;
  int i;
  int count;
 
  in = fopen(fileNameIn, "r");
  out = fopen(fileNameOut, "w");
  
  fscanf(in,"%d\n",&T);

  for (t=1; t <= T; t++) {
    fscanf(in,"%lld\n",&A);
    fscanf(in,"%lld\n",&B);
    count = 0;
    for (i=0; i < numFairSquares; i++) {
      if ((A <= fair_squares[i])&&(fair_squares[i] <= B)) {
        count++;
      }
    }
    fprintf(out,"Case #%d: %d\n", t, count);
  }
  fclose(in);
  fclose(out);
}
