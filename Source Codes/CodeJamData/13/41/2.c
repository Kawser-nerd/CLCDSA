#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define nor( A_name , B_limit )                       for ( A_name = 0; A_name < (B_limit); A_name ++ )
#define dor( A_name , B_limit )           int A_name; for ( A_name = 0; A_name < (B_limit); A_name ++ )

#define ri                                 atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
#define rll                                atoll(Mem + q ); q += ( strlen(Mem + q) + 1 );

#define cil( A )                          ((int64_t)(A))
#define  cd( A )                          ((double )(A))
#define cll( A )                          ((long long int)(A))

#define mr( A_type, B_name, C_count )     size_t arraysizebytes##B_name = (sizeof(A_type) * (C_count)) ; A_type * B_name = malloc( arraysizebytes##B_name );
#define arrayclear( B_name )              bzero( B_name, arraysizebytes##B_name );
#define usup( A_rop, B_op)                if ( (A_rop) < (B_op) ) { (A_rop) = (B_op); }
#define uinf( A_rop, B_op)                if ( (A_rop) > (B_op) ) { (A_rop) = (B_op); }
#define maxa( A_rop, B_array, C_limit )   int maxa##B_array = 0; while ( maxa##B_array < (C_limit) ) { if ( maxa##B_array == 0 ) { A_rop = B_array[maxa##B_array]; } else { usup(A_rop, B_array[ maxa##B_array ]) } ; maxa##B_array ++; }
#define mina( A_rop, B_array, C_limit )   int maxa##B_array = 0; while ( maxa##B_array < (C_limit) ) { if ( maxa##B_array == 0 ) { A_rop = B_array[maxa##B_array]; } else { uinf(A_rop, B_array[ maxa##B_array ]) } ; maxa##B_array ++; }

                                          void * swapchair;
#define swap( A, B )                             swapchair = malloc(sizeof(A)); memcpy(swapchair, &(A), sizeof(A) ); memcpy( &(A), &(B), sizeof(A) ); memcpy( &(B), swapchair,  sizeof(A) ); free(swapchair);
#define abs( A )                          ( ((A)<0) ? ( 0 - (A) ) : ( A ) )

#if 1
#define fsd( A_fmt , ... )                fprintf(stderr, "%s %d: " A_fmt "\n", __FUNCTION__, __LINE__ , ##__VA_ARGS__ );
#else
#define fsd( ... )                        (void)0 ;
#endif

#define niut( A_rop , B_limit, C_cond )                  while ( A_rop < (B_limit) ) { if ( C_cond ) { break; } A_rop ++; }
#define diut( A_rop , B_limit, C_cond )   int A_rop = 0; while ( A_rop < (B_limit) ) { if ( C_cond ) { break; } A_rop ++; }

#define bst( A_name, B_lower, B_upper, C_cond )    int64_t lower##A_name = B_lower; int64_t upper##A_name = B_upper; int64_t A_name; while ( lower##A_name < upper##A_name ) { A_name = lower##A_name + ((upper##A_name - lower##A_name)/2); if ( ! (C_cond) ) { lower##A_name = A_name + 1; } else { upper##A_name = A_name; } } A_name = upper##A_name;

typedef struct {
	unsigned on;
	int64_t x;
	int64_t count;
	int64_t original;
} j;

int compar_j( j * left, j * right ) {
	if ( left[0].x  < right[0].x ) { return -1; }
	if ( left[0].x == right[0].x ) {
		if ( left[0].on > right[0].on ) {
			return -1;
		}
	}
	return 1;
}



int64_t cost( int64_t a, int64_t b, int64_t N ) {
	if ( a == b ) { return 0; }
	int64_t d = b-a;

	int64_t temp = (N+1) * d;

	d *= (d+1);
	d /= 2;

	temp -= d;

	temp = temp % 1000002013LL;

	return temp;
}



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



j jj[2000];


typedef struct { 
	int64_t on;
	int64_t count;
} ticket;

ticket tt[1000];
int64_t numtickets;

int64_t N, M;
while ( Case_T < Cases ) {
/* --------------------- */
	N = rll
	M = rll

	dor( x , M ) {
/*
		ss[x].o = rll
		ss[x].e = rll
		ss[x].p = rll
*/

		jj[2*x].on = 1;
		jj[2*x].x = rll;

		jj[(2*x) + 1].on = 0;
		jj[(2*x) + 1].x  = rll;

		jj[(2*x)    ].count  = rll;
		jj[(2*x) + 1].count  = jj[(2*x)    ].count ;

		jj[(2*x) + 1].original= jj[(2*x) ].x  ;
	}

	qsort( jj, 2*M, sizeof(j), compar_j );


	int64_t ans = 0;

	numtickets = 0;
	nor( x, 2*M ) {
		if ( jj[x].on ) {
			tt[numtickets].on = jj[x].x;
			tt[numtickets].count = jj[x].count;
			numtickets ++;
		} else {
			int64_t kill = jj[x].count;
			while ( kill > 0 ) {
				int64_t m = kill;
				uinf( m, tt[numtickets - 1].count );

				int64_t temp = (cost( jj[x].original, jj[x].x, N) - cost( tt[numtickets-1].on, jj[x].x, N)) % 1000002013LL;
				temp *= m;
				temp %= 1000002013LL;


				ans += temp;
				ans %= 1000002013LL;



				kill -= m;
				tt[numtickets - 1].count -= m;
				if ( tt[numtickets - 1].count == 0 ) {
					numtickets --;
				}
			}
		}
	}


	ans += 1000002013LL;
	ans %= 1000002013LL;

	printf("Case #%u: %lld\n", Case_T + 1, ans );

	Case_T ++;
/* --------------------- */
}

return 0;
}
