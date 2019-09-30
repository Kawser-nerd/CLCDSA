#include <stdio.h>
#include <assert.h>

/* python code input is first piped through to make reading bitmap easier:

#!/usr/bin/python

import sys

if __name__ == "__main__":
	cases = int(sys.stdin.readline())
	print cases
	for case in xrange(1,cases+1):
		M,N = map(int, sys.stdin.readline().strip().split())
		print M,N
		for i in xrange(M):
			line = sys.stdin.readline().strip();
			assert len(line) == N/4
			out = []
			for c in line:
				bm = int(c,16)
				a,b,c,d = 0,0,0,0
				if bm & 8: a = 1
				if bm & 4: b = 1
				if bm & 2: c = 1
				if bm & 1: d = 1
				out.extend([a,b,c,d])
			print " ".join(map(str,out))

*/
char board[512][512];

int nsizes;
int sizes[262144];
int ncut[262144];
int M; 
int N;

#define SENT	999999
#define GONE	'X'

int largest_grid(int i,int j) {
	int last; int size;
	last = board[i][j];
	if (last == GONE) return 0;
	size=1;

	while (1) {
		// See if we can grow it
		int bottomrow = i+size;
		int rightcolumn = j+size;
		if (bottomrow >=M) return size;
		if (rightcolumn >=N) return size;
		last = board[bottomrow-1][j];
		int k;
		for (k=j; k<=rightcolumn; k++) {
			int here = board[bottomrow][k];
			last = !last;
			if (here == GONE || here != last) return size;
		}
		for (k=bottomrow-1; k>=i; k--) {
			int here = board[k][rightcolumn];
			last = !last;
			if (here == GONE || here != last) return size;
		}
		// YAY!
		++size;
	}
	
	return 0;
	
}

void slice(int i, int j, int size) {
	int a; int b;
	for (a=i; a<i+size; ++a) {
		for (b=j; b<j+size; ++b) {
			board[a][b] = GONE;
		}
	}
}

void cut() {
	int lastbiggest = 0;
	int biggest = 0;
	int i; int j;
	int bigi; int bigj;
	bigi=-1; bigj=-1;

	while (1) {
		biggest = 0;
		for (i=0; i<M; ++i) {
			for (j=0; j<N; ++j) {
				int cake;
				cake = largest_grid(i,j);
				if (cake > biggest) {
					biggest = cake;
					bigi = i;
					bigj = j;
				}
			}
		}
		if (biggest == 0) 
			return; // Cake is a lie
		assert(bigi >= 0); 
		assert(bigj >= 0);
		slice(bigi,bigj,biggest);
		if (lastbiggest != biggest) {
			sizes[nsizes] = biggest;
			ncut[nsizes] = 0;
			nsizes++;
			lastbiggest = biggest;
		}
		ncut[nsizes-1] += 1;
	}
}

int main() {
	int casenums;
	int ret;

	ret = fscanf(stdin,"%d", &casenums); assert(ret == 1);

	int casenum;
	for (casenum = 1; casenum <= casenums; ++casenum) {
		ret = fscanf(stdin,"%d%d", &M, &N); assert(ret == 2); 

		int i; int j;
		int bbb;
		for (i=0; i<M; ++i) {
			for (j=0; j<N; ++j) {
				fscanf(stdin, "%d", &bbb);
				board[i][j] = bbb;
			}
		}

		nsizes = 0;
		cut();
		printf("Case #%d: %d\n", casenum,nsizes);
		for (i=0; i<nsizes; ++i) 
			printf("%d %d\n", sizes[i],ncut[i]);
	}
	
	return 0;
}
