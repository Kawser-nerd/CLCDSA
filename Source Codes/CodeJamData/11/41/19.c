#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
	double l;
	int s;
} MSStruct;



double timeonit( MSStruct t_a, int t_bonus ) {
	double t_ret = ((double) t_a.l);
	t_ret /= ((double) (t_a.s + t_bonus));
	return t_ret;
}



int MS_LeftToBeFirst( MSStruct * Left, MSStruct * Right ) {
	if ( Left[0].s < Right[0].s ) { return 1; }
	if ( Left[0].s > Right[0].s ) { return 0; }
	if ( Left[0].l > Right[0].l ) { return 1; }
	return 0;
}




#define MS_Biggest 1002
MSStruct * GlobalDumbMS;


void ms( MSStruct * MS_Source , unsigned int MS_Count) {
	MSStruct * MS_Temp = GlobalDumbMS;
	MSStruct * MS_Front = MS_Temp;
	MSStruct * MS_Back  = MS_Source;

	unsigned int MS_TT_A;
	unsigned int MS_TT_B;
	unsigned int MS_S_A;
	unsigned int MS_S_B;
	unsigned int MS_Size = 1;
	unsigned int MS_T;
	while ( MS_Size < MS_Count ) {
		MS_T = 0;
	
		while ( MS_T < MS_Count ) {
			/*  */
			MS_S_A = MS_Size;
			MS_S_B = MS_Size;
			if ( (MS_T + (MS_Size * 2)) > MS_Count ) {
				if ( (MS_T + MS_Size) >= MS_Count ) {
					MS_TT_A = 0;
					while ( (MS_T + MS_TT_A) < MS_Count ) {
						MS_Front[MS_T + MS_TT_A] = MS_Back[MS_T + MS_TT_A];
						MS_TT_A ++;
					}
					break;
				}
				MS_S_B = MS_Count - (MS_T + MS_Size);
			}
			MS_TT_A = 0;
			MS_TT_B = 0;
			while ( (MS_TT_A < MS_S_A) && (MS_TT_B < MS_S_B) ) {
				if ( MS_LeftToBeFirst( & MS_Back[MS_T + MS_TT_A] , & MS_Back[MS_T + MS_S_A + MS_TT_B] ) ) {
					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_TT_A];
					MS_TT_A ++;
				} else {
					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_S_A + MS_TT_B];
					MS_TT_B ++;
				}
			}
			if ( MS_TT_A < MS_S_A ) {
				while ( MS_TT_A < MS_S_A ) {
					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_TT_A];
					MS_TT_A ++;
				}
			}
			if ( MS_TT_B < MS_S_B ) {
				while ( MS_TT_B < MS_S_B ) {
					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_S_A + MS_TT_B];
					MS_TT_B ++;
				}
			}
	
			MS_T += (MS_Size * 2);
		}
	
		if ( MS_Front == MS_Source ) {
			MS_Front = MS_Temp;
			MS_Back  = MS_Source;
		} else {
			MS_Front = MS_Source;
			MS_Back  = MS_Temp;
		}
	
		MS_Size <<= 1;
	}
	if ( MS_Back == MS_Temp ) {
		MS_T = 0;
		while ( MS_T < MS_Count ) {
			MS_Front[MS_T] = MS_Back[MS_T];
			MS_T ++;
		}
	}
	return;
}




























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


/* main */ GlobalDumbMS = malloc( sizeof(MSStruct) * MS_Biggest );


int qx;


int X;
int S;
int R;
int t;
int N;

MSStruct * Poo = malloc( sizeof(MSStruct) * 1002 );


int temp;

int bonus;

double dtemp;

double blah;

double leftover;

double Answer;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	X   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
	S   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
	R   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
	t   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
	N   = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );

	temp = 0;

	qx = 0;
	while ( qx < N ) {
		Poo[qx].l = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
		Poo[qx].s = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );
		Poo[qx].l = Poo[qx].s - Poo[qx].l;
		Poo[qx].s = atoll(Mem + x ); x += ( strlen(Mem + x) + 1 );

		Poo[qx].s += S;
		temp += Poo[qx].l;
		qx ++;
	}

	Poo[N].l = X - temp;
	Poo[N].s = S;
/*
qx = 0;
while (qx < (N+1) ) {
	fprintf(stderr, "L: %lf, s %d\n", Poo[qx].l, Poo[qx].s);
	qx ++;
}
*/
	bonus = R - S;
//fprintf(stderr, "bonus %d\n", bonus);

	ms( Poo, (N + 1) );
/*
fprintf(stderr, "sorted\n");
qx = 0;
while (qx < (N+1) ) {
	fprintf(stderr, "L: %lf, s %d\n", Poo[qx].l, Poo[qx].s);
	qx ++;
}
*/
	/* ! */ dtemp = ((double) t);

	qx = 0;
	while ( qx < (N+1) ) {
		blah = timeonit(Poo[qx], bonus);
		if ( dtemp < blah ) {
			if ( dtemp > 0 ) {
				leftover  = Poo[qx].l - ( ((double)(Poo[qx].s + bonus)) * dtemp );
				Poo[qx].l = Poo[qx].l - leftover;
				Poo[N+1].s = Poo[qx].s;

				Poo[qx].s += bonus;

				Poo[N+1].l = leftover;
//				fprintf(stderr, "discount\n");
			} else {
//				fprintf(stderr, "www\n");
				Poo[N+1].l = 0.0;
				Poo[N+1].s = 123;
			}
			break;
		}
		dtemp -= blah; // (   Poo[qx].l / ((double)(Poo[qx].s + bonus))     );
		Poo[qx].s += bonus;
		qx ++;
	}

if ( qx == (N+1) ) {
				Poo[N+1].l = 0.0;
				Poo[N+1].s = 123;
}

/*qx = 0;
while (qx < (N+2) ) {
	fprintf(stderr, "L: %lf, s %d\n", Poo[qx].l, Poo[qx].s);
	qx ++;
}
*/
	Answer = 0.0;
	qx = 0;
	while ( qx < (N+2) ) {
		Answer += ( Poo[qx].l / ((double) Poo[qx].s) ) ;
		qx ++;
	}


	printf("Case #%u: %lf\n", Case_T + 1, Answer );

	Case_T ++;
}

return 0;
}
