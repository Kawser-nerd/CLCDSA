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

int m[4] = {2,3,4,5};

int p[64];

int ok[64];

int x = 0;
while ( x < 64 ) {
	p[x] = m[x/16] * m[(x/4) %4] * m[x%4];
	x ++;
}

int Kk;

int R,N,M,K;
while ( Case_T < Cases ) {
/* --------------------- */
	R   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	N   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	M   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	K   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

	printf("Case #%u:\n", Case_T + 1 );

	unsigned int R_T = 0;
	while ( R_T < R ) {
		x = 0;
		while ( x < 64 ) {
			ok[x] = 1;
			x ++;
		}

		int y;
		x = 0;
		while ( x < K ) {
			Kk = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
			y = 0;
			while ( y < 64 ) {
				if ( (p[y] % Kk) != 0 ) {
					ok[y] = 0;
				}
				y ++;
			}
			x ++;
		}

		x = 0;
		while ( x < 64 ) {
			if ( ok[x] ) {
				printf("%d%d%d\n", m[x/16],  m[(x/4) %4], m[x%4] );
				goto End;
			}
			x ++;
		}
		printf("234\n");
		End:

		R_T ++;
	}

	Case_T ++;
/* --------------------- */
}

return 0;
}
