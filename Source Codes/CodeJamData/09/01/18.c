#include <stdio.h>

char words[5000][16];

int i, j, k;
int main()
{
	int L, D, N;



	scanf("%d %d %d\n", &L, &D, &N);

	for (i=0; i<D; i++)
	{
		scanf("%s\n",words[i]);
		for (j=0; j<L; j++)
			words[i][j]-='a';
	}


	for (i=1; i<=N; i++)
	{
		int wordcount=0;
		int T[15][26] = { {0}};
		char ch;
	
		for (j=0; j<L ; j++)
		{
			scanf("%c", &ch);
		
			if (ch=='(')
			{
				do {
					scanf("%c",&ch);
					if (ch==')') break;
					T[j][ch-'a']=1;
				} while (ch!=')');
			} else
				T[j][ch-'a'] = 1;
		}
		while (ch!='\n')
			scanf("%c", &ch);

		for (k=0; k<D; k++)
		{
			char *currword=words[k];
			for (j=0; j<L; j++)
			{
				if (T[j][currword[j]]==0)
					goto nextword;
				
			}
				wordcount++;
			nextword:
				;
		}

		printf("Case #%d: %d\n", i, wordcount);
	}
}



