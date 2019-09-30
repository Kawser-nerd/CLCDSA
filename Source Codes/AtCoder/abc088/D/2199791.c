#include <stdio.h>

int queue_point = 0;
int queue_size = 0;
int queue[8192];

void enqueue(int p) {
  queue[queue_size++] = p;
}
int dequeue() {
  if (queue_point >= queue_size) return -1;
  else return queue[queue_point++];
}

int stack[4] = {-1, 0, 0, 0};
int stack_pointer = 0;
void push(int p) {
  stack[stack_pointer++] = p;
}
int pop() {
  return stack[--stack_pointer];
}

// ?????????????????????????????
int main() {
  int i, j;
  int H, W;
  int p, goal, distance = 0;
  char S[50][51];
  int visited[50][50];
  int white = 0;

  scanf("%d %d", &H, &W);
  goal = H*W-1;
  for (i = 0; i < H; i++) {
    scanf("%s", S[i]);
    for (j = 0; j < W; j++) {
      if (S[i][j] == '.') {
        visited[i][j] = 0;
        white++;
      }
      else visited[i][j] = 1;
    }
  }

  int n = 0;

  // ?????
  enqueue(0);
  while ((n = queue_size - queue_point) > 0) {
    distance++;
    while (n--) {
      p = dequeue();
      if (p == goal) goto end;
      i = p / W;
      j = p - W*i;
      visited[i][j] = 1;
      if (i > 0   && !visited[i-1][j]) {
        enqueue(W*(i-1)+j);
        visited[i-1][j] = 1;
      }
      if (i < H-1 && !visited[i+1][j]) {
        enqueue(W*(i+1)+j);
        visited[i+1][j] = 1;
      }
      if (j > 0   && !visited[i][j-1]) {
        enqueue(W*i+j-1);
        visited[i][j-1] = 1;
      }
      if (j < W-1 && !visited[i][j+1]) {
        enqueue(W*i+j+1);
        visited[i][j+1] = 1;
      }
    }
  }

end:
  if (distance < H+W-1) {
    puts("-1");
  } else {
    printf("%d\n", white - distance);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S[i]);
     ^