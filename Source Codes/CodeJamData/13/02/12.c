#include <stdlib.h>
#include <stdio.h>

#define LAWN_ALLOC_SIZE 128
#define MAX_HEIGHT 100

struct _point { int r, c; };
typedef struct _point point;


struct _occurences_list
{
  point positions[LAWN_ALLOC_SIZE * LAWN_ALLOC_SIZE];
  int count;
};
typedef struct _occurences_list occurences_list;


void single_test (void);


int
main (void)
{
  int T, i;
  
  scanf ("%d", &T);
  for (i = 1; i <= T; ++i)
    {
      printf ("Case #%d: ", i);
      single_test ();
    }
  
  return 0;
}


void
single_test (void)
{
  static int A[LAWN_ALLOC_SIZE][LAWN_ALLOC_SIZE];
  static occurences_list OL[LAWN_ALLOC_SIZE];
  int N, M;
  int i, j, k;
  int r, c, vok, hok;
  int result = 1;
  
  scanf ("%d %d", &N, &M);
  
  for (i = 0; i <= MAX_HEIGHT; ++i)
    OL[i].count = 0;
  
  for (i = 0; i < N; ++i)
    for (j = 0; j < M; ++j)
      {
        scanf ("%d", &(A[i][j]));
        OL[A[i][j]].positions[OL[A[i][j]].count].r = i;
        OL[A[i][j]].positions[OL[A[i][j]].count].c = j;
        OL[A[i][j]].count += 1;
      }
  
  for (i = MAX_HEIGHT; result && i >= 0; --i)
    {
      for (j = 0; j < OL[i].count; ++j)
        {
          r = OL[i].positions[j].r;
          c = OL[i].positions[j].c;
          
          vok = 1;
          for (k = 0; vok && k < N; ++k)
            if (A[k][c] > i)
              vok = 0;
          
          hok = 1;
          for (k = 0; hok && k < M; ++k)
            if (A[r][k] > i)
              hok = 0;
          
          if (! (hok || vok))
            {
              result = 0;
              break;
            }
        }
    }
  
  if (result)
    printf ("YES\n");
  else
    printf ("NO\n");
}
