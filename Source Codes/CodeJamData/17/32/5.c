#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

#define JAMIE 0
#define CAMERON 1

typedef struct{
  int start;
  int end;
  int parent;
} act_t;

int chrono_sort(const void * a, const void * b){
  const act_t * A = a;
  const act_t * B = b;

  return A->start - B->start;
}

int short_sort(const void * a, const void * b){
  const act_t * A = a;
  const act_t * B = b;

  if (A->parent == -1 && B->parent > -1)
    return 1;
  if (A->parent > -1 && B->parent == -1)
    return -1;

  return ((A->end + 1440) - A->start) % 1440 - (B->end + 1440- B->start) % 1440;
}

void solve(){
  int A_C, A_J, c, j, i;
  act_t *C, *J, *acts, *gaps;
  act_t *a, *b;
  int on_duty;
  int time[2] = {0, 0};
  int changes; 
  char schedule[1440];

  for (i = 0; i < 1440; ++i)
    schedule[i] = -1;

  scanf("%d%d", &A_C, &A_J);

#if DEBUG
  printf("%d %d\n", A_C, A_J);
#endif 

  C = malloc(A_C * sizeof(act_t));
  J = malloc(A_J * sizeof(act_t));
  acts = malloc((A_J + A_C) * sizeof(act_t));

  for (c = 0; c < A_C; ++c){
    scanf("%d%d", &(C[c].start), &(C[c].end));
    acts[c] = C[c];
    acts[c].parent = CAMERON;
  }

  for (j = 0; j < A_J; ++j){
    scanf("%d%d", &(J[j].start), &(J[j].end));
    acts[c + j] = J[j];
    acts[c + j].parent = JAMIE;
  }

//  qsort(C, A_C, sizeof(act_t), chrono_sort);
//  qsort(J, A_J, sizeof(act_t), chrono_sort);
  qsort(acts, A_C + A_J, sizeof(act_t), chrono_sort);

  time[JAMIE] = time[CAMERON] = 0;
  for (i = 0; i < A_C + A_J; ++i){
    time[1 - acts[i].parent] += acts[i].end - acts[i].start;
    for (c = acts[i].start; c < acts[i].end; ++c)
      schedule[c] = 1 - acts[i].parent;
  }

  gaps = malloc((A_C + A_J) * sizeof(act_t));
  for (i = 0; i < A_J + A_C; ++i){
    a = &(acts[i]);
    b = &(acts[(i + 1) % (A_J + A_C)]);
    gaps[i].start = a->end;
    gaps[i].end = b->start;
    if (a->parent == b->parent)
      gaps[i].parent = 1 - a->parent;
    else
      gaps[i].parent = -1;
  }

  qsort(gaps, A_C + A_J, sizeof(act_t), short_sort);
  for (i = 0; i < A_J + A_C; ++i){
    if (gaps[i].end < gaps[i].start) gaps[i].end += 1440;
    if (gaps[i].parent >= 0){
      if (720 - time[gaps[i].parent] >= (gaps[i].end + 1440 - gaps[i].start) % 1440){
        for (c = gaps[i].start; c < gaps[i].end; ++c)
          schedule[c % 1440] = gaps[i].parent;
        time[gaps[i].parent] += gaps[i].end - gaps[i].start;
      }
      else {
        for (c = gaps[i].start; time[gaps[i].parent] < 720; ++c){
          schedule[c % 1440] = gaps[i].parent;
          ++time[gaps[i].parent];
        }
        for (; c < gaps[i].end; ++c){
          schedule[c % 1440] = 1 - gaps[i].parent;
          ++time[1 - gaps[i].parent];
        }
      }
    }
    else {
      on_duty = schedule[gaps[i].start - 1];
      for (c = gaps[i].start; c < gaps[i].end && time[on_duty] < 720; ++c){
        schedule[c % 1440] = on_duty;
        ++time[on_duty];
      }
      on_duty = 1 - on_duty;
      for (; c < gaps[i].end; ++c){
        schedule[c % 1440] = on_duty;
        ++time[on_duty];
      }
    }
  }

#if DEBUG
  for (i = 0; i < A_C + A_J; ++i){
    printf("act: %d %d %d\t\t gap: %d %d %d\n", acts[i].start, acts[i].end, acts[i].parent, gaps[i].start, gaps[i].end, gaps[i].parent);
  }

  for (i = 0; i < 1440; ++i)
      printf("%c", schedule[i] + 'B');
    if (schedule[i] < 0){
      //fprintf(stderr, "ERROR!\n");
      //exit(1);
    }
#endif

  changes = 0;
  for (i = 0; i < 1440; ++i)
    if (schedule[i] != schedule[(i + 1) % 1440])
      ++changes;

  printf("%d", changes);
}

int main(int argc, char* argv[]){
  int T, t;

  scanf(" %d", &T);

  for (t = 1; t <= T; ++t){
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }

  return 0;
}
