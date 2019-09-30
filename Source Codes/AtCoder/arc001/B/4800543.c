main(a,b){scanf("%d%d",&a,&b);a=abs(a-=b);b=a/10;a-=b*10;b+=(a<3?a:(a<8?abs(5-a)+1:(10-a)+1));printf("%d\n",b);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){scanf("%d%d",&a,&b);a=abs(a-=b);b=a/10;a-=b*10;b+=(a<3?a:(a<8?abs(5-a)+1:(10-a)+1));printf("%d\n",b);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d",&a,&b);a=abs(a-=b);b=a/10;a-=b*10;b+=(a<3?a:(a<8?abs(5-a)+1:(10-a)+1));printf("%d\n",b);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:33: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d",&a,&b);a=abs(a-=b);b=a/10;a-=b*10;b+=(a<3?a:(a<8?abs(5-a)+1:(10-a)+1));printf("%d\n",b);}
                                 ^
./Main.c:1:95: warning: implici...