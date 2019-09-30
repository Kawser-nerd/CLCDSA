char b[19][22];
int d[]={1,0,1,1,-1},cnt[19][19],BC,WC,C;
main()
{
	for(int i=0;i<19;i++)gets(b[i]);
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(b[i][j]=='.')continue;
			C+=2*(b[i][j]=='o')-1;
			for(int r=0;r<4;r++)
			{
				int now=1;
				for(int k=0;k<5;k++)
				{
					int tx=i+d[r]*k,ty=j+d[r+1]*k;
					if(tx<0||ty<0||tx>18||ty>18||b[tx][ty]!=b[i][j])
					{
						now=0;
						break;
					}
				}
				if(now)
				{
					if(b[i][j]=='o')BC++;
					else WC++;
					for(int k=0;k<5;k++)cnt[i+d[r]*k][j+d[r+1]*k]++;
				}
			}
		}
	}
	for(int i=0;i<19;i++)for(int j=0;j<19;j++)if(cnt[i][j]==(C-1?C==BC?WC:-1:WC?-1:BC))exit(!puts("YES"));
	puts("NO");
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:5:23: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  for(int i=0;i<19;i++)gets(b[i]);
                       ^
./Main.c:33:85: warning: implicit declaration of function ‘exit’ [-Wimplicit-function-declaration]
  for(int i=0;i<19;i++)for(int j=0;j<19;j++)if(cnt[i][j]==(C-1?C==BC?WC:-1:WC?-1:BC))exit(!puts("YES"));
                                                                                     ^
./Main.c:33:85: warning: incompatible implicit declaration of built-in function ‘exit’
./Main.c:33:85: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
./Main.c:33:91: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  for(int i=0;i<19;i++)for(int j=0;j<19;j++)if(cnt[i][j]==(C-1?C==BC?WC:-1:WC?-1:BC))exit(!puts("YES"));
                                                                                           ...