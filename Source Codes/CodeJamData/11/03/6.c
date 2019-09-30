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


unsigned int N;
unsigned int Candies[1000];

unsigned int qx;

unsigned int Temp;
unsigned int Smallest;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	N = atoi(Mem + x ); x += ( strlen(Mem + x) + 1 );
	qx = 0;
	while ( qx < N ) {
		Candies[qx] = atoi(Mem + x ); x += ( strlen(Mem + x) + 1 );
		qx ++;
	}

	Temp = 0;
	qx = 0;
	while ( qx < N ) {
		Temp ^= Candies[qx];
		qx ++;
	}

	if ( Temp != 0 ) {
		printf("Case #%u: NO\n", Case_T + 1 );
	} else {
		qx = 0;
		Temp = 0;
		Smallest = 1000001;
		while ( qx < N ) {
			Temp += Candies[qx];
			if ( Candies[qx] < Smallest ) {
				Smallest = Candies[qx];
			}
			qx ++;
		}
		Temp -= Smallest;
		printf("Case #%u: %u\n", Case_T + 1, Temp);
	}

	Case_T ++;
}

return 0;
}