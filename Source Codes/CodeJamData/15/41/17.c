#include<stdio.h>
unsigned short safe[102][102];
char inp[102][102];
char fast_char_var;
#define	fast_unsigned_dtype	unsigned short
fast_unsigned_dtype fast_unsigned_var;
fast_unsigned_dtype fast_unsigned()
{
	fast_char_var=getchar_unlocked();
	while(fast_char_var<48||fast_char_var>57)
		fast_char_var=getchar_unlocked();
	fast_unsigned_var=0;
	while(fast_char_var>47&&fast_char_var<58)
	{
		fast_unsigned_var=(fast_unsigned_var<<1)+(fast_unsigned_var<<3)+fast_char_var-48;
		fast_char_var=getchar_unlocked();
	}
	return fast_unsigned_var;
}
int main()
{
	unsigned short test_cases,r,c,i,j,count,x,y,flag,temptest;
	test_cases=fast_unsigned();
	//scanf("%hu",&test_cases);
	for(temptest=1;temptest<=test_cases;temptest++)
	{
		count=0;
		//scanf("%hu%hu",&r,&c);
		r=fast_unsigned();
		c=fast_unsigned();
		//fast_char_var=getchar_unlocked();
		//while(fast_char_var!='.'&&fast_char_var!='^'&&fast_char_var!='v'&&fast_char_var!='>'&&fast_char_var!='<')
		//	fast_char_var=getchar_unlocked();
		//putchar_unlocked(fast_char_var);
		//putchar_unlocked('\n');
		for(i=0;i<r;i++)
		{
			//scanf("%s",*(inp+i));

			fast_char_var=getchar_unlocked();
			for(j=0;j<c;j++)
			{
				safe[i][j]=0;
				inp[i][j]=fast_char_var;
				fast_char_var=getchar_unlocked();
			}
		}
		//for(i=0;i<r;i++)
		//{
		//	for(j=0;j<r;j++)
		//		putchar_unlocked(inp[i][j]);
		//	putchar_unlocked('\n');
		//}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				switch(inp[i][j])
				{
					case '.':
						safe[i][j]=1;
						break;
					case '^':
						for(x=0;x<i;x++)
							if(inp[x][j]!='.')
							{
								safe[i][j]=1;
								break;
							}
						break;
					case 'v':
						for(x=i+1;x<r;x++)
							if(inp[x][j]!='.')
							{
								safe[i][j]=1;
								break;
							}
						break;
					case '<':
						for(y=0;y<j;y++)
							if(inp[i][y]!='.')
							{
								safe[i][j]=1;
								break;
							}
						break;
					case '>':
						for(y=j+1;y<c;y++)
							if(inp[i][y]!='.')
							{
								safe[i][j]=1;
								break;
							}
						break;
				}
			}
		flag=0;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(!safe[i][j])
				{
					//printf("%lu %lu\n", i,j);
					count++;
					//try left
					for(y=j+1;y<c&&(!safe[i][j]);y++)
						if(inp[i][y]!='.')
						{
							safe[i][j]=1;
							break;
						}
					for(y=0;y<j&&(!safe[i][j]);y++)
						if(inp[i][y]!='.')
						{
							safe[i][j]=1;
							break;
						}
					for(x=i+1;x<r&&(!safe[i][j]);x++)
						if(inp[x][j]!='.')
						{
							safe[i][j]=1;
							break;
						}
					for(x=0;x<i&&(!safe[i][j]);x++)
						if(inp[x][j]!='.')
						{
							safe[i][j]=1;
							break;
						}
					if(!safe[i][j])
					{
						flag=1;
						goto out;
					}
				}
		out:;
		if(flag)
			printf("Case #%hu: IMPOSSIBLE\n",temptest);
		else
			printf("Case #%hu: %hu\n",temptest,count);
	}
	return 0;
}