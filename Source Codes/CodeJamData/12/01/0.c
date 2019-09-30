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
//	if ( Mem[q] == 0x20 ) { Mem[q] = 0x00; }
	q++;
}
unsigned int Cases = atoi(Mem);
q = strlen(Mem) + 1;
fprintf(stderr, "Cases: %u\n", Cases);



int Trans[26] = {121,104,101,115,111,99,118,120,100,117,105,103,108,98,107,114,122,116,110,119,106,112,102,109,97,113};


unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	int x = 0;
	char * a = Mem + q;


	int y = strlen(Mem + q );
	while ( x < y ) {
		if ( (Mem[q + x] <= 'z') &&  (Mem[q + x] >= 'a') ) {
			Mem[q + x] = Trans[ Mem[q + x] -'a' ];
		}
		x ++;
	}
	q += ( strlen(Mem + q) + 1 );


	printf("Case #%u: %s\n", Case_T + 1,   a  );


	Case_T ++;
}

return 0;
}


