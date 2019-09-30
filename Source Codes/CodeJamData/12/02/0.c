#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>


int main( int argc, char ** argv, char ** envp ) {
int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
unsigned char * Mem = malloc(Size);
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




int N;
int S;
int p;

int T_a[100];

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	N   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	S   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	p   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

int x = 0;
	while ( x < N ) {
		T_a[x] =  atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
		x ++;
	}

int ans = 0;

x = 0;
	while ( x < N ) {
		if ( ((T_a[x] + 2) / 3) >= p ) {
			ans ++;
		} else if ( 
			(
				(((T_a[x] + 2) / 3) == ((T_a[x] + 1) / 3))
			&&
				((((T_a[x] + 2) / 3) + 1) >= p)
			&&
				(((T_a[x] + 2) / 3) != 0)
			)
		&&
			(S > 0)
		) {
			S --;
			ans ++;
		}
		x ++;
	}

	printf("Case #%u: %d\n", Case_T + 1, ans );

	Case_T ++;
}

return 0;
}
