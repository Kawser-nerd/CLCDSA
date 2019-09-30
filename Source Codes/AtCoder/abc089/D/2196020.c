#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS (300*300+1)

typedef struct {
  int x;
  int y;
  int value;
} Point;

Point point[MAX_POINTS];

int solve(int begin, int end)
{
  return point[end].value - point[begin].value;
}

int main()
{
  memset(point, 0, sizeof(point));

  int height, width, diff;
  scanf("%d%d%d", &height, &width, &diff);
  for(int x = 0; x < height; x++) {
    for(int y = 0; y < width; y++) {
      int value;
      scanf("%d", &value);
      point[value].x = x;
      point[value].y = y;
    }
  }

  for(int i = diff+1; i <= height * width; i++) {
    point[i].value = point[i-diff].value + abs(point[i].x - point[i-diff].x)
      + abs(point[i].y - point[i-diff].y);
  }

  int num_tests;
  scanf("%d", &num_tests);
  for(int i = 0; i < num_tests; i++) {
    int begin, end;
    scanf("%d%d", &begin, &end);
    printf("%d\n", solve(begin, end));
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &height, &width, &diff);
   ^
./Main.c:29:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &value);
       ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num_tests);
   ^
./Main.c:44:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &begin, &end);
     ^