long a,b;main(){scanf("%ld%ld",&a,&b)<puts(abs(a-b)<2?"Brown":"Alice");} ./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long a,b;main(){scanf("%ld%ld",&a,&b)<puts(abs(a-b)<2?"Brown":"Alice");}
          ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long a,b;main(){scanf("%ld%ld",&a,&b)<puts(abs(a-b)<2?"Brown":"Alice");}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:39: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 long a,b;main(){scanf("%ld%ld",&a,&b)<puts(abs(a-b)<2?"Brown":"Alice");}
                                       ^
./Main.c:1:44: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
 long a,b;main(){scanf("%ld%ld",&a,&b)<puts(abs(a-b)<2?"Brown":"Alice");}
                                            ^