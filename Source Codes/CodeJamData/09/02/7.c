#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FGETS(s,n,p)	s[0] = 0;fgets(s,n,p)

typedef struct {
	int altitude;
	int level;	// Basin = 1, Others = 2 or more
	int id;		// Basin identification from 1,2,...
} maptype;

int print_map(int H, int W, maptype map[100][100])
{
	int i, j;
	int id_char[300];
	int next_char = 'a';
	memset(id_char, 0, sizeof(id_char));
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			int id = map[i][j].id;
			if (id_char[id] == 0)
			{
				id_char[id] = next_char++;
			}
			printf("%c", id_char[id]);
//			printf(" %5d[%c]", map[i][j].altitude, map[i][j].id+'a'-1);
			if (j == W-1) printf("\n"); else printf(" ");
		}
//		printf("\n");
	}
	return 0;
}

int get_flow_pos(int H, int W, maptype map[100][100], int h, int w)
{
	int pos = -1;	// Will not flow
	int pos_alt = map[h][w].altitude;
	// Will it Morth?
	if (h-1 >= 0 && map[h-1][w].altitude < pos_alt)
	{
		pos = (h-1)*W+w;
		pos_alt = map[h-1][w].altitude;
	}
	// Will it West?
	if (w-1 >= 0 && map[h][w-1].altitude < pos_alt)
	{
		pos = h*W+(w-1);
		pos_alt = map[h][w-1].altitude;
	}
	// Will it East?
	if (w+1 <= W-1 && map[h][w+1].altitude < pos_alt)
	{
		pos = h*W+(w+1);
		pos_alt = map[h][w+1].altitude;
	}
	// Will it South?
	if (h+1 <= H-1 && map[h+1][w].altitude < pos_alt)
	{
		pos = (h+1)*W+w;
		pos_alt = map[h+1][w].altitude;
	}
	return pos;
}

int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int c, N;

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &N);
	for (c = 0; c < N; c++)
	{
		int H, W;
		maptype map[100][100];
		int i, j;

		fscanf(in, "%d %d", &H, &W);
		memset(map, 0, sizeof(map));
		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				fscanf(in, "%d", &(map[i][j].altitude));
			}
		}

		// Mark the Basin
		int processed = 0;
		int next_id = 1;
		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				if (	(i == 0 || map[i-1][j].altitude >= map[i][j].altitude) &&
					(i == H-1 || map[i+1][j].altitude >= map[i][j].altitude) &&
					(j == 0 || map[i][j-1].altitude >= map[i][j].altitude) &&
					(j == W-1 || map[i][j+1].altitude >= map[i][j].altitude))
				{
					map[i][j].level = 1;
					map[i][j].id = next_id++;
					processed++;
				}
			}
		}

		int level;
		for (level = 1; processed < W*H; level++)
		{
			for (i = 0; i < H; i++)
			{
				for (j = 0; j < W; j++)
				{
					if (map[i][j].level != level) continue;
					int my_pos = i*W+j;
					// Try North Pos
					if (i-1 >= 0 && get_flow_pos(H, W, map, i-1, j) == my_pos)
					{
						map[i-1][j].level = level+1;
						map[i-1][j].id = map[i][j].id;
						processed++;
					}
					// Try West Pos
					if (j-1 >= 0 && get_flow_pos(H, W, map, i, j-1) == my_pos)
					{
						map[i][j-1].level = level+1;
						map[i][j-1].id = map[i][j].id;
						processed++;
					}
					// Try East Pos
					if (j+1 <= W-1 && get_flow_pos(H, W, map, i, j+1) == my_pos)
					{
						map[i][j+1].level = level+1;
						map[i][j+1].id = map[i][j].id;
						processed++;
					}
					// Try South Pos
					if (i+1 <= H-1 && get_flow_pos(H, W, map, i+1, j) == my_pos)
					{
						map[i+1][j].level = level+1;
						map[i+1][j].id = map[i][j].id;
						processed++;
					}
				}
			}
		}


		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
		printf("\n");
		print_map(H, W, map);

	}
	return 0;
}
