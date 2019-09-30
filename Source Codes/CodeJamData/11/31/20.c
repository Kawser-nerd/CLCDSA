#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 50
#define MAX_COLS 50

#define WHITE_PIXEL '.'
#define BLUE_PIXEL '#'
#define RED_PIXEL_1 '/'
#define RED_PIXEL_2 '\\'

int main(void)
{
	FILE *f_in, *f_out;
	if (!(f_in = fopen("A.in", "r")))
	{
		printf("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("A.out", "w+");
	
	int i, j, k, n;
	int cols, rows;
	int error;
	char ch;
	char grid[MAX_ROWS][MAX_COLS];
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d:\n", i+1);
		
		fscanf(f_in, "%d %d\n", &rows, &cols);
		//On a récupéré la grille.
		for(j = 0; j < rows; j++)
		{
			for(k = 0; k < cols; k++)
			{
				ch = '\n';
				while (ch == '\n') fscanf(f_in, "%c", &ch);
				grid[j][k] = ch;
			}
		}
		//On va maintenant la transformer.
		error = 0;
		for(j = 0; j < rows; j++)
		{
			for(k = 0; k < cols; k++)
			{
				switch(grid[j][k])
				{
					case BLUE_PIXEL:
						if (k == cols-1 || j == rows-1)
						{
							error = 1;
						}
						else
						{
							if (grid[j+1][k] == BLUE_PIXEL && grid[j][k+1] == BLUE_PIXEL && grid[j+1][k+1] == BLUE_PIXEL)
							{
								grid[j][k] = RED_PIXEL_1;
								grid[j][k+1] = RED_PIXEL_2;
								grid[j+1][k] = RED_PIXEL_2;
								grid[j+1][k+1] = RED_PIXEL_1;
							}
							else
							{
								error = 1;
							}
						}
						break;
					default:
						break;
				}
				if (error == 1) break;
			}
			if (error == 1) break;
		}
		//On affiche la sortie selon qu'il y a une erreur ou pas.
		if (error == 1)
		{
			fprintf(f_out, "Impossible\n");
		}
		else
		{
			for(j = 0; j < rows; j++)
			{
				for(k = 0; k < cols; k++)
				{
					fprintf(f_out, "%c", grid[j][k]);
				}
				fprintf(f_out, "\n");
			}
		}
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
