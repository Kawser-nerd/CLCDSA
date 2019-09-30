#include <stdio.h>

#define NMAX 51
#define BLUE 'B'
#define RED 'R'
#define BLANK '.'

char b[NMAX][NMAX];

int main()
{
	int i, j, l, t, n, k, caso, next;
	int h, v, ds, da, rd, bl;
	char c;
	
	scanf("%d", &t);
	for (caso = 1; caso <= t; caso++){
		rd = bl = 0;
		scanf("%d%d", &n, &k);
		for (i = 0; i < n; i ++){
			scanf("%s", b[i]);
			next = n-1;
			for (j = n-1; j >= 0; j--){
			/*printf("%d ", next);*/
				if (b[i][j] != BLANK){
					b[i][next] = b[i][j];
					if (next != j)
						b[i][j] = BLANK;
					next--;
				}
			/*printf("%c ", b[i][next]);*/
			}
			/*putchar('\n');*/
			/*printf("%s\n", b[i]);*/
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if ((c = b[i][j]) != BLANK){
					h = 1;
					for (l = j-1; l >= 0 && b[i][l] == c; l--)
						h++;						;
					for (l = j+1; l < n && b[i][l] == c; l++)
						h++;
					
					v = 1;
					for (l = i-1; l >= 0 && b[l][j] == c; l--)
						v++;						;
					for (l = i+1; l < n && b[l][j] == c; l++)
						v++;
					
					ds = 1;
					for (l = -1; i+l >= 0 && j+l >= 0 && b[i+l][j+l] == c; l--)
						ds++;						;
					for (l = 1; i+l < n && j+l < n && b[i+l][j+l] == c; l++)
						ds++;
						
					da = 1;
					for (l = -1; i+l >= 0 && j-l < n && b[i+l][j-l] == c; l--)
						da++;						;
					for (l = 1; i+l < n && j-l >= 0 && b[i+l][j-l] == c; l++)
						da++;
						
					if (h >= k || v >= k || ds >= k || da >= k){
						/*printf("(%d,%d)(%d, %d, %d)\n", i, j, h, v, ds);*/
						if (c == RED)
							rd = 1;
						else
							bl = 1;
					}
				}
			}
		}
		if (rd == 1){
			if (bl == 1)
				printf("Case #%d: Both\n", caso);
			else
				printf("Case #%d: Red\n", caso);
		}
		else{
			if (bl == 1)
				printf("Case #%d: Blue\n", caso);
			else
				printf("Case #%d: Neither\n", caso);
		}
	}

	return 0;
}

