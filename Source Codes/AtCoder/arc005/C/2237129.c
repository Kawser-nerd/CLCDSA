#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

typedef struct {
  int x;
  int y;
  int dist;
  int life;
} Takahashi;

typedef struct {
  int dist;
  int is_block;
  int is_sentinel;
  int life;
} Cell;

#define QUEUE_SIZE 0x10000
typedef Takahashi Item;
Item queue[QUEUE_SIZE];
size_t queue_in = 0;
size_t queue_out = 0;
int queue_is_full = 0;

#define MAX_EDGE_LEN (500+2)
Cell map[MAX_EDGE_LEN][MAX_EDGE_LEN];
Takahashi start;
Takahashi goal;

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
  queue_is_full = (queue_in == queue_out);
}

int queue_pop(Item* result)
{
  if(queue_in == queue_out && !queue_is_full) {
    return 0;
  }
  memcpy(result, &queue[queue_out], sizeof(Item));
  queue_out = inc_queue_index(queue_out);
  queue_is_full = 0;
  return 1;
}

void clear_queue()
{
  queue_in = 0;
  queue_out = 0;
  queue_is_full = 0;
}

void next_takahashi(Takahashi* dst, const Takahashi* src, int dx, int dy)
{
  dst->x = src->x + dx;
  dst->y = src->y + dy;
  dst->dist = src->dist + 1;
  dst->life = src->life;
}

int bf_search()
{
  queue_push(&start);
  Takahashi takahashi;
  while(queue_pop(&takahashi)) {
    if(takahashi.x == goal.x && takahashi.y == goal.y) {
      return 1;
    }
    if(map[takahashi.x][takahashi.y].is_sentinel) {
      continue;
    }
    if(map[takahashi.x][takahashi.y].is_block) {
      takahashi.life--;
      if(takahashi.life < 0) {
        continue;
      }
    }
    if(map[takahashi.x][takahashi.y].dist <= takahashi.dist &&
       takahashi.life <= map[takahashi.x][takahashi.y].life) {
      continue;
    }
    map[takahashi.x][takahashi.y].dist = takahashi.dist;
    map[takahashi.x][takahashi.y].life = takahashi.life;
    Takahashi up;
    Takahashi down;
    Takahashi left;
    Takahashi right;
    next_takahashi(&up, &takahashi, -1, 0);
    next_takahashi(&down, &takahashi, 1, 0);
    next_takahashi(&left, &takahashi, 0, -1);
    next_takahashi(&right, &takahashi, 0, 1);
    queue_push(&up);
    queue_push(&down);
    queue_push(&left);
    queue_push(&right);
  }
  return 0;
}

void init_map()
{
  for(int x = 0; x < MAX_EDGE_LEN; x++) {
    for(int y = 0; y < MAX_EDGE_LEN; y++) {
      map[x][y].dist = INT_MAX;
      map[x][y].is_block = 1;
      map[x][y].is_sentinel = 1;
      map[x][y].life = -1;
    }
  }
}

int main()
{
  init_map();

  int height, width;
  scanf("%d%d", &height, &width);
  getchar(); // remove LF
  for(int x = 1; x <= height; x++) {
    for(int y = 1; y <= width; y++) {
      map[x][y].is_sentinel = 0;
      char ch = getchar();
      switch(ch) {
        case 's':
          start.x = x;
          start.y = y;
          start.dist = 0;
          start.life = 2;
          map[x][y].is_block = 0;
          break;
        case 'g':
          goal.x = x;
          goal.y = y;
          map[x][y].is_block = 0;
          break;
        case '#':
          map[x][y].dist = INT_MAX;
          map[x][y].is_block = 1;
          break;
        case '.':
          map[x][y].dist = INT_MAX;
          map[x][y].is_block = 0;
          break;
        default:
          fprintf(stderr, "Unknown char: '%c'\n", ch);
          exit(1);
      }
    }
    getchar(); // remove LF
  }
  if(bf_search()) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:134:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &height, &width);
   ^