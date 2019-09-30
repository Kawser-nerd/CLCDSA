char b[19][22];
int d[]={1,0,1,1,-1};
int cnt[19][19],BC,WC;
main()
{
	int bc=0,wc=0;
	for(int i=0;i<19;i++)
	{
		gets(b[i]);
		for(int j=0;j<19;j++)
		{
			if(b[i][j]=='o')bc++;
			else if(b[i][j]=='x')wc++;
		}
	}
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(b[i][j]=='.')continue;
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
		if(WC)puts("NO");
		else
		{
			for(int i=0;i<19;i++)for(int j=0;j<19;j++)
			{
				if(cnt[i][j]==BC)
				{
					puts("YES");
					return 0;
				}
			}
			puts("NO");
		}
	}
	else if(bc-wc==0)
	{
		if(BC)puts("NO");
		else
		{
			for(int i=0;i<19;i++)for(int j=0;j<19;j++)
			{
				if(cnt[i][j]==WC)
				{
					puts("YES");
					return 0;
				}
			}
			puts("NO");
		}
	}
	else puts("NO");
} ./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:9:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(b[i]);
   ^
./Main.c:44:9: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   if(WC)puts("NO");
         ^
/tmp/ccMZwpuv.o: In function `main':
Main.c:(.text.startup+0x1e): warning: the `gets' function is dangerous and should not be used.