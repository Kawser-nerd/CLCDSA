#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIDE 100 // Height and Width
#define MAX_ALTITUDE 10000

#define NORTH 0
#define WEST 1
#define EAST 2
#define SOUTH 3
#define X 0
#define Y 1

typedef struct _Cell {
	int altitude;
	char label;
	int mark;
} Cell;

typedef struct _Coordinate {
	int row, column;
} Coordinate;

int DIRECT[4][2]; 

int H, W;
Cell map[MAX_SIDE][MAX_SIDE];

inline int isCoordValid(int i, int j) {
	return ( (i >= 0) && (i < H) && (j >= 0) && (j < W) );
}

inline int isMarked(int i, int j) {
	return (map[i][j].mark > 0);
}

inline int nextInt() {
	static int result;
	scanf("%d", &result);
	return result;
}

void init_data() {
	DIRECT[NORTH][X] = 0;
	DIRECT[NORTH][Y] = -1;
	
	DIRECT[WEST][X] = -1;
	DIRECT[WEST][Y] = 0;
	
	DIRECT[EAST][X] = 1;
	DIRECT[EAST][Y] = 0;
	
	DIRECT[SOUTH][X] = 0;
	DIRECT[SOUTH][Y] = 1;
}

void read_data() {
	int i, j;
	
	memset(map, 0, sizeof(map));
	
	H = nextInt(); W = nextInt();
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			map[i][j].altitude = nextInt();
		}
	}
}

void print_data(int caseId) {
	int i, j;
	
	printf("Case #%d:\n", caseId);
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			printf("%c", map[i][j].label);
			if (j < W-1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int checkAllMark() {
	int i, j;
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			if ( !isMarked(i, j) ) {
				return 0;
			}
		}
	}
	
	return 1;
}

Coordinate nextHighestCell() {
	Coordinate result;
	int i, j, max = -1;
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			if ( !isMarked(i, j) ) {
				if (map[i][j].altitude > max) {
					result.row = i;
					result.column = j;
					max = map[i][j].altitude;
				}
			}
		}
	}
	
	return result;
}

void renewMark(int oldValue, int newValue) {
	int i, j;
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			if (map[i][j].mark == oldValue) {
				map[i][j].mark = newValue;
			}
		}
	}
	
	return;
}

void waterFlow(Coordinate coord, int mark) {
	int i, x, y, min, min_dir;
	
	// Flow!
	do {
		// Color itself
		map[coord.row][coord.column].mark = mark;
		
		min = map[coord.row][coord.column].altitude;
		min_dir = -1;
		
		// Select a flowing direction
		for (i=0; i<4; i++) {
			x = coord.column + DIRECT[i][X];
			y = coord.row + DIRECT[i][Y];
			
			if ( !isCoordValid(y, x) ) {
				continue;
			}
			
			if ( map[y][x].altitude < min) {
				min = map[y][x].altitude;
				min_dir = i;
			}
		}
		
		if (min_dir == -1) {
			// Lowest
			break;
		}
		
		// Coordinate of next position
		coord.column += DIRECT[min_dir][X];
		coord.row += DIRECT[min_dir][Y]; 
		
		if ( isMarked(coord.row, coord.column) ) {
			// Reset value of filled area;
			renewMark(map[coord.row][coord.column].mark, mark);
			break;
		}
	} while (1);
}

void solve() {
	Coordinate coord;
	int currentMark = 0;
	
	while ( !checkAllMark() ) {
		coord = nextHighestCell();
		waterFlow(coord, ++currentMark);
	}
}

void setLabel(int mark, char label) {
	int i, j;
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			if (map[i][j].mark == mark) {
				map[i][j].label = label;
			}
		}
	}
}

void replot() {
	int i, j;
	char l = 'a';
	
	for (i=0; i<H; i++) {
		for (j=0; j<W; j++) {
			if (map[i][j].label == 0) {
				setLabel(map[i][j].mark, l++);
			} 
		}
	}
}

int main() {
	int i, test_cases;
	
	init_data();
	
	test_cases = nextInt();
	
	for (i=1; i<=test_cases; i++) {
		read_data();
		solve();
		replot();
		print_data(i);
	}
	
	return 0;
}
