main(k,s){scanf("%d%d",&k,&s);s=fmin(3*k-s,s);printf("%d",(k<s?6*k*s-2*s*s-3*k*k+3*k+2:(s+1)*(s+2))/2);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(k,s){scanf("%d%d",&k,&s);s=fmin(3*k-s,s);printf("%d",(k<s?6*k*s-2*s*s-3*k*k+3*k+2:(s+1)*(s+2))/2);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(k,s){scanf("%d%d",&k,&s);s=fmin(3*k-s,s);printf("%d",(k<s?6*k*s-2*s*s-3*k*k+3*k+2:(s+1)*(s+2))/2);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:33: warning: implicit declaration of function ‘fmin’ [-Wimplicit-function-declaration]
 main(k,s){scanf("%d%d",&k,&s);s=fmin(3*k-s,s);printf("%d",(k<s?6*k*s-2*s*s-3*k*k+3*k+2:(s+1)*(s+2))/2);}
                                 ^
./Main.c:1:33: warning: incompatible implicit declarat...