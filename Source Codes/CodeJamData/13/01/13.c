#include <stdio.h>
char G[4][4];

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out","w", stdout);
	int i, j, T, tst = 0; 
  char ch;

	scanf("%d", &T);
  scanf("%c", &ch);
	while (T--) {
    
    char nx = 0;
    char no = 0;
    char wx = 0;
    char wo = 0;
    char t = 0;
    char apoint = 0;

    for (i = 0; i < 4; ++i) {
      for (j = 0; j < 4; ++j) {
        scanf("%c", &G[i][j]);
        if (G[i][j] == '.') ++apoint;
        fprintf(stderr, "%c", G[i][j]);
      } 
      scanf("%c", &ch);
		  fprintf(stderr, "\n");
    }
    
    // diagonal check
    nx = 0; no = 0; t = 0;
    for (i = 0; i < 4 && !wx && !wo; ++i) {    
      if (G[i][i] == 'T') ++t;
      else if (G[i][i] == 'X') ++nx;    
      else if (G[i][i] == 'O') ++no;    
    }
    if (nx + t == 4) wx = 1;
    else if (no + t == 4) wo = 1;
    
    // the 2nd diagonal check
    if (!wx && !wo) {
      nx = 0; no = 0; t = 0;
      for (i = 0; i < 4; ++i) {    
        if (G[3-i][i] == 'T') ++t;
        else if (G[3-i][i] == 'X') ++nx;    
        else if (G[3-i][i] == 'O') ++no;    
      }
      if (nx + t == 4) wx = 1;
      else if (no + t == 4) wo = 1;
    }
    
    // horizontal check
    for (i = 0; i < 4 && !wx && !wo; ++i) {
      nx = 0; no = 0; t = 0;
      for (j = 0; j < 4; ++j) {
        if (G[i][j] == 'T') ++t;
        else if (G[i][j] == 'X') ++nx;    
        else if (G[i][j] == 'O') ++no;    
      }
      if (nx + t == 4) wx = 1;
      else if (no + t == 4) wo = 1;
    }

    // vertical check
    for (j = 0; j < 4 && !wx && !wo; ++j) {
      nx = 0; no = 0; t = 0;
      for (i = 0; i < 4; ++i) {
        if (G[i][j] == 'T') ++t;
        else if (G[i][j] == 'X') ++nx;    
        else if (G[i][j] == 'O') ++no;    
      }
      if (nx + t == 4) wx = 1;
      else if (no + t == 4) wo = 1;
    }
    
    if (!wx && !wo && apoint > 0)
      printf("Case #%d: Game has not completed\n", ++tst);   
    else if (!wx && !wo && apoint == 0)
      printf("Case #%d: Draw\n", ++tst);   
    else if (wx > 0)
      printf("Case #%d: X won\n", ++tst);   
    else if (wo > 0)
      printf("Case #%d: O won\n", ++tst);   
    
    if (T > 0) scanf("%c", &ch);
  }
	return 0;
}
