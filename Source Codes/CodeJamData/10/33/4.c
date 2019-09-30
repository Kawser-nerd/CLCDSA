#include <stdio.h>
#define MAXN 512
#define MAXM 512

void readline(FILE * fin)
{
	while(getc(fin)!='\n')
		;
}

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

int main(int argc, char *argv[]){
	FILE *fin,*fout;
	int tcase,T,types,r,i,j,k,oldmax,maxr,curi,curj,N,M,count[MAXM+MAXN+1];//,size[MAXM][MAXN];
	char board[MAXM][MAXN];

	if (argc>1)
		fin=fopen(argv[1],"r");
	else
		fin=fopen("chess.in","r");
	if (!fin)
		return 1;
	if (argc>2)
		fout=fopen(argv[2],"w");
	else
		fout=fopen("chess.out","w");
	if (!fout)
	{
		fclose(fin);
		return 1;
	}
	fscanf(fin,"%d",&T);
	for (tcase=1;tcase<=T;tcase++)
	{
		fscanf(fin,"%d",&M);
		fscanf(fin,"%d",&N);
		readline(fin);
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j+=4)
			{
				char t[2];
				unsigned ch;

				t[1] = 0;
				t[0] = getc(fin);
				sscanf(t,"%x",&ch);
				for(k=0;k<4;k++)
					board[i][j+k] = (!(ch & (1 << (3-k)))) ^ ((i+j+k) & 1);
			}
			readline(fin);
		}
		types = 0;
		oldmax = N+M;
		for(i=0;i<=min(N,M);i++)
			count[i]=0;
		while(1)
		{
			maxr = 0;
			for(i=0;i<M;i++)
			{
				for(j=0;j<N;j++)
				{
					if(board[i][j]>1)
						continue;
					for(r=1;;r++)
					{
						if(i+r>=M || j+r>=N)
							break;
						for(k=0;k<=r;k++)
							if(board[i+k][j+r]!=board[i][j])
								break;
						if(k<=r)
							break;
						for(k=0;k<r;k++)
							if(board[i+r][j+k]!=board[i][j])
								break;
						if(k<r)
							break;
					}
					if(r>maxr)
					{
						maxr = r;
						curi = i;
						curj = j;
					}
				}
			}
			if(!maxr)
				break;
			for(i=curi;i<curi+maxr;i++)
				for(j=curj;j<curj+maxr;j++)
					board[i][j]=2;
			count[maxr]++;
			if(maxr<oldmax)
			{
				oldmax = maxr;
				types++;
			}
		}
		fprintf(fout,"Case #%d: %d\r\n",tcase,types);
		for(i=min(N,M);i>0;i--)
		{
			if(count[i])
				fprintf(fout,"%d %d\r\n",i,count[i]);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
