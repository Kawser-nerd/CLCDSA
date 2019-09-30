#include<stdio.h>
#include<stdlib.h>
char *P[2] = {"No", "Yes"};

int compare_char1(const void *a, const void *b){return *(char*)a - *(char*)b;}
int compare_char2(const void *a, const void *b){return *(char*)b - *(char*)a;}
char S[101], T[101], s, t, c, f;
int main(){
  while((c=getchar())!=10){S[s++]=c;}
  while((c=getchar())!=10){T[t++]=c;}
  qsort(S, s, sizeof(char), compare_char1);
  qsort(T, t, sizeof(char), compare_char2);
  f=0;
  for(c=0; c<=s; c++){
    if(S[c]>T[c]){
      break;
    }else if(S[c]<T[c]){
      f=1;
      break;
    }
  }
  puts(P[f]);
}