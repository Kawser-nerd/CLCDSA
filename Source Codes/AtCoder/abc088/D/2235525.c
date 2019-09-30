#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGE_LEN 50
#define VERY_LARGE_I32 0x7fffffff

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

typedef struct {
  int x;
  int y;
  int dist;
} Point;

#define QUEUE_SIZE 0x1000
typedef Point Item;
Item queue[QUEUE_SIZE];
size_t queue_in = 0;
size_t queue_out = 0;
int queue_is_full = 0;

int32_t map[MAX_EDGE_LEN+2][MAX_EDGE_LEN+2];

size_t inc_queue_index(size_t index)
{
  return (index + 1) % QUEUE_SIZE;
}

void queue_push(const Item* item)
{
  if(queue_is_full) {
    fputs("Queue is full.\n", stderr);
    exit(1);
  }
  memcpy(&queue[queue_in], item, sizeof(Item));
  queue_in = inc_queue_index(queue_in);
  queue_is_full = queue_in == queue_out;
}

int queue_pop(Item* result)
{
  if(queue_in == queue_out && !queue_is_full) {
    return 1;
  }
  memcpy(result, &queue[queue_out], sizeof(Item));
  queue_out = inc_queue_index(queue_out);
  queue_is_full = 0;
  return 0;
}

void clear_queue()
{
  queue_in = 0;
  queue_out = 0;
  queue_is_full = 0;
}

void next_point(Point* dst, const Point* src, int diffx, int diffy)
{
  dst->x = src->x + diffx;
  dst->y = src->y + diffy;
  dst->dist = src->dist + 1;
}

int count_dots(int height, int width)
{
  int result = 0;
  for(int x = 1; x <= height; x++) {
    for(int y = 1; y <= width; y++) {
      if(map[x][y] != -1) {
        result++;
      }
    }
  }
  return result;
}

int bf_search(int height, int width)
{
  Point start;
  start.x = 1;
  start.y = 1;
  start.dist = 1;
  queue_push(&start);
  while(1) {
    Point point;
    if(queue_pop(&point)) {
      return -1;
    }
    if(point.x == height && point.y == width) {
      return point.dist;
    }
    if(map[point.x][point.y] <= point.dist) {
      continue;
    }
    map[point.x][point.y] = point.dist;
    Point up;
    Point down;
    Point left;
    Point right;
    next_point(&up, &point, -1, 0);
    next_point(&down, &point, 1, 0);
    next_point(&left, &point, 0, -1);
    next_point(&right, &point, 0, 1);
    queue_push(&up);
    queue_push(&down);
    queue_push(&left);
    queue_push(&right);
  }
}

int main()
{
  memset(map, -1, sizeof(map));

  int height, width;
  scanf("%d%d", &height, &width);
  getchar(); // remove LF
  for(int x = 1; x <= height; x++) {
    for(int y = 1; y <= width; y++) {
      char ch = getchar();
      switch(ch) {
        case '.':
          map[x][y] = VERY_LARGE_I32;
          break;
        case '#':
          map[x][y] = -1;
          break;
        default:
          fprintf(stderr, "Unknown char: '%c'\n", ch);
          exit(1);
      }
    }
    getchar(); // remove LF
  }
  int distance = bf_search(height, width);
  if(distance == -1) {
    printf("%d\n", distance);
    return 0;
  }
  int num_dots = count_dots(height, width);
  printf("%d\n", num_dots - distance);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:120:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &height, &width);
   ^