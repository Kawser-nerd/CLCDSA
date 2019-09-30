#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
#define U_L 100000000b
#define U_M	010000000b
#define U_R 001000000b
#define M_L 000100000b
#define M_M	000010000b
#define M_R 000001000b
#define D_L 000000100b
#define D_M	000000010b
#define D_R 000000001b
*/

//when X' been touch, it become a Y, that don't reflect anything, it absorb everything

typedef struct
{
	long long int H, W, D;
	char* map;
	long long int Xx, Xy;
} mirrorobj;

void mirTheWall(mirrorobj* mirrorhall);

void printMap(mirrorobj* mirrorhall);

int isDirect(mirrorobj* mirrorhall, 
	long long int Ax, long long int Ay);

void travTheHall(mirrorobj* mirrorhall, long long int* out);


int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long long int T, H, W, D;
	long long int i;
	long long int j, k;
	mirrorobj mirrorhall;

	fscanf(fin, "%lld\n", &T);

	long long int out;
	char ocase[40];

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%lld ", &H);
		mirrorhall.H = H;
		//printf("%lld\n", H);
		fscanf(fin, "%lld ", &W);
		mirrorhall.W = W;
		//printf("%lld\n", W);
		fscanf(fin, "%lld\n", &D);
		mirrorhall.D = D;
		//printf("%lld\n", D);

		out = 0;

		//readMirror(fin, mirrorhall);
		mirrorhall.map = calloc(H * W + 1, sizeof(char));
		for (j = 0; j < H; ++j)
		{
			fscanf(fin, "%s\n", mirrorhall.map + W * j );
		}
		for (j = 0; j < W; ++j)
		{
			for (k = 0; k < H; ++k)
			{
				if (mirrorhall.map[j + W * k] == 'X')
				{
					mirrorhall.Xx = j;
					mirrorhall.Xy = k;
				}
			}
		}
		//printf("%s", mirrorhall.map);
		//printMap(&mirrorhall);

		//mirTheWall(mirrorhall);
		
		while(
				((mirrorhall.Xx + 0.5 - 1) <= mirrorhall.D) ||
				((mirrorhall.Xy + 0.5 - 1) <= mirrorhall.D) ||
				(((mirrorhall.W - mirrorhall.Xx - 0.5 - 1)) <= mirrorhall.D) ||
				(((mirrorhall.H - mirrorhall.Xy - 0.5 - 1)) <= mirrorhall.D)
				){
			mirTheWall(&mirrorhall);
		}
		//mirTheWall(&mirrorhall);


		//printMap(&mirrorhall);

		//mirTheNode();
		//travTheHall();
		travTheHall(&mirrorhall, &out);
		//printMap(&mirrorhall);





		sprintf(ocase, "Case #%lld: %lld", i + 1, out);
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else
			fprintf (fout, "%s", ocase);
		
	}

	fclose(fin);
	fclose(fout);


	return 0;
}

void mirTheWall(mirrorobj* mirrorhall){
	long long int W = (*mirrorhall).W;
	long long int H = (*mirrorhall).H;
	long long int D = (*mirrorhall).D;
	long long int newW = 3 * W - 4;
	long long int newH = 3 * H - 4;

	long long int i, X0, Y0;
	long long int j, k, newi, newj, oldi, oldj;
	long long int Xx, Xy;
	Xx = (*mirrorhall).Xx + W - 2;
	Xy = (*mirrorhall).Xy + H - 2;

	char* newmap = calloc(newH * newW + 1, sizeof(char));
	memset(newmap, 'U', newW * newH);

	// copy to the main
	for (i = 0; i < W; ++i)
	{
		oldi = i;
		newi = W - 2 + i;

		for (j = 0; j < H; ++j)
		{
			oldj = j;
			newj = H - 2 + j;

			newmap[newi + newW * newj] = (*mirrorhall).map[i + j * W];
		}
	}

	// copy to the left
	X0 = W * 2 - 3;
	for (i = 0; i < W - 1; ++i)
	{
		oldi = i + W - 1;
		newi = X0 - oldi;
		for (j = 0; j < newH; ++j)
		{
			oldj = j;
			newj = j;
			newmap[newi + newW * newj] = newmap[oldi + newW * oldj];
		}
	}

	// copy to the right
	//X0 = W * 2 - 1;
	for (i = 0; i < W - 1; ++i)
	{
		oldi = i;
		newi = newW - oldi - 1;
		for (j = 0; j < H; ++j)
		{
			oldj = j;
			newj = H - 2 + j;
			newmap[newi + newW * newj] = (*mirrorhall).map[oldi + W * oldj];
		}
	}

	// copy to the up
	Y0 = H * 2 - 3;
	for (i = 0; i < newW; ++i)
	{
		oldi = i;
		newi = i;
		for (j = 0; j < H - 1; ++j)
		{
			oldj = j + H - 1;
			newj = Y0 - oldj;
			newmap[newi + newW * newj] = newmap[oldi + newW * oldj];
		}
	}

	// copy to the up
	Y0 = H * 4 - 7;
	for (i = 0; i < newW; ++i)
	{
		oldi = i;
		newi = i;
		for (j = 0; j < H - 1; ++j)
		{
			oldj = j + H - 1;
			newj = Y0 - oldj;
			newmap[newi + newW * newj] = newmap[oldi + newW * oldj];
		}
		newmap[newi + newW * (newH - 1)] = '#';
	}

	free((*mirrorhall).map);
	(*mirrorhall).map = newmap;
	(*mirrorhall).W = newW;
	(*mirrorhall).H = newH;
	(*mirrorhall).Xx = Xx;
	(*mirrorhall).Xy = Xy;

	//printf("%c\n", newmap[Xx + newW * Xy]);
}

void printMap(mirrorobj* mirrorhall){
	long long int W = (*mirrorhall).W;
	long long int H = (*mirrorhall).H;
	long long int D = (*mirrorhall).D;
	char* map = (*mirrorhall).map;

	char* tmpline = calloc(W + 1, sizeof(char));

	long long int i;

	//printf("%lld %lld %lld\n", H, W, D);
	//printf("%s\n", map);
	for (i = 0; i < H; ++i)
	{
		memcpy(tmpline, map + W * i, W);
		tmpline[W] = 0;
		printf("%s\n", tmpline);
	}
	//printf("%s\n", map);
	printf("\n");

	free(tmpline);
}

int isDirect(mirrorobj* mirrorhall, 
	long long int Ax, long long int Ay){

	long long int i, j, k, Bx, By;

	long long int W = (*mirrorhall).W;
	long long int H = (*mirrorhall).H;
	long long int D = (*mirrorhall).D;
	char* map = (*mirrorhall).map;
	long long int Xx = (*mirrorhall).Xx;
	long long int Xy = (*mirrorhall).Xy;

	int ret = 0;

	if ((Ax == Xx) && (Ay == Xy))
	{
		return 0;
	}

	if (Ax == Xx)
	{
		if ((Ay - Xy) * (Ay - Xy) > D * D)
			return 0;
		else
		{
			Bx = Xx;
			By = Xy + ((Ay - Xy) > 0) * 1 + ((Ay - Xy) < 0) * -1;
			if(By == Ay) return 1;
			while((Ay - Xy) * (Ay - Xy) > (By - Xy) * (By - Xy)){
				if((map[Bx + W * By] == 'Y')||map[Bx + W * By] == 'X'){
					//map[Ax + W * Ay] = 'Y';
					return 0;
				}
				else if ((map[Bx + W * By] == '#'))
				{
					return 0;
				}
				By += ((Ay - Xy) > 0) * 1 + ((Ay - Xy) < 0) * -1;
			}
			return 1;
		}
	}

	if (Ay == Xy)
	{
		if ((Ax - Xx) * (Ax - Xx) > D * D)
			return 0;
		else
		{
			Bx = Xx + ((Ax - Xx) > 0) * 1 + ((Ax - Xx) < 0) * -1;
			By = Xy;
			if(Bx == Ax)return 1;
			while((Ax - Xx) * (Ax - Xx) > (Bx - Xx) * (Bx - Xx)){
				if((map[Bx + W * By] == 'Y')||map[Bx + W * By] == 'X'){
					//map[Ax + W * Ay] = 'Y';
					return 0;
				}
				else if ((map[Bx + W * By] == '#'))
				{
					return 0;
				}
				Bx += ((Ax - Xx) > 0) * 1 + ((Ax - Xx) < 0) * -1;
			}
			return 1;
		}
	}
	
	if ( (Ax - Xx) * (Ax - Xx) + (Ay - Xy) * (Ay - Xy) <= D * D)
	{
		//return 1;
		Bx = Xx + ((Ax - Xx) > 0) * 1 + ((Ax - Xx) < 0) * -1;
		By = (Ay - Xy) * (Bx - Xx) / (Ax - Xx) + Xy;
		while((Bx - Xx) * (Bx - Xx) + (By - Xy) * (By - Xy) <
				 (Ax - Xx) * (Ax - Xx) + (Ay - Xy) * (Ay - Xy))
		{
			if((Ay - Xy) * (Bx - Xx) / (Ax - Xx) * (Ax - Xx) == (Ay - Xy) * (Bx - Xx)){
				if((map[Bx + W * By] == 'Y')||map[Bx + W * By] == 'X'){
					map[Ax + W * Ay] = 'Y';
					return 0;
				}
				else if ((map[Bx + W * By] == '#'))
				{
					//map[Bx + W * By] = 'S';
					return 0;
				}
			}
			Bx += ((Ax - Xx) > 0) * 1 + ((Ax - Xx) < 0) * -1;
			By = (Ay - Xy) * (Bx - Xx) / (Ax - Xx) + Xy;
		}
		return 1;
	}
	else return 0;


	return ret;
}

void travTheHall(mirrorobj* mirrorhall, long long int* out){

	long long int i, j, k;

	long long int W = (*mirrorhall).W;
	long long int H = (*mirrorhall).H;
	long long int D = (*mirrorhall).D;
	char* map = (*mirrorhall).map;
	long long int Xx = (*mirrorhall).Xx;
	long long int Xy = (*mirrorhall).Xy;


	for (j = 0; j < W; ++j)
	{
		for (k = 0; k < H; ++k)
		{
			if (map[j + W * k] == 'X')
			{
				//printf("%lld, %lld\n", j ,k);
				if(isDirect(mirrorhall, j, k)){
					map[j + W * k] = 'Y';//die
					*out += 1;
				}
			}
		}
	}
}