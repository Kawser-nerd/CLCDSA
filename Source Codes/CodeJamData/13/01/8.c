#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main( int argc, char ** argv, char ** envp ) {
int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
char * Mem = malloc(Size);
lseek(File, 0, SEEK_SET);
read(File, Mem, Size);
close(File);
unsigned int q = 0;
while ( q < Size ) {
	if ( Mem[q] == 0x0a ) { Mem[q] = 0x00; }
	if ( Mem[q] == 0x20 ) { Mem[q] = 0x00; }
	q++;
}
unsigned int Cases = atoi(Mem);
q = strlen(Mem) + 1;
fprintf(stderr, "Cases: %u\n", Cases);
unsigned int Case_T = 0;


char b[4*4];

int x;

while ( Case_T < Cases ) {
/* --------------------- */
	if ( Case_T > 0 ) { q ++; }

	for ( x = 0; x < 4; x ++ ) {
		b[(4*x) + 0 ] = Mem[q + 0];
		b[(4*x) + 1 ] = Mem[q + 1];
		b[(4*x) + 2 ] = Mem[q + 2];
		b[(4*x) + 3 ] = Mem[q + 3];
		q += ( strlen(Mem + q) + 1 );
	}

	int xwon = 0;
	int owon = 0;
	int freespace = 0;


	int y;
	for ( x = 0; x < 4; x ++ ) {
		for ( y = 0; y < 4; y ++ ) {
			if ( b[(4*x) + y] == '.' ) { freespace = 1; }
		}
	}

	char m;

	for ( x = 0; x < 4; x ++ ) {
		m = 'X';
		if (
			((b[(4*x) + 0] == m ) || (b[(4*x) + 0] == 'T' ))
		&&	((b[(4*x) + 1] == m ) || (b[(4*x) + 1] == 'T' ))
		&&	((b[(4*x) + 2] == m ) || (b[(4*x) + 2] == 'T' ))
		&&	((b[(4*x) + 3] == m ) || (b[(4*x) + 3] == 'T' ))
		) {
			xwon = 1;
		}

		m = 'O';
		if (
			((b[(4*x) + 0] == m ) || (b[(4*x) + 0] == 'T' ))
		&&	((b[(4*x) + 1] == m ) || (b[(4*x) + 1] == 'T' ))
		&&	((b[(4*x) + 2] == m ) || (b[(4*x) + 2] == 'T' ))
		&&	((b[(4*x) + 3] == m ) || (b[(4*x) + 3] == 'T' ))
		) {
			owon = 1;
		}
	}


	for ( x = 0; x < 4; x ++ ) {
		m = 'X';
		if (
			((b[(4*0) + x] == m ) || (b[(4*0) + x] == 'T' ))
		&&	((b[(4*1) + x] == m ) || (b[(4*1) + x] == 'T' ))
		&&	((b[(4*2) + x] == m ) || (b[(4*2) + x] == 'T' ))
		&&	((b[(4*3) + x] == m ) || (b[(4*3) + x] == 'T' ))
		) {
			xwon = 1;
		}

		m = 'O';
		if (
			((b[(4*0) + x] == m ) || (b[(4*0) + x] == 'T' ))
		&&	((b[(4*1) + x] == m ) || (b[(4*1) + x] == 'T' ))
		&&	((b[(4*2) + x] == m ) || (b[(4*2) + x] == 'T' ))
		&&	((b[(4*3) + x] == m ) || (b[(4*3) + x] == 'T' ))
		) {
			owon = 1;
		}
	}


	m = 'X';
	if (
		((b[(4*0) + 0] == m ) || (b[(4*0) + 0] == 'T' ))
	&&	((b[(4*1) + 1] == m ) || (b[(4*1) + 1] == 'T' ))
	&&	((b[(4*2) + 2] == m ) || (b[(4*2) + 2] == 'T' ))
	&&	((b[(4*3) + 3] == m ) || (b[(4*3) + 3] == 'T' ))
	) {
		xwon = 1;
	}

	m = 'O';
	if (
		((b[(4*0) + 0] == m ) || (b[(4*0) + 0] == 'T' ))
	&&	((b[(4*1) + 1] == m ) || (b[(4*1) + 1] == 'T' ))
	&&	((b[(4*2) + 2] == m ) || (b[(4*2) + 2] == 'T' ))
	&&	((b[(4*3) + 3] == m ) || (b[(4*3) + 3] == 'T' ))
	) {
		owon = 1;
	}


	m = 'X';
	if (
		((b[(4*3) + 0] == m ) || (b[(4*3) + 0] == 'T' ))
	&&	((b[(4*2) + 1] == m ) || (b[(4*2) + 1] == 'T' ))
	&&	((b[(4*1) + 2] == m ) || (b[(4*1) + 2] == 'T' ))
	&&	((b[(4*0) + 3] == m ) || (b[(4*0) + 3] == 'T' ))
	) {
		xwon = 1;
	}


	m = 'O';
	if (
		((b[(4*3) + 0] == m ) || (b[(4*3) + 0] == 'T' ))
	&&	((b[(4*2) + 1] == m ) || (b[(4*2) + 1] == 'T' ))
	&&	((b[(4*1) + 2] == m ) || (b[(4*1) + 2] == 'T' ))
	&&	((b[(4*0) + 3] == m ) || (b[(4*0) + 3] == 'T' ))
	) {
		owon = 1;
	}


	if ( xwon ) {
		printf("Case #%u: X won\n", Case_T + 1 );
	} else if ( owon ) {
		printf("Case #%u: O won\n", Case_T + 1 );
	} else if ( freespace ) {
		printf("Case #%u: Game has not completed\n", Case_T + 1 );
	} else {
		printf("Case #%u: Draw\n", Case_T + 1 );
	}

	Case_T ++;
/* --------------------- */
}

return 0;
}
