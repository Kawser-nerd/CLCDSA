#define X 50

int r,n,m,k,s[8000][12],a[8000][12],b[12],x,y[8000];

void calc(int i,int pro,int nn)
{
	if(nn==n)
	{
		int j;
		for(j=0;j<k;j++) if(s[i][j]==pro) b[j]=1;
		return;
	}
	calc(i,pro*a[i][nn],nn+1);
	calc(i,pro,nn+1);
}

int ck(int i)
{
	memset(b,0,sizeof(b));
	calc(i,1,0);
	int j;
	for(j=0;j<k&&b[j];j++);
	if(j==k) return 1;
	return 0;
}

main()
{
	int i,j,l,tag;
	scanf("%*d");
	scanf("%d%d%d%d",&r,&n,&m,&k);
	for(i=0;i<r;i++)
	{
		for(j=0;j<k;j++) scanf("%d",&s[i][j]);
	}
	srand(22);
	puts("Case #1:");
	while(x<X)
	{
		x=0;
		for(i=0;i<r;i++)
		{
			tag=0;
			for(l=0;l<100&&!tag;l++)
			{
				for(j=0;j<n;j++) a[i][j]=2+rand()%(m-1);
				if(ck(i))
				{
					tag=1;
					y[i]=1;
					x++;
				}
			}
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<n;j++) printf("%d",a[i][j]);
		puts("");
	}
}
