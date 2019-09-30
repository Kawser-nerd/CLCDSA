#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("refinput.in", "r");
	FILE * fout = fopen("refoutput.out", "r");

	int T, i, j;
	char tab[27];
	memset(tab, ' ', 26);
	tab[26] = 0;
	tab['q'-'a']='z';
	tab['e'-'a']='o';
	tab['y'-'a']='a';
	tab['z'-'a']='q';

	char in[120];
	char out[120];
	char ocase[20];
	int offset;
	char temp;
	char * outp;

	fscanf(fin, "%d\n", &T);

	for (i = 0; i < T; ++i)
	{
		fgets(in, 100, fin);
		fgets(out, 120, fout);
		//printf("%s\n", in);
		//printf("%s\n", out);
		sprintf(ocase, "Case #%d: ", i);
		offset = strlen(ocase);
		//printf("tste\n");
		for (j = 0; in[j] != 0; ++j)
		{
			if( (in[j] != ' ') && (in[j] >='a') && (in[j] <= 'z') )
			{
				tab[in[j]-'a']=out[j + offset];
			}
		}
	}

	//printf("%s\n", tab);
	//fscanf(fin, "%d", &T);
	//printf("%d\n", T);
	fclose(fin);
	fclose(fout);

	fin = fopen("input.in", "r");
	fout = fopen("output.out", "w");
	fscanf(fin, "%d\n", &T);

	for (i = 0; i < T; ++i)
	{
		memset(ocase, 0, 20);
		memset(in, 0, 120);
		memset(out, 0, 120);
		sprintf(ocase, "Case #%d: ", i+1);
		strcpy(out, ocase);
		fgets(in, 120, fin);
		fscanf(fin, "\n", &temp);

		offset = strlen(ocase);
		for (j = 0; in[j] != 0; ++j)
		{
			if( (in[j] != ' ') && (in[j] >='a') && (in[j] <= 'z') )
			{
				out[j + offset] = tab[in[j]-'a'];
			}
			else if (in[i] == '\n')
				out[j + offset] = 0;
			else
				out[j + offset] = ' ';
		}
		//printf("%s\n", out);
		if (out[strlen(out) - 1] == ' ')
		{
			out[strlen(out) - 1] = 0;
		}
		if (i != T -1)
		{
			fprintf (fout, "%s\n", out);
		}
		else
			fprintf (fout, "%s", out);
	}

	fclose(fin);
	fclose(fout);


	return 0;
}