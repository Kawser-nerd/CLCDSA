#include <stdio.h>
#include <string.h>
#include <stdint.h>

int N;

#define PMAP_PLUS	1
#define PMAP_X		2
#define PMAP_O		4

char baseMap[100][100];
char maxMap[100][100];
int maxScore = 0;

void printMap(char map[100][100])
{
	int x, y;
	printf("MAP:\n");
	for(y = 0; y < N; y++){
		for(x = 0; x < N; x++){
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
}

int genPotentialMap(const char map[100][100], char pMap[100][100])
{
	// 次に遷移可能な状態をすべてのマスについて調べる。
	// 合法な状態から一つ削除することは常に可能
	int x, y, f, p, q;
	/*
	for(y = 0; y < N; y++){
		for(x = 0; x < N; x++){
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
	*/
	// init
	for(y = 0; y < N; y++){
		for(x = 0; x < N; x++){
				pMap[y][x] = PMAP_PLUS | PMAP_X | PMAP_O;
		}
	}
	// check x
	for(y = 0; y < N; y++){
		f = 0;
		for(x = 0; x < N; x++){
//printf("%c", map[y][x]);
			if(map[y][x] != ' '){
				if(map[y][x] != '+') f++;
			}
		}
//printf("|\n");
		if(f >= 2) return 1;	// violated
		if(f != 0){
			for(x = 0; x < N; x++){
				if(map[y][x] == ' ' || map[y][x] == '+'){
					pMap[y][x] &= PMAP_PLUS;
				}
			}
		}

	}
	// check y
	for(x = 0; x < N; x++){
		f = 0;
		for(y = 0; y < N; y++){
//printf("%c", map[y][x]);
			if(map[y][x] != ' '){
				if(map[y][x] != '+') f++;
			}
		}
//printf("|\n");
		if(f >= 2) return 1;	// violated
		if(f != 0){
			for(y = 0; y < N; y++){
				if(map[y][x] == ' ' || map[y][x] == '+'){
					pMap[y][x] &= PMAP_PLUS;
				}
			}
		}

	}
	// sum = const 
//printf("Sum const check:\n");
	for(p = 0; p <= (N - 1) * 2; p++){
		f = 0;
		// 和がpとなるxyのペア
		for(q = 0; q < N; q++){
			if(p-q < 0 || N <= p-q) continue;
//printf("%c", map[q][p-q]);
			if(map[q][p-q] != ' '){
				if(map[q][p-q] != 'x') f++;
			}
		}
//printf("|\n");
		//
		if(f >= 2) return 1;	// violated
		if(f != 0){
			for(q = 0; q < N; q++){
				if(p-q < 0 || N <= p-q) continue;
				if(map[q][p-q] == ' ' || map[q][p-q] == 'x'){
					pMap[q][p-q] &= PMAP_X;
				}
			}
		}
	}
	// diff = const 
//printf("Diff const check:\n");
	for(p = -(N-1); p <=(N-1); p++){
		f = 0;
		for(q = 0; q < N; q++){
			if(p+q < 0 || N <= p+q) continue;
//printf("%c", map[q][p+q]);
			if(map[q][p+q] != ' '){
				if(map[q][p+q] != 'x') f++;
			}
		}
//printf("|\n");
		//
		if(f >= 2) return 1;	// violated
		if(f != 0){
			for(q = 0; q < N; q++){
				if(p+q < 0 || N <= p+q) continue;
				if(map[q][p+q] == ' ' || map[q][p+q] == 'x'){
					pMap[q][p+q] &= PMAP_X;
				}
			}
		}
	}
/*
	printf("PMAP:\n");
	for(y = 0; y < N; y++){
		for(x = 0; x < N; x++){
			printf("%d ", pMap[y][x]);
		}
		printf("\n");
	}
*/	
	return 0;
}

int mkPMapDiff(const char basePMap[100][100], char nextPMap[100][100], char map[100][100], int px, int py)
{
	int x, y, p, q;
	char c = map[py][px];
	//
	memcpy(nextPMap, basePMap, 100 * 100);
	//
	if(c != '+'){
		// 同一行もしくは列に、+以外の記号は一つしか出現できない。
		for(x = 0; x < N; x++){
			nextPMap[py][x] &= PMAP_PLUS;
		}
		for(y = 0; y < N; y++){
			nextPMap[y][px] &= PMAP_PLUS;
		}
	}
	if(c != 'x'){
		// 同一対角線上に、x以外の記号は一つしか出現できない。
		p = px + py;	// 和がp
		for(q = 0; q < N; q++){
			if(p-q < 0 || N <= p-q) continue;
			nextPMap[q][p-q] &= PMAP_X;
		}
		//
		p = px - py;	// 差がp
		for(q = 0; q < N; q++){
			if(p+q < 0 || N <= p+q) continue;
			nextPMap[q][p+q] &= PMAP_X;
		}
	}
	return 0;
}

int check(const char parent[100][100], char pMap[100][100], int x, int y);

int tryMod(char map[100][100], char pMap[100][100], int tx, int ty, char c)
{
	/*
int x, y;
printf("PMAP:\n");
for(y = 0; y < N; y++){
	for(x = 0; x < N; x++){
		printf("%d ", pMap[y][x]);
	}
	printf("\n");
}
printf("(%d, %d) <= %c (%d)\n", tx, ty, c, pMap[ty][tx]);
*/
	char tmp;
	char nextPMap[100][100];
	tmp = map[ty][tx];
	map[ty][tx] = c;
	//
	mkPMapDiff(pMap, nextPMap, map, tx, ty);
	check(map, nextPMap, tx, ty);
	//
	map[ty][tx] = tmp;
	return 1;
}

int calcScore(char map[100][100])
{
	int c = 0;
	int x, y;
	for(y = 0; y < N; y++){
		for(x = 0; x < N; x++){
			if(map[y][x] == 'o') c += 2;
			else if(map[y][x] != ' ') c += 1;
		}
	}
	return c;
}

int check(const char parent[100][100], char pMap[100][100], int bx, int by)
{
	char map[100][100];
	int x, y, modified = 0;
	//
	memcpy(map, parent, 100 * 100);
	y = by;
	x = bx + 1;
	for(; y < N; y++){
		for(; x < N; x++){
			/*
			if(parent == baseMap){
				printf("(%d, %d)\n", x, y);
			}
			*/
			if(pMap[y][x] && parent[y][x] != 'o'){
				if(parent[y][x] == ' '){
					if(pMap[y][x] & PMAP_PLUS)	modified |= tryMod(map, pMap, x, y, '+');
					if(pMap[y][x] & PMAP_X)		modified |= tryMod(map, pMap, x, y, 'x');
				}
				if(pMap[y][x] & PMAP_O)		modified |= tryMod(map, pMap, x, y, 'o');
			}
		}
		x = 0;
	}
	if(!modified){
		int score = calcScore(map);
// printf(">%d\n", score);
		if(score > maxScore){
			maxScore = score;
			memcpy(maxMap, map, 100 * 100);
/*			
			printf("Score updated: %d\n", score);
			for(y = 0; y < N; y++){
				for(x = 0; x < N; x++){
					printf("%c ", map[y][x]);
				}
				printf("\n");
			}
*/			
		}
	}
	return 0;
}

void printOutput(int idx)
{
	char modList[1000][3];
	int modCount = 0;
	int x, y;
	for(y = 0; y < N; y++){
		for(x = 0; x < N; x++){
			if(baseMap[y][x] != maxMap[y][x]){
				modList[modCount][0] = maxMap[y][x];
				modList[modCount][1] = y + 1;
				modList[modCount][2] = x + 1;
				modCount++;
			}
		}
	}

	printf("Case #%d: %d %d\n", idx + 1, calcScore(maxMap), modCount);
	for(y = 0; y < modCount; y++){
		printf("%c %d %d\n", modList[y][0], modList[y][1], modList[y][2]);
	}
}

void smallSolver(int idx)
{
	int x;
	//maxScore = score;
	// oの位置を決定
	memcpy(maxMap, baseMap, 100 * 100);
	for(x = 0; x < N; x++){
		if(maxMap[0][x] == 'o'){
			// oが見つかればそれを使う
			break;
		}
	}
	if(x >= N){
		for(x = 0; x < N; x++){
			if(maxMap[0][x] == 'x'){
				// xが見つかればoにする
				maxMap[0][x] = 'o';
				break;
			}
		}
	}
	if(x >= N){
		// oが見つからなかったなら左上をoにしてしまう
		maxMap[0][0] = 'o';
	}
	// 1行目のo以外を+で埋める
	for(x = 0; x < N; x++){
		if(maxMap[0][x] == 'o') continue;
		maxMap[0][x] = '+';
	}
	// ナナメでoの直下以外をxで埋める
	int y;
	x = 0;
	for(y = 1; y < N; y++){
		if(maxMap[0][x] == 'o') x++;
		maxMap[y][x] = 'x';
		x++;
	}
	// 一番下の行の左端以外を+で埋める
	for(x = 1; x < N; x++){
		if(maxMap[N - 1][x] != ' ') continue;
		maxMap[N - 1][x] = '+';
	}
}

int main(int argc, char *argv[])
{
	int T, M;
	int i, k, x, y;
	char c;
	char pMap[100][100];
	//
	scanf("%d ", &T);
	for(i = 0; i < T; i++){
		maxScore = 0;
		scanf("%d %d ", &N, &M);
		
		for(y = 0; y < N; y++){
			for(x = 0; x < N; x++){
				baseMap[y][x] = ' ';
			}
		}
		for(k = 0; k < M; k++){
			scanf("%c %d %d ", &c, &y, &x);
			x--;
			y--;
			baseMap[y][x] = c;
		}
	/*	
		genPotentialMap(baseMap, pMap);
//printf("CHECK BEGUN\n");
		check(baseMap, pMap, -1, 0);
	*/	
		smallSolver(i);
		printOutput(i);
		/*
		printMap(baseMap);
		printMap(maxMap);
		*/
	}
	return 0;
}
