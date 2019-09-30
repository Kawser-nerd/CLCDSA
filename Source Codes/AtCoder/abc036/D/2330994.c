#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DIV 1000000007
//int f[100000], g[100000];
long long int f2, g2;
typedef struct node *link;
struct node{int n;  link next;};
link *p;
link setLink(link p, int n){
  link x = malloc(sizeof(struct node));
  x->n = n;  x->next = p;
  return x; 
}

void rmLink(link p){
  p->next = p->next->next;
}

void printLink(link p){
  link i;
  printf("link: ");
  for(i=p;i!=NULL;i=i->next) printf("%d->",i->n);
  printf(".\n");
}

void count(link q, int fr, int now){
  long long int f=1, g=1;
  int t=q->n;
  if(q->next==NULL){f2=2;  g2=1;  return;}
  while(q->next!=NULL){
    //printf("%d, %d\n",fr, q->n);
    if(q->n==fr){q = q->next;  continue;}
    count(p[q->n], now, q->n);
    f = (f*f2)%DIV;  g = (g*g2)%DIV;
    q = q->next;
  }
  g2 = f;  f2 = (g2+g)%DIV;
  //printf("%d: f..%d, g..%d\n",t, f2,g2);
  return;
}

int main(void){
  int n, a, b, c, i;
  scanf("%d",&n);
  p = malloc(sizeof(struct node *)*n);
  for(i=0;i<n;i++) p[i]=setLink(NULL,-1);
  for(i=0;i<n-1;i++){
    scanf("%d %d",&a, &b);
    a--;  b--;
    p[a] = setLink(p[a], b);
    p[b] = setLink(p[b], a);
  }
  //for(i=0;i<n;i++) printLink(p[i]);
  count(p[0], -2, 0);
  printf("%lld\n",f2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a, &b);
     ^