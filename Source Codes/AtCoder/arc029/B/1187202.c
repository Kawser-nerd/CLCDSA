float a,b;
int f(float c,float d)
{
	if(a<c&&b<d)return 1;
	float q=0,p=1.57079632679,t;
	for(int i=0;i<99;i++)
	{
		t=(q+p)/2;
		if(a*sin(t)+b*cos(t)<c&&a*cos(t)+b*sin(t)<d)return 1;
		else if(a*sin(t)+b*cos(t)>c)p=t;
		else q=t;
	}
	return 0;
}
main()
{
	float c,d,e;
	int n;
	scanf("%f%f%d",&a,&b,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%f%f",&c,&d);
		int s=f(c,d)||f(d,c);
		if(!s)e=a,a=b,b=e;
		s|=f(c,d)||f(d,c);
		puts(s?"YES":"NO");
	}
} ./Main.c: In function ‘f’:
./Main.c:9:8: warning: implicit declaration of function ‘sin’ [-Wimplicit-function-declaration]
   if(a*sin(t)+b*cos(t)<c&&a*cos(t)+b*sin(t)<d)return 1;
        ^
./Main.c:9:8: warning: incompatible implicit declaration of built-in function ‘sin’
./Main.c:9:8: note: include ‘<math.h>’ or provide a declaration of ‘sin’
./Main.c:9:17: warning: implicit declaration of function ‘cos’ [-Wimplicit-function-declaration]
   if(a*sin(t)+b*cos(t)<c&&a*cos(t)+b*sin(t)<d)return 1;
                 ^
./Main.c:9:17: warning: incompatible implicit declaration of built-in function ‘cos’
./Main.c:9:17: note: include ‘<math.h>’ or provide a declaration of ‘cos’
./Main.c: At top level:
./Main.c:15:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:19:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%f%f%d",&a,&b,&n);
  ^
./Main.c:19:2: warning: incompatible implicit declaration of built-in func...