#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define EMPTY 0
#define FULL 1
#define DELETED 2
 
#define INF 1000000000
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct {
	long key;
	int flag;
} Data;

long H, W, N;
long a[100001];
long b[100001];
Data map[5678920] = {0};
int state_map[5678920] = {0};
Data taboo[5678920];
int state_taboo[5678920] = {0};
long ans[10] = {0};
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};


long hash(long key, long count) {
	return (key + count) % 5678912;
}

void insert_map(long key) {
	int i, k;
	
	i = 0;
	k = hash(key, i++);
	while(state_map[k] == FULL) {
		k = hash(key, i++);
	}
	
	map[k].key = key;
	map[k].flag = 1;
	state_map[k] = FULL;
}

int search_map(long key) {
	int i, k;
	
	i = 0;
	k = hash(key, i++);
	while(state_map[k] != EMPTY) {
		if(state_map[k] == FULL && map[k].key == key) {
			return map[k].flag;
		}
		k = hash(key, i++);
	}
	
	return 0;
}

void insert_taboo(long key) {
	int i, k;
	
	i = 0;
	k = hash(key, i++);
	while(state_taboo[k] == FULL) {
		k = hash(key, i++);
	}
	
	taboo[k].key = key;
	taboo[k].flag = 1;
	state_taboo[k] = FULL;
}

long search_taboo(long key) {
	int i, k;
	
	i = 0;
	k = hash(key, i++);
	while(state_taboo[k] != EMPTY) {
		if(state_taboo[k] == FULL && taboo[k].key == key) {
			return taboo[k].flag;
		}
		k = hash(key, i++);
	}
	
	return 0;
}

int main() {
	int i, j, k, x, y, xx, yy, ii, jj;
	int count;
	long sum;
	
	scanf("%ld %ld %ld", &H, &W, &N);
	for(i=0;i<N;i++) {
		scanf("%ld %ld", &a[i], &b[i]);
		insert_map(a[i] * W + b[i]);
	}
	
	for(k=0;k<N;k++) {
		yy = a[k];
		xx = b[k];
		for(i=0;i<3;i++) {
			for(j=0;j<3;j++) {
				y = yy + dy[i];
				x = xx + dx[j];
				
				if(search_taboo(y * W + x)) continue;
				if(y <= 1 || y >= H || x <= 1 || x >= W) continue;
			
				insert_taboo(y * W + x);
				count = 0;
				for(ii=0;ii<3;ii++) {
					for(jj=0;jj<3;jj++) {
						if(search_map((y+dy[ii]) * W + (x+dx[jj]))) {
							count++;
						}
					}
				}
				ans[count]++;
			}
		}
	}

	sum = 0;
	for(i=1;i<=9;i++) {
		sum += ans[i];
	}
	
	ans[0] = (H * W) - (2 * H + 2 * W) + 4 - sum;

	for(i=0;i<=9;i++) {
		printf("%ld\n", ans[i]);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:99:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld %ld", &H, &W, &N);
  ^
./Main.c:101:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &a[i], &b[i]);
   ^