#include <cstdio>

int world[1002][1002];
int my_count[1001][1001];

int check_neighbor(int, int);

int main(void){
	int h, w;
    scanf("%d", &h);
    scanf("%d", &w);

	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
				world[i][j] = 0;
			} else {
                scanf("%d", &world[i][j]);
			}
		}
	}

	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++) {
			my_count[i][j] = 0;
		}
	}

	int sum = 0;
	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			sum += check_neighbor(y, x);
			sum %= 1000000007;
		}
	}
    printf("%d\n", sum);

	return 0;
}

int check_neighbor(int y, int x) {
	if (my_count[y][x] == 0) {
		my_count[y][x] = 1;
		if (world[y][x] < world[y + 1][x]) {
			my_count[y][x] += (check_neighbor(y + 1, x) % 1000000007);
            my_count[y][x] %= 1000000007;
		}
		if (world[y][x] < world[y - 1][x]) {
			my_count[y][x] += (check_neighbor(y - 1, x) % 1000000007);
            my_count[y][x] %= 1000000007;
		}
		if (world[y][x] < world[y][x + 1]) {
			my_count[y][x] += (check_neighbor(y, x + 1) % 1000000007);
            my_count[y][x] %= 1000000007;
		}
		if (world[y][x] < world[y][x - 1]) {
			my_count[y][x] += (check_neighbor(y, x - 1) % 1000000007);
            my_count[y][x] %= 1000000007;
		}
	}
	return my_count[y][x];
}