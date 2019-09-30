#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

typedef enum {
  SEA,
  NOT_VISITED,
  VISITED,
} Cell;

typedef struct {
  int x;
  int y;
} Point;

char map[12][12];

void search_home(Point* result)
{
  for(int x = 1; x <= 10; x++) {
    for(int y = 1; y <= 10; y++) {
      if(map[x][y] == VISITED || map[x][y] == NOT_VISITED) {
        result->x = x;
        result->y = y;
        return;
      }
    }
  }
  fputs("No graund cell found\n", stderr);
  exit(1);
}

int count_all_groud_area()
{
  int cnt = 0;
  for(int x = 1; x <= 10; x++) {
    for(int y = 1; y <= 10; y++) {
      if(map[x][y] == VISITED || map[x][y] == NOT_VISITED) {
        cnt++;
      }
    }
  }
  return cnt;
}

void clear_groud()
{
  for(int x = 1; x <= 10; x++) {
    for(int y = 1; y <= 10; y++) {
      if(map[x][y] == VISITED) {
        map[x][y] = NOT_VISITED;
      }
    }
  }
}

int count_area(int x, int y)
{
  if(map[x][y] != NOT_VISITED) {
    return 0;
  }
  int total_cnt = 1;
  map[x][y] = VISITED;
  total_cnt += count_area(x-1, y);
  total_cnt += count_area(x+1, y);
  total_cnt += count_area(x, y-1);
  total_cnt += count_area(x, y+1);
  return total_cnt;
}

void try_fill(int x, int y, int required_area)
{
  int total_area = 0;
  total_area += count_area(x-1, y);
  total_area += count_area(x+1, y);
  total_area += count_area(x, y-1);
  total_area += count_area(x, y+1);
  if(total_area == required_area) {
    puts("YES");
    exit(0);
  }
}

void try_all_candidates(int required_area)
{
  for(int x = 1; x <= 10; x++) {
    for(int y = 1; y <= 10; y++) {
      if(map[x][y] == SEA) {
        map[x][y] = VISITED;
        try_fill(x, y, required_area);
        clear_groud();
        map[x][y] = SEA;
      }
    }
  }
}

Cell char2cell(char ch)
{
  switch(ch) {
    case 'o':
      return NOT_VISITED;
    case 'x':
      return SEA;
    default:
      fprintf(stderr, "Unknown char found: '%c'\n", ch);
      exit(1);
  }
}

int main()
{
  memset(map, SEA, sizeof(map));
  for(int x = 1; x <= 10; x++) {
    for(int y = 1; y <= 10; y++) {
      char ch = getchar();
      map[x][y] = char2cell(ch);
    }
    getchar(); // remove LF
  }

  int all_groud_area = count_all_groud_area();
  if(all_groud_area == 10 * 10) {
    puts("YES");
    exit(0);
  }

  try_all_candidates(all_groud_area);
  puts("NO");

  return 0;
}