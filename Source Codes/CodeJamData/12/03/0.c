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




int A;
int B;

char print[9];
int l;
int j;

int used[9];
int nused;

char chair;

int64_t ans;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	A   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	B   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

	ans = 0;

	int c = A;
	while ( c <= B ) {

		sprintf(print, "%d", c);
		nused = 0;
		l = strlen(print);
		int d = 1;
		while ( d < l ) {
			chair = print[0];
			memmove(print, print+1, 8);
			print[l-1] = chair;
			print[l] = 0x00;
			sscanf(print, "%d", &j );
			if ( (j <= B) && (j>= A) ) {
				if ( j > c ) {
					int k = 0;
					while ( k < nused ) {
						if ( used[k] == j ) { break; }
						k ++;
					}
					if ( k == nused ) {
						used[k] = j;
						nused ++;
						ans ++;
					}
				}
			}
			d ++;
		}

		c ++;
	}


	printf("Case #%u: %lld\n", Case_T + 1,   (long long int)ans   );

	Case_T ++;
}

return 0;
}
