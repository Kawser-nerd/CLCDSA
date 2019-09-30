q[1<<18],t[1<<18],f[1<<18];i,a;
main(n){
	for(scanf("%d",&n);~scanf("%d",&a);i++)q[a]=i;
	for(f[n]=n;--i;t[a]?q[f[a]]<q[i]&q[i]<q[a]|q[i]<q[a]&q[a]<q[f[a]]|q[a]<q[f[a]]&q[f[a]]<q[i]?t[i]=t[a],f[i]=f[a]:(t[i]=t[f[i]=i+1]+1):q[i]<q[a]?t[i]=0,f[i]=i:(f[i]=i+(t[i]=1)))a=i+1;
	printf("%d",t[1]);
} ./Main.c:1:1: warning: data definition has no type or storage class
 q[1<<18],t[1<<18],f[1<<18];i,a;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘q’ [-Wimplicit-int]
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 q[1<<18],t[1<<18],f[1<<18];i,a;
          ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 q[1<<18],t[1<<18],f[1<<18];i,a;
                   ^
./Main.c:1:28: warning: data definition has no type or storage class
 q[1<<18],t[1<<18],f[1<<18];i,a;
                            ^
./Main.c:1:28: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:30: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 q[1<<18],t[1<<18],f[1<<18];i,a;
                              ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main...