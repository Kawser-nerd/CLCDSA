#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main( int argc, char ** argv, char ** envp ) {

int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
unsigned char * Mem = malloc(Size);
lseek(File, 0, SEEK_SET);
read(File, Mem, Size);
close(File);

unsigned int x = 0;
while ( x < Size ) {
	if ( Mem[x] == 0x0a ) { Mem[x] = 0x00; }
	if ( Mem[x] == 0x20 ) { Mem[x] = 0x00; }
	x++;
}

unsigned int Cases = atoi(Mem);
x = strlen(Mem) + 1;

fprintf(stderr, "Cases: %u\n", Cases);


unsigned int C;
unsigned int D;
unsigned int N;

unsigned char Cdel[256 * 256];
unsigned char Ddel[256 * 256];

unsigned char Dels[256];

unsigned int qx;
unsigned int qy;

unsigned char List[101];
unsigned int Length;

unsigned char Exists[256];

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	C = atoi(Mem + x ); x += ( strlen(Mem + x) + 1 );

	bzero(Cdel, 256*256);
	qx = 0;
	while ( qx < C ) {
		Cdel[ (Mem[x]  *256) + Mem[x + 1] ] = Mem[x + 2];
		Cdel[ (Mem[x + 1]  *256) + Mem[x] ] = Mem[x + 2];
		x += ( strlen(Mem + x) + 1 );
		qx ++;
	}

	D = atoi(Mem + x ); x += ( strlen(Mem + x) + 1 );
	bzero(Ddel, 256*256);
	bzero(Dels, 256);
	qx = 0;
	while ( qx < D ) {
		Ddel[ (Mem[x]  *256) +  Dels[Mem[x  ]] ] = Mem[x+1];
		Ddel[ (Mem[x+1]*256) +  Dels[Mem[x+1]] ] = Mem[x];
		Dels[Mem[x]] ++;
		Dels[Mem[x+1]] ++;
		x += ( strlen(Mem + x) + 1 );
		qx ++;
	}

	N = atoi(Mem + x ); x += ( strlen(Mem + x) + 1 );

//	fprintf(stderr, "%u,%u,%u\n", C,D,N);

	bzero(Exists, 256);

	bzero(List, 101);
	Length = 0;
	qx = 0;
	while ( qx < N ) {
		if ( Length != 0 ) {
			if (        Cdel[ (List[Length-1]  *256) + Mem[x+qx] ] != 0 ) {
				Exists[ List[Length-1] ] --;
				List[Length-1] = Cdel[ (List[Length-1]  *256) + Mem[x+qx] ];
				List[Length] = 0x00;
			} else if ( Dels[ Mem[x+qx] ] > 0 ) {
				qy = 0;
				while ( qy < Dels[ Mem[x+qx] ] ) {
					if ( Exists[ Ddel[ (Mem[x+qx] * 256) + qy ] ] > 0 ) {
//						fprintf(stderr, "%c - %u,%c  %u\n", Mem[x+qx], qy, Ddel[ (Mem[x+qx] * 256) + qy ] ,  (unsigned int)Exists[ Ddel[ (Mem[x+qx] * 256) + qy ] ]);

						Length = 0;
						List[Length] = 0x00;
						bzero(Exists, 256);
						break;
					}
					qy ++;
				}
				if ( qy == Dels[ Mem[x+qx] ] ) {
					goto a;
				}
			} else {
				a:
				List[Length] = Mem[x+qx];
				Exists[Mem[x+qx]] ++;
				Length ++;
				List[Length] = 0x00;
			}
		} else {
			List[Length] = Mem[x+qx];
			Exists[Mem[x+qx]] ++;
			Length ++;
			List[Length] = 0x00;
		}
		qx ++;
//		fprintf(stderr, "%s\n", List);
	}

	x += ( strlen(Mem + x) + 1 );


	printf("Case #%u: [", Case_T + 1 );

	qx = 0;
	while ( qx < Length ) {
		if (qx != 0 ) { printf(", "); }
		printf("%c", (char)List[qx]);
		qx ++;
	}

	printf("]\n");

	Case_T ++;
}

return 0;
}