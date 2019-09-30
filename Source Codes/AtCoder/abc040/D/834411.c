#include <stdio.h>
#include <stdlib.h>


struct Edge {
  int a, b, y;
};

struct Question {
  int n, v, w;
};

int M, N, Q;
struct Edge edges[200000];
struct Question questions[100000];
int group[100001];
int size[100001];
int answers[100000];

int findGroup(int n) {
  if(n == group[n]) {
    return n;
  }
  group[n] = findGroup(group[n]);
  return group[n];
}

void mergeGroup(int m, int n) {
  m = findGroup(m);
  n = findGroup(n);
  if(m != n) {
    int s = size[n] + size[m];
    size[m] = s;
    size[n] = s;
    group[m] = n;
  }
}

int edgeSorter(const void* a, const void* b) {
  return ((struct Edge*) b)->y - ((struct Edge*) a)->y;
}

int questionSorter(const void* a, const void* b) {
  return ((struct Question*) b)->w - ((struct Question*) a)->w;
}

int main(void) {
  int i, edgeIndex;

  scanf("%d %d", &N, &M);
  for(i = 0; i < M; i++) {
    scanf("%d %d %d", &(edges[i].a), &(edges[i].b), &(edges[i].y));
  }
  scanf("%d", &Q);
  for(i = 0; i < Q; i++) {
    questions[i].n = i;
    scanf("%d %d", &(questions[i].v), &(questions[i].w));
  }

  qsort((void*) edges, M, sizeof(edges[0]), edgeSorter);
  qsort((void*) questions, Q, sizeof(questions[0]), questionSorter);

  for(i = 1; i <= N; i++) {
    group[i] = i;
    size[i] = 1;
  }

  edgeIndex = 0;
  for(i = 0; i < Q; i++) {
    while(edgeIndex < M && edges[edgeIndex].y > questions[i].w) {
      mergeGroup(edges[edgeIndex].a, edges[edgeIndex].b);
      edgeIndex++;
    }
    answers[questions[i].n] = size[findGroup(questions[i].v)];
  }

  for(i = 0; i < Q; i++) {
    printf("%d\n", answers[i]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:52:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &(edges[i].a), &(edges[i].b), &(edges[i].y));
     ^
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &Q);
   ^
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &(questions[i].v), &(questions[i].w));
     ^