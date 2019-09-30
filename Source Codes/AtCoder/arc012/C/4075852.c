char b[19][22],B;
int d[]={1,0,1,1,-1};
int f()
{
	int ans=0,bc=0,wc=0;
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
				ans|=now;
			}
		}
	}
	return ans||bc-wc>1||bc-wc<0;
}
main()
{
	int wc=0,bc=0;
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
			B=b[i][j];
			b[i][j]='.';
			if((bc-wc==1||bc-wc==0)&&!f())exit(!puts("YES"));
			b[i][j]=B;
		}
	}
	puts("NO");
} ./Main.c:31:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:36:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(b[i]);
   ^
./Main.c:49:34: warning: implicit declaration of function ‘exit’ [-Wimplicit-function-declaration]
    if((bc-wc==1||bc-wc==0)&&!f())exit(!puts("YES"));
                                  ^
./Main.c:49:34: warning: incompatible implicit declaration of built-in function ‘exit’
./Main.c:49:34: note: include ‘<stdlib.h>’ or provide a declaration of ‘exit’
./Main.c:49:40: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
    if((bc-wc==1||bc-wc==0)&&!f())exit(!puts("YES"));
                                        ^
/tmp/ccwQUwIO.o: In function `main':
Main.c:(.text.startup+0x1e): warning: the `gets' function is dangerous and should not be used.