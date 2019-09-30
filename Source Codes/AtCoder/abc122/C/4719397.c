#include <stdio.h>
#include <stdlib.h>
int ac_flag(char*,int,int);
 
int main(void) {
  int n,q;
  scanf("%d %d", &n, &q);
  char *s;
  s = malloc(n);
  scanf("%s", s);
  int i,l,r;
  int count[n];
  count[0]=0;
  for (i=0;i<n-1;i++){
    if(s[i]==65){
      if(s[i+1]==67){
        count[i+1] = count[i] + 1;
        continue;
      }
    }
    count[i+1] = count[i]; 
  }
  for(i=0;i<q;i++){
    scanf("%d %d", &l, &r);
    printf("%d\n", count[r-1] - count[l-1]);
  }
  free(s);
  return 0;
}

int ac_flag(char *s, int l, int r){
  int i;
  int count = 0;
  for (i=l-1;i<r-1;i++){
    if(s[i]==65){
      if(s[i+1]==67){
        count++;
        i++;
      }
    }
  }
  return count;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &q);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &l, &r);
     ^