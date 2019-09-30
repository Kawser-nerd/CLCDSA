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

unsigned int qx;


unsigned int N;

unsigned int Wrong;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	N = atoi(Mem + x ); x += ( strlen(Mem + x) + 1 );

	Wrong = 0;
	qx = 0;
	while ( qx < N ) {
		if ( atoi(Mem + x ) != (qx + 1) ) {
			Wrong ++;
		}
		x += ( strlen(Mem + x) + 1 );
		qx ++;
	}

	printf("Case #%u: %u.000000\n", Case_T + 1, Wrong );

	Case_T ++;
}

return 0;
}