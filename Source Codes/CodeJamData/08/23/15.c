/*
 	CODED BY DAVID RIOS PUIG
	FOR GOOGLE CODE JAM
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void getname(char *name, FILE *fin);

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./p1 A-small.in\n");
		return 0;
	}
	
	//File input & File output
	FILE *fin, *fout;

	//Number of case
	int ncase, k;

	//cards
	int K,card,cnt;
	
	//pos
	int pos;

	//array
	int *deck,*mar,*index;

	int i,final;

	//Opening input file
	if((fin=fopen(argv[1],"r")) == NULL)
	{
		printf("Error opening input file\n");
		return -1;
	}

	//Setting number of case
	fscanf(fin,"%d\n", &ncase);

	//Opening output file
	if((fout=fopen("A-small.out","w")) == NULL)
	{
		printf("Error opening output file\n");
		return -1;
	}

	for(k=0;k<ncase; k++)
	{
		final = 0;
		//number of cards
		fscanf(fin,"%d\n", &K);
		
		printf("%d CARDS\n",K);
		
		//positions
		fscanf(fin,"%d ",&pos);
		deck = malloc(K *sizeof(int));
		mar = malloc(K *sizeof(int));

		index = malloc(pos * sizeof(int));
		
		
		//FALTA ESCANEJAR LES POSICIONS
		for(i=0;i<pos-1;i++)
		{
			fscanf(fin,"%d ",&index[i]);
		}
		fscanf(fin,"%d\n",&index[i]);

		
		for(i = 0; i<K;i++)
			mar[i]=0;

		card = 1;
		cnt = 1;
		while(final == 0)
		{
			for(i=0; i<K;i++)
			{
				if(mar[i]==0 && cnt == card)
				{
					mar[i]=1;
					deck[i]=card;
					card++;
					cnt=1;
				}
				else 
				{
					if (mar[i] == 0)
						cnt++;
				}
			}

			final = 1;
			for(i=0;i<K;i++)
			{
				if(mar[i]==0)
				final = 0;
			}

		}

		fprintf(fout,"Case #%d: ", k+1);
		for(i=0;i<pos-1;i++)
		{
			fprintf(fout,"%d ",deck[index[i]-1]);
		}
		fprintf(fout,"%d\n",deck[index[i]-1]);
		free(deck);
		free(mar);
		free(index);
	}
	fclose(fout);
	fclose(fin);
	return 0;
}

void getname(char *name, FILE *fin)
{
	char c;
	int i=0;
	
	while(1)
	{
		if(fscanf(fin,"%c",&c) != EOF)
		{
			if(c!= '\n')
			{
				name[i++]=c;
			}
			else
			{
				name[i]='\0';
				break;
			}
		}
		else
		{
			name[i]='\0';
			break;
		}
	}
}
