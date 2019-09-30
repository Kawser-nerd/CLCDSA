#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <gmp.h>

#ifdef DEBUG_ON
#define DEBUG if (1) 
#else
#define DEBUG if (0) 
#endif

typedef unsigned int uint32;
typedef unsigned char uint8;

#define MAX_N (101*4)
typedef char board_t[MAX_N][MAX_N];
void
dump_board(board_t *board, int N) {
  int r, maxrow, c, maxcol;
  maxcol = maxrow = N;
  for (r=0;r<maxrow;r++) {
    for (c=0;c<maxcol;c++) {
      if ((*board)[r][c]) {
	printf ("1");
      } else {
	printf ("0");
      }
    }
    printf("\n");
  }
}

void parse_array (char *s, uint32 *out, uint32 N) {
  uint32 n;
  char *token;
  char *sp1;
  for (n = 0; n < N; n++, s = NULL) {
    token = strtok_r(s," ", &sp1);
    out[n] = atoi(token);
    assert (token != NULL);
  }
}

#define MAXBUF (4096)

typedef struct {
  uint32 A;
  uint32 B;
} wire_t;


int main (int argc, char *argv[]) {
  wire_t *wire;
  mpz_t bigint;

  uint32 NUM_CASE, cur_case;
  uint32 N,n;

  uint32 A, B;
  uint32 i, j;
  uint32 total;
  
  FILE *FD;
  char buf[MAXBUF];
  char tbuf[MAXBUF];

  char *token;
  char *sp1, *parse;
  uint32 out[MAXBUF];

  board_t board1;
  board_t board2;

  board_t *cur_board;
  board_t *next_board;
  board_t *t_board;

  uint32 x, y, has_b;
  uint32 round;
  uint32 x1,y1,x2,y2;

  FD = fopen(argv[1],"r");
  if (!FD) {
    printf ("cannot open %s\n",argv[1]);
  }

  if (fgets(buf,MAXBUF,FD) == NULL) {
    assert(0);
  }

  sscanf(buf, "%u", &NUM_CASE);
  
  for (cur_case = 1; cur_case <= NUM_CASE; cur_case++) {
    printf ("Case #%d: ",cur_case);
    if (fgets(buf,MAXBUF,FD)==NULL) {
      assert(0);
    }
    sscanf(buf, "%u", &N);

    memset(board1,0,sizeof(board1));
    memset(board2,0,sizeof(board2));
    has_b = 0;
    for (n = 0; n < N; n++) {
      if (fgets(buf,MAXBUF,FD)==NULL) {
	assert(0);
      }
      sscanf(buf, "%u %u %u %u", &x1, &y1, &x2, &y2);

      for(y=y1; y<= y2; y++) {
	for (x=x1; x<=x2;x++) {
	  board1[y][x] = 1;
	  has_b = 1;
	}
      }
    }

    cur_board = &board1;
    next_board = &board2;
    round = 0;
    while (1) {
DEBUG    printf("\n");
DEBUG      dump_board(cur_board,MAX_N);
      if (has_b) {
	round++;
      } else {
	break;
      }
      has_b = 0;
      for (y=0;y< MAX_N;y++) {
	for (x=0;x< MAX_N;x++) {
	  if ((*cur_board)[y][x]) {
	    if ((y==0) || (x == 0)) {
	      (*next_board)[y][x] = 0;
	    } else {
	      if (((*cur_board)[y-1][x] == 0) && 
		  ((*cur_board)[y][x-1] == 0)) {
		(*next_board)[y][x] = 0;
	      } else {
		(*next_board)[y][x] = 1;
		has_b = 1;
	      }
	    }
	  } else {
	    if ((y==0) || (x == 0)) {
		(*next_board)[y][x] = 0;
	    } else {
	      if (((*cur_board)[y-1][x] == 1) && 
		  ((*cur_board)[y][x-1] == 1)) {
		(*next_board)[y][x] = 1;
		has_b = 1;
	      } else {
		(*next_board)[y][x] = 0;
	      }
	    }
	  }
	}
      }
      t_board = cur_board;
      cur_board = next_board;
      next_board = t_board;
    }
    printf ("%d\n",round);
  }
}
