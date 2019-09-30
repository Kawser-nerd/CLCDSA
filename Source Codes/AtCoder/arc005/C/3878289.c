#include <stdio.h>

static char map[260000];
static int visited[260000];
static int queue[3][260000][2];
int queuePtr[] = {0, 0, 0};
int queuePtrEnd[] = {0, 0, 0};
static int res[2];

void enqueue(int num, int x, int y) {
	queue[num][queuePtrEnd[num]][0] = x;
	queue[num][queuePtrEnd[num]][1] = y;
	queuePtrEnd[num] += 1;
}

int *dequeue(int num) {
	res[0] = queue[num][queuePtr[num]][0];
	res[1] = queue[num][queuePtr[num]][1];
	queuePtr[num] += 1;
	return res;
}

int main() {
	int br = 0;
	int arr[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
	int height, width, startX, startY;
	int goal = 0;

	scanf("%d %d", &height, &width);
	for (int i = 0; i < height; i++) {
		scanf("%s", map + i*width);
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			visited[j * width + i] = 0;
			if (map[j * width + i] == 's') {
				// queue[0][0][0] = i;
				// queue[0][0][1] = j;
				// queuePtrEnd[0] += 1;
				enqueue(0, i, j);
				visited[j * width + i] = 1;
			}
		}
	}

	while (br <= 2) {
		if (queuePtr[br] == queuePtrEnd[br]) {
			br++;
		} else {
			int* pos = dequeue(br);
			// int posX = queue[br][queuePtr[br]][0];
			// int posY = queue[br][queuePtr[br]][1];
			// queuePtr[br] += 1;

			if (map[pos[1] * width + pos[0]] == 'g') {
				goal = 1;
				break;
			} else {
				for (int i = 0; i < 4; i++) {
					int curX = pos[0] + arr[i][0];
					int curY = pos[1] + arr[i][1];
					if ((curX >= 0) && (curX < width) && (curY >= 0) && (curY < height)) {
						int nextBr = br + (map[curY*width + curX] == '#' ? 1 : 0);
						if (visited[curY*width + curX] == 0 && nextBr <= 2) {
							// printf("%d, %d, %d\n", curX, curY, nextBr);
							visited[curY*width + curX] = 1;
							// queue[nextBr][queuePtrEnd[nextBr]][0] = curX;
							// queue[nextBr][queuePtrEnd[nextBr]][1] = curY;
							// queuePtrEnd[nextBr] += 1;
							enqueue(nextBr, curX, curY);
						}
					}
				}
			}
		}
	}
	printf("%s\n", goal ? "YES" : "NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &height, &width);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", map + i*width);
   ^