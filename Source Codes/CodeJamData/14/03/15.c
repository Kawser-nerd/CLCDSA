/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 12 April 2014
*/


#include<stdio.h>


int main()
{
	int i, j, i2, j2;
	int cases, T;

    int r, R, C, M;
    char array[50][50];
    char found, type;

	FILE *output = fopen("C-large.out", "w");
	FILE *input = fopen("C-large.in", "r");
	fscanf(input, "%d", &T);

	for(cases=1; cases<=T; cases++)
	{
		fscanf(input, "%d %d %d", &R, &C, &M);
		
		for(i=0; i<R; i++)
		    for(j=0; j<C; j++)
		        array[i][j] = '.';
		
		/* fill the columns per row */
		if(M==0) type=0;
		else type=1;

		for(i=0; i<R-2 && M>0; i++)
		    for(j=0; j<C && M>0; j++)
		    {
		        array[i][j] = '*';
		        i2=i;
		        j2=j;
		        M--;
		    }
		r=i;

		/* fill the rows per column */
		if(M>0) type=2;

		for(j=0; j<C-2 && M>0; j++)
		    for(i=r; i<R && M>0; i++)
		    {
		        array[i][j] = '*';
		        i2=i;
		        j2=j;
		        M--;
		    }

        array[R-1][C-1] = 'c';

        found=0;
        if(M==0)
        {
            i=i2;
            j=j2;
            if(type==0)
                found=1;
            else if(type==1)
            {
                if(i>R-3) { printf("     ERROR at type 1, i > R-3\n"); break; }
                if(j==C-2)
                {
                    if(i<=R-4)
                    {
                        if(C>2)
                        {
                            array[i][j] = '.';
                            array[i+1][0] = '*';
                            found=1;
                        }
                    }
                    else if(C>3)    // here i = R-3
                    {
                        array[i][j]   = '.';
                        array[i][j-1] = '.';
                        array[i+1][0] = '*';
                        array[i+2][0] = '*';
                        found=1;
                    }
                }
                else found=1;
            }
            else if(type==2)
            {
                if(i<=R-3) { printf("     ERROR at type 2, i <= R-3\n"); break; }
                if(i==R-2)
                {
                    if(j<C-4 && R>2 && C>4)
                    {
                        array[R-3][C-1] = '.';
                        array[R-3][C-2] = '.';
                        array[R-3][C-3] = '.';
                        array[R-2][j+1] = '*';
                        array[R-1][j+0] = '*';
                        array[R-1][j+1] = '*';
                        found=1;
                    }
                }
                else found=1;
            }
        }

        else if(M==1)
        {
                 if(R==1 && C>1) { array[R-1][C-2] = '*'; found=1; }
            else if(C==1 && R>1) { array[R-2][C-1] = '*'; found=1; }
        }

        else if(M==3 && R>1 && C>1)
        {
            array[R-1][C-2] = '*';
            array[R-2][C-1] = '*';
            array[R-2][C-2] = '*';
            found=1;
        }
        
        if(found)
        {
		    fprintf(output, "Case #%d:\n", cases);
		    printf("Case #%d:\n", cases);

		    for(i=0; i<R; i++)
		    {
		        for(j=0; j<C; j++)
		        {
		            fprintf(output, "%c", array[i][j]);
		            printf("%c", array[i][j]);
		        }
		        fprintf(output, "\n");
		        printf("\n");
		    }
		}
		else
        {
		    fprintf(output, "Case #%d:\nImpossible\n", cases);
		    printf("Case #%d:\nImpossible\n", cases);
        }
	}

	fclose(input);
	fclose(output);
}

