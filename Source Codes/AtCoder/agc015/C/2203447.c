H,W,Q,y,x,y1,x1,
A[2001][2001],
B[2001][2001],
C[2001][2001];
char S[2001][2001];
main(){
	scanf("%d%d%d%*c",&H,&W,&Q);
	for(y=0;y++<H;){
		gets(S[y]+1);
	}
	for(y=0;y++<H;){
		for(x=0;x++<W;){
			A[y][x]=A[y][x-1]+A[y-1][x]-A[y-1][x-1]+S[y][x]%2;
			B[y][x]=B[y][x-1]+B[y-1][x]-B[y-1][x-1]+S[y-1][x]*S[y][x]%2;
			C[y][x]=C[y][x-1]+C[y-1][x]-C[y-1][x-1]+S[y][x-1]*S[y][x]%2;
		}
	}
	for(;~scanf("%d%d%d%d",&y1,&x1,&y,&x);){
		printf("%d\n",
			A[y][x]-A[y1-1][x]-A[y][x1-1]+A[y1-1][x1-1]
			-(B[y][x]-B[y1][x]-B[y][x1-1]+B[y1][x1-1])
			-(C[y][x]-C[y1-1][x]-C[y][x1]+C[y1-1][x1])
		);
	}
} ./Main.c:1:1: warning: data definition has no type or storage class
 H,W,Q,y,x,y1,x1,
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘H’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘W’ [-Wimplicit-int]
 H,W,Q,y,x,y1,x1,
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘Q’ [-Wimplicit-int]
 H,W,Q,y,x,y1,x1,
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 H,W,Q,y,x,y1,x1,
       ^
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 H,W,Q,y,x,y1,x1,
         ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘y1’ [-Wimplicit-int]
 H,W,Q,y,x,y1,x1,
           ^
./Main.c:1:11: warning: built-in function ‘y1’ declared as non-function
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘x1’ [-Wimplicit-int]
 H,W,Q,y,x,y1,x1,
              ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
 A[...