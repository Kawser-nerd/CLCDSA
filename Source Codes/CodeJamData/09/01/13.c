#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int D,L,N;

typedef struct node {
  /* int count; */
  struct node *n[30];
} node, *dict;

dict d;
char buffer[800];

dict newdict() {
  dict d = malloc(sizeof(node));
  /* d->count = 0; */
  memset(d->n,0,sizeof(d->n));
  return d;
}

void addtodict(dict d, char *s) {
  int i;
  if (*s==0) { /* d->count++; */ return; }
  i = *s - 'a';
  if (!d->n[i])
    d->n[i] = newdict();
  addtodict(d->n[i],s+1);
  /* d->count++; */
}

void showdict(int l, dict d) {
  int i;
  /* printf("%*sLevel %d: %d words\n",l,"",l,d->count); */
  printf("%*sLevel %d\n",l,"",l);
  for (i=0;i<30;i++) {
    if (d->n[i]) {
      printf("%*s- calling for %c",l,"",i+'a');
      showdict(l+1,d->n[i]);
    }
  }
}

void showdict2(dict d) {
  int i;
  printf("<");
  for (i=0;i<30;i++) {
    if (d->n[i]) {
      printf("%c",i+'a');
      showdict2(d->n[i]);
    }
  }
  printf(">");
}

int word[20][30];

void toword(int i, char *s) {
  if (!*s) return;
  if (*s!='(') {
    word[i][*s-'a'] = 1;
    toword(i+1,s+1);
  } else {
    s++;
    while (*s != ')')
      word[i][*s++-'a'] = 1;
    toword(i+1,s+1);
  }
}

int count(int wi, dict d) {
  int i, cum = 0;
  if (wi==L) return 1;
  if (!d) return 0;
  /* printf("count with wi=%d and dict = ",wi); */
  /* showdict2(d); */
  /* printf("\n"); */
  for (i=0;i<30;i++) {
    if (word[wi][i] && d->n[i]) {
      cum += count(wi+1, d->n[i]);
    }
  }
  return cum;
}

void prt(char s, char e) {
  int i,j;
  for (i=s-'a';i<=e-'a';i++) {
    for (j=0;j<L;j++)
      printf(" %d",word[j][i]);
    printf("\n");
  }
}

int main() {
  int n,i,j;
  scanf("%d%d%d",&L,&D,&N);
  d = newdict();
  for (i=0;i<D;i++) {
    scanf("%s",buffer);
    addtodict(d,buffer);
  }
  //  showdict(1,d);
  for (i=0;i<N;i++) {
    scanf("%s",buffer);
    memset(word,0,sizeof(word));
    toword(0,buffer);
    //    prt('a','e');
    printf("Case #%d: %d\n",i+1,count(0,d));
  }
}


