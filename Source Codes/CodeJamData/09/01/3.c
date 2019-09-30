#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXd 5123
#define MAXl 20

char word[MAXd][MAXl];
char *patt;

int d,l,n;

int close[MAXl];

void pre() {
  int i,j;

  for(i=j=0 ; patt[i]!='\0' ; i++,j++) {
    if(patt[i]=='(')
      while(patt[i]!=')') i++;

    close[j]=i+1;
  }
}

int match(int k) {
  int i,j;

  for(i=j=0 ; word[k][i]!='\0' ; j=close[i],i++) {
    while(j<close[i] && word[k][i]!=patt[j]) j++;
    if(word[k][i]!=patt[j]) return 0;
  }

  return 1;
}

int main() {
  int i,j,k;

  scanf(" %d %d %d", &l, &d, &n);

  for(i=0 ; i<d ; i++)
    scanf(" %s", word[i]);

  for(i=0 ; i<n ; i++) {
    scanf(" %as", &patt);

    pre();
    for(j=k=0 ; j<d ; j++)
      k += match(j);
    printf("Case #%d: %d\n", i+1, k);

    free(patt);
  }

  return 0;
}
