char b[19][22];
int d[]={1,0,1,1,-1},cnt[19][19],BC,WC,bc,wc;
main()
{
	for(int i=0;i<19;i++)gets(b[i]);
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(b[i][j]=='.')continue;
			if(b[i][j]=='o')bc++;
			else wc++;
			for(int r=0;r<4;r++)
			{
				int now=1;
				for(int k=1;k<5;k++)
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
	if(bc-wc==1)
	{
		if(!WC)for(int i=0;i<19;i++)for(int j=0;j<19;j++)if(cnt[i][j]==BC)
		{
			puts("YES");
			return 0;
		}
	}
	else if(bc-wc==0)
	{
		if(!BC)for(int i=0;i<19;i++)for(int j=0;j<19;j++)if(cnt[i][j]==WC)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:5:23: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  for(int i=0;i<19;i++)gets(b[i]);
                       ^
./Main.c:38:4: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
    puts("YES");
    ^
/tmp/ccNOZrkt.o: In function `main':
Main.c:(.text.startup+0x1d): warning: the `gets' function is dangerous and should not be used.