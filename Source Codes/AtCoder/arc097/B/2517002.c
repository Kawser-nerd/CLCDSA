int p[1<<17];
int find(int a){return a-p[a]?p[a]=find(p[a]):a;}
int n,m,x,y,cnt;
int P[1<<17];
main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i++<n;)
	{
		p[i]=i;
		scanf("%d",P+i);
	}
	for(;~scanf("%d%d",&x,&y);)
	{
		x=find(x);y=find(y);
		if(x-y)p[x]=y;
	}
	for(int i=0;i++<n;)cnt+=find(P[i])==find(i);
	printf("%d",cnt);
} ./Main.c:5:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:7:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d",&n,&m);
  ^
./Main.c:7:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:7:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:19:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%d",cnt);
  ^
./Main.c:19:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:19:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’