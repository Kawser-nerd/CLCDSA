m[13],s[2<<9],a,b;
main(i)
{
	for(;i<367;i++)s[i]=i%7<2;
	for(i=1;i<12;i++)m[i+1]=m[i]+(i==2?29:i==4||i==6||i==9||i==11?30:31);
	for(scanf("%*d");~scanf("%d/%d",&a,&b);s[i]=1)for(i=m[a]+b;s[i];i++);
	for(a=i=0;i<367;a=a<b?b:a)b+=s[i++]?1:-b;
	printf("%d",a);
} ./Main.c:1:1: warning: data definition has no type or storage class
 m[13],s[2<<9],a,b;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 m[13],s[2<<9],a,b;
       ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 m[13],s[2<<9],a,b;
               ^
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 m[13],s[2<<9],a,b;
                 ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i)
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:6:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%*d");~scanf("%d/%d",&a,&b);s[i]=1)for(i=m[a]+b;s[i];i++);
      ^
./Main.c:6:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:6: note: include ‘<stdi...