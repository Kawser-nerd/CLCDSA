#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES (100+1)

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

bool is_connected[MAX_NODES][MAX_NODES];
bool is_visited[MAX_NODES];

bool is_tree(int index, int prev_index, int num_node)
{
  is_visited[index] = true;
  for(int i = 1; i <= num_node; i++) { // go next node
    if(i == prev_index) { // skip prev node
      continue;
    }
    if(is_connected[index][i]) {
      if(is_visited[i]) {
        return false;
      }
      if(!is_tree(i, index, num_node)) {
        return false;
      }
    }
  }
  return true;
}

int cnt_tree(int num_node)
{
  int cnt = 0;
  for(int i = 1; i <= num_node; i++) {
    if(!is_visited[i] && is_tree(i, -1, num_node)) {
      cnt++;
    }
  }
  return cnt;
}

int main()
{
  memset(is_visited, false, sizeof(is_visited));
  memset(is_connected, false, sizeof(is_connected));

  int num_node, num_edge;
  scanf("%d%d", &num_node, &num_edge);
  for(int i = 0; i < num_edge; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    is_connected[a][b] = true;
    is_connected[b][a] = true;
  }

  printf("%d\n", cnt_tree(num_node));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &num_node, &num_edge);
   ^
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^