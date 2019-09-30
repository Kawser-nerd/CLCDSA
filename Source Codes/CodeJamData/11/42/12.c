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




int qx;
int qy;
int64_t R, C, D;

int Best;

int st;

int * Plate = malloc( sizeof(int) * 500 * 500);

int64_t tempx;
int64_t tempy;

int qqx, qqy;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	R   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
	C   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
	D   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );


	qx = 0;
	while ( qx < R ) {
		qy = 0; while ( qy < C ) {
			Plate[ (C * qx) + qy] = Mem[x + qy] - 0x30;
			qy ++;
		}
		x += ( strlen(Mem + x) + 1 );
		qx ++;
	}

	Best = 0;

	st = 3;
	while ( (st <= R) && (st <= C) ) {
		qx = 0;
		while ( qx <= (R - st) ) {
			qy = 0;
			while ( qy <= (C-st) ) {
				tempx = 0;
				tempy = 0;
				qqx = 0;
				while ( qqx < st ) {
					qqy = 0;
					while ( qqy < st ) {
						tempx += (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqx * 2) - (st-1) )  )
						);

						tempy += (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqy * 2) - (st-1) )  )
						);

						qqy ++;
					}
					qqx ++;
				}

qqx = 0;
qqy = 0;
						tempx -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqx * 2) - (st-1) )  )
						);

						tempy -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqy * 2) - (st-1) )  )
						);

qqx = st-1;
qqy = 0;
						tempx -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqx * 2) - (st-1) )  )
						);

						tempy -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqy * 2) - (st-1) )  )
						);


qqx = 0;
qqy = (st-1);
						tempx -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqx * 2) - (st-1) )  )
						);

						tempy -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqy * 2) - (st-1) )  )
						);


qqx = st-1;
qqy = (st-1);
						tempx -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqx * 2) - (st-1) )  )
						);

						tempy -= (
							Plate[ ( C * (qx + qqx)) + (qy+qqy)]
						*
							((int64_t) ( (qqy * 2) - (st-1) )  )
						);




				if ( (tempx == 0 ) && (tempy == 0) ) {
//					fprintf(stderr, "found %d\n", st);
					Best = st;
				}

				qy ++;
			}
			qx ++;
		}
		st ++;
	}

	if ( Best == 0 ) {
		printf("Case #%u: IMPOSSIBLE\n", Case_T + 1 );
	} else {
		printf("Case #%u: %d\n", Case_T + 1, Best );
	}

	Case_T ++;
}

return 0;
}
