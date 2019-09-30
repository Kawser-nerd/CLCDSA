// Just for the fun of it, use bc (arbitrary precision calculator language)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 256
#define MAX     105
#define MAX_SP  50000

typedef struct {
  char len, s[MAX];
} SPalindrome;

int sol[MAX], nsp, la, lb;
SPalindrome sp[MAX_SP];
char a[MAX], b[MAX];


void generate(int pos, int sum) {
  int i, j, k;

  if (pos==26) return;
  if (pos!=0) {
    k = 0;
    for (j=0; j<pos; j++)     sp[nsp].s[k++] = sol[j];
    for (j=pos-1; j>=0; j--)  sp[nsp].s[k++] = sol[j];
    sp[nsp++].len = k;
  }

  for (i=0; sum*2+i*i<10 && i<=3; i++) {
    if (i==0 && pos==0) continue;
    k = 0;
    for (j=0; j<pos; j++)    sp[nsp].s[k++] = sol[j];
    sp[nsp].s[k++] = i;
    for (j=pos-1; j>=0; j--) sp[nsp].s[k++] = sol[j];
    sp[nsp++].len = k;
  }

  for (i=0; (sum+i*i)*2<10 && i<=2; i++) {
    if (i==0 && pos==0) continue;
    sol[pos] = i;
    generate(pos+1, sum+i*i);
  }
}

int compare(const void *a, const void *b) {
  SPalindrome *sp1 = (SPalindrome *)a;
  SPalindrome *sp2 = (SPalindrome *)b;
  int i;
  
  if (sp1->len != sp2->len) return (sp1->len - sp2->len);
  for (i=0; i<sp1->len; i++) {
    if (sp1->s[i] < sp2->s[i]) return -1;
    if (sp1->s[i] > sp2->s[i]) return +1;
  }
  return 0;
}

void show() {
  int i, j;
  for (i=0; i<nsp; i++) {
    printf("%5d: ", i);
    for (j=0; j<sp[i].len; j++)
      printf("%d", sp[i].s[j]+'0');
    putchar('\n');
  }
}

void getsq() {
  int i, j, k;
  FILE *f;
  char buf[MAX_BUF];

  f = fopen("tmp.txt", "w");
  for (i=0; i<nsp; i++) {
    for (j=0; j<sp[i].len; j++) fprintf(f, "%d", sp[i].s[j]);
    fputc('*', f);
    for (j=0; j<sp[i].len; j++) fprintf(f, "%d", sp[i].s[j]);
    fputc('\n', f);
  }
  fclose(f);
  system("bc < tmp.txt > res.txt"); // :)
  
  nsp = 0;
  f = fopen("res.txt", "r");
  k = 0;
  while (fgets(buf, MAX_BUF, f)) {
    for (i=0; buf[i]!='\n' && buf[i]!='\\'; i++) sp[nsp].s[k++] = buf[i];
    if (buf[i]=='\n') {
      sp[nsp].len=k;
      sp[nsp].s[k]=0;
      k = 0;
      nsp++;
    }
  }
  fclose(f);
}

int calc(int pos, int ls, char *s) {
  int i;
  if (sp[pos].len < ls) return -1;
  if (sp[pos].len > ls) return +1;
  for (i=0; i<ls; i++) 
    if (sp[pos].s[i] < s[i])      return -1;
    else if (sp[pos].s[i] > s[i]) return +1;
  return 0;
}

int main() {
  int i, t, c, count, aux1, aux2;
  
  nsp = 0;
  generate(0, 0);
  qsort(sp, nsp, sizeof(SPalindrome), compare);
  getsq();
  //show();

 
  scanf("%d", &t);
  for (c=1; c<=t; c++) {
    scanf("%s %s", &a, &b);
    la = strlen(a); lb = strlen(b);
    for (i=0, count=0; i<nsp; i++) {
      aux1 = calc(i, la, a);
      if (aux1 < 0) continue;
      aux2 = calc(i, lb, b);
      if (aux2 > 0) break;
      //printf("%s < %s < %s\n", a, sp[i].s, b);
      count++;
    }
    printf("Case #%d: %d\n", c, count);
  }
    
  return 0;

}
