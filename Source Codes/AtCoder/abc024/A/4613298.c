main(a,b,c,k,s,t){~scanf("%d",&a)?main(b,c,k,s,t,a):printf("%d\n",a*s+b*t-((s+=t)<k?0:c*s));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b,c,k,s,t){~scanf("%d",&a)?main(b,c,k,s,t,a):printf("%d\n",a*s+b*t-((s+=t)<k?0:c*s));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘t’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:20: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b,c,k,s,t){~scanf("%d",&a)?main(b,c,k,s,t,a):printf("%d\n",a*s+b*t-((s+=t)<k?0:c*s));}
                    ^
./Main.c:1:20: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:20: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:53: warning: im...