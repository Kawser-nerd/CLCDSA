main(a,b){(a=getchar())>32?main(a,a):puts(b^84?"NO":"YES");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){(a=getchar())>32?main(a,a):puts(b^84?"NO":"YES");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:14: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a,b){(a=getchar())>32?main(a,a):puts(b^84?"NO":"YES");}
              ^
./Main.c:1:38: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a,b){(a=getchar())>32?main(a,a):puts(b^84?"NO":"YES");}
                                      ^