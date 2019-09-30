#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>


int abs( int a ) {
	if (a < 0) {
		return 0-a;
	}
	return a;

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




int H;
int W;
int D;

int a[30*30];

int s_x;
int s_y;

int dd[101*101];

int x, y;


typedef struct {
	int hit;
	int tdx;
	int tdy;
} hret;

hret prop( int x, int y, int r_x, int r_y, int dx, int dy , int b ) {
//                          fprintf(stderr,"call: %d,%d %d,%d ,, %d,%d ,, %d\n", x,y,r_x,r_y,dx,dy,b);
	hret Return;
	Return.tdx = 0;
	Return.tdy = 0;

	if ( dy == 0 ) {
		if ( (a[ (30*y) + x ] == 3)
		&&
			(r_x != 0)
		) {
			Return.hit = 1;
//                          fprintf(stderr, "1: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}

		if ( a[ (30*y) + x + ((dx>0)?(1):(0-1)) ] == 1 ) {
			if ( b == 0 ) { Return.hit = 0; return Return; }
			Return.tdx ++;
			hret rec = prop( x , y, ((dx>0)?(0-1):(1)), 0, 0-dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "2: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		} else {

//		if ( a[ (30*y) + x + ((dx>0)?(1):(0-1)) ] > 1 ) {
			if ( b == 0 ) { Return.hit = 0; return Return; }
			Return.tdx ++;
			hret rec = prop( x + ((dx>0)?(1):(0-1)) , y, ((dx>0)?(0-1):(1)), 0, dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "3: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}
	}


	if ( dx == 0 ) {
		if (( a[ (30*y) + x ] == 3)
		&&
			(r_y != 0)
		) {
			Return.hit = 1;
//                          fprintf(stderr, "4: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}

		if ( a[ (30*(y +  ((dy>0)?(1):(0-1))  )) + x ] == 1 ) {
			if ( b == 0 ) { Return.hit = 0; return Return; }
			Return.tdy ++;
			hret rec = prop( x , y, 0, ((dy>0)?(0-1):(1)), dx, 0-dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "5: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		} else {

//		if ( a[ (30*y) + x + ((dx>0)?(1):(0-1)) ] > 1 ) {
			if ( b == 0 ) { Return.hit = 0; return Return; }
			Return.tdy ++;
			hret rec = prop( x , y + ((dy>0)?(1):(0-1)), 0, ((dy>0)?(0-1):(1)), dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "6: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}
	}

	if (
		( (r_x % (dx/2)) != 0 )
	||
		( (r_y % (dy/2)) != 0 )
	) {
		fprintf(stderr, "error3: dx,dy %d,%d ; rx,ry %d,%d\n", dx, dy, r_x, r_y);
	}

	if (
		( (r_x / (dx/2)) < 0 )
	&&
		( (r_x / (dx/2))  == (r_y / (dy/2))  )
	) {
		if ( a[ (30*y) + x ] == 3 ) {
			Return.hit = 1;
//                          fprintf(stderr, "7: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}
	}


	int cm = abs(dy)*abs(dx);

	int hittime_x_n;
	int hittime_y_n;

	if ( dx < 0 ) {
		hittime_x_n = r_x + (cm/2);
	} else {
		hittime_x_n = (cm/2) - r_x;
	}

	if ( dy < 0 ) {
		hittime_y_n = r_y + (cm/2);
	} else {
		hittime_y_n = (cm/2) - r_y;
	}

	if ( b == 0 ) { Return.hit = 0; return Return; }

	if (         (hittime_y_n * abs(dx)) == (hittime_x_n * abs(dy)) ) {
//                          fprintf(stderr, "corner\n");


		if (
			a[
				(
					30
				*
					(y +  ((dy>0)?(1):(0-1)) )
				)
			+
				x
			+
				((dx>0)?(1):(0-1))
			] == 1
		) {
//                          fprintf(stderr, "mirrorcorner\n" );
			if (
				(a[ (30* (y +  0                )) + x + ((dx>0)?(1):(0-1)) ] == 1)
			&& 
				(a[ (30* (y +  ((dy>0)?(1):(0-1)) )) + x + 0                ] == 1)
			) {
				Return.tdy ++;
				Return.tdx ++;
				hret rec = prop( x , y , (cm/2) * ((dx>0)?(1):(0-1)), (cm/2) * ((dy>0)?(1):(0-1)), 0-dx, 0-dy, b - 1 );
				Return.hit = rec.hit;
				Return.tdx += rec.tdx;
				Return.tdy += rec.tdy;
//                          fprintf(stderr, "8: %d,%d\n", Return.tdx, Return.tdy );

				return Return;
			} else if ( 
				(a[ (30* (y +  ((dy>0)?(1):(0-1)) )) + x + 0                ] == 1)
			) {
				Return.tdy ++;
				Return.tdx ++;
				hret rec = prop( x  + ((dx>0)?(1):(0-1)), y , (cm/2) * ((dx>0)?(0-1):(1)), (cm/2) * ((dy>0)?(1):(0-1)), dx, 0-dy, b - 1 );
				Return.hit = rec.hit;
				Return.tdx += rec.tdx;
				Return.tdy += rec.tdy;
//                          fprintf(stderr, "9: %d,%d\n", Return.tdx, Return.tdy );
				return Return;
			} else if (
				(a[ (30* (y +  0                )) + x + ((dx>0)?(1):(0-1)) ] == 1)
			) {
				Return.tdy ++;
				Return.tdx ++;
				hret rec = prop( x , y + ((dy>0)?(1):(0-1)) , (cm/2) * ((dx>0)?(1):(0-1)), (cm/2) * ((dy>0)?(0-1):(1)), 0-dx, dy, b - 1 );
				Return.hit = rec.hit;
				Return.tdx += rec.tdx;
				Return.tdy += rec.tdy;
//                          fprintf(stderr, "10: %d,%d\n", Return.tdx, Return.tdy );
				return Return;
			} else {
				Return.hit = 0;
//                          fprintf(stderr, "11: %d,%d\n", Return.tdx, Return.tdy );
				return Return;
			}
		} else {
//                          fprintf(stderr, "notmirrorcorner\n" );
			Return.tdy ++;
			Return.tdx ++;
			hret rec = prop( x + ((dx>0)?(1):(0-1)), y + ((dy>0)?(1):(0-1)), (cm/2) * ((dx>0)?(0-1):(1)), (cm/2) * ((dy>0)?(0-1):(1)), dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "12: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}



	} else if (  (hittime_y_n * abs(dx)) > (hittime_x_n * abs(dy))  ) {
		// then x hits first

		int steps = hittime_x_n / abs(dx);

		if ( 
			(a[ (30* (y +  0                )) + x + ((dx>0)?(1):(0-1)) ] == 1)
		) {
			Return.tdx ++;
			hret rec = prop( x , y ,  (cm/2) * ((dx>0)?(1):(0-1)) ,  r_y + (dy * steps), 0-dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "13: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		} else {
			Return.tdx ++;
			hret rec = prop( x + ((dx>0)?(1):(0-1)), y ,  (cm/2) * ((dx>0)?(0-1):(1)) ,  r_y + (dy * steps), dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "14: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}
	} else if (  (hittime_y_n * abs(dx)) < (hittime_x_n * abs(dy)) ) {

		int steps = hittime_y_n / abs(dy);

		if ( 
			(a[ (30* (y + ((dy>0)?(1):(0-1)) )) + x + 0                  ] == 1)
		) {
			Return.tdy ++;
			hret rec = prop( x , y , r_x + (dx*steps), (cm/2) * ((dy>0)?(1):(0-1)) , dx, 0-dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "15: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		} else {
			Return.tdy ++;
			hret rec = prop( x , y  + ((dy>0)?(1):(0-1)), r_x + (dx*steps), (cm/2) * ((dy>0)?(0-1):(1)) , dx, dy, b - 1 );
			Return.hit = rec.hit;
			Return.tdx += rec.tdx;
			Return.tdy += rec.tdy;
//                          fprintf(stderr, "16: %d,%d\n", Return.tdx, Return.tdy );
			return Return;
		}

	}

	fprintf(stderr, "error2\n");
}

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	H   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	W   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	D   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

//                          fprintf(stderr, "H %d, W %d, D %d\n", H, W, D);

	y = 0;
	while ( y < H ) {
		x = 0;
		while ( x < W ) {
			if ( Mem[q + x] == '#' ) {
				a[ (30*y) + x ] = 1;
			}
			if ( Mem[q + x] == '.' ) {
				a[ (30*y) + x ] = 2;
			}
			if ( Mem[q + x] == 'X' ) {
				a[ (30*y) + x ] = 3;
				s_x = x;
				s_y = y;
			}

			x ++;
		}
		q += ( strlen(Mem + q) + 1 );
		y ++;
	}


	int ans = 0;

	bzero( dd, sizeof(int) * 101 * 101 ) ;

	dd[ (101*(50 + 0)) + (50 + 0) ] = 1;

	x = -1;
	y = -1;


	while ( (abs(x) <= D) && (abs(y) <= D) ) {
		if ( dd[ (101*(50 + y)) + (50 + x) ] == 0 ) {
			hret ret = prop( s_x, s_y, 0, 0, x*2, y*2, (D * 2) + 3 );
//return 0;
			if ( ret.hit ) {
				if ( ((ret.tdx * ret.tdx) + (ret.tdy * ret.tdy)) <= (D*D) ) {

//                          fprintf(stderr, "hit shooting from %d,%d with dir %d,%d, dist %d,%d,, against %d\n", s_x, s_y, x, y, ret.tdx, ret.tdy, D);
					ans ++;
				}
			}

			int k = 1;
			while ( k <= D ) {
				if ( (abs(k*y) > D) || (abs(k*x) > D) ) { break; }
				dd[ (101*(50 + (k*y))) + (50 + (k*x)) ] = 1;
				k ++;
			}
		}

		if (        (x<0) && (y < abs(x)) && (y >= (0-abs(x)))) {
			y ++;
		} else if ( (y>0) && (x < abs(y))  && (x >= (0-abs(y))) ) {
			x ++;
		} else if ( (x>0) && (y > (0-abs(x))) && (y <= (abs(x))  )) {
			y --;
		} else if ( (y<0) && (x > (0-abs(y)))  && (x <= (abs(y))  )) {
			x --;

			if ( (x == y) && (x <= 0) ) {
				x --;
				y --;
			}

		}

/*
 else {
			fprintf(stderr, "error\n");
		}
		fprintf(stdout, "new is %d,%d\n", x, y);
*/

	}


	printf("Case #%u: %d\n", Case_T + 1,    ans   );

	Case_T ++;
}

return 0;
}
