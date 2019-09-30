long m=1e9+7,s=1,D[41][1<<17]={1};
X,j,k,T,M=1<<17,q;
main(i,n){
	scanf("%d%d%d%d",&n,&q,&X,&T);
	for(X=((1<<q|1)<<X|1)<<T-1;k/M?k=0,++j>9?s=s*10%m,j=0,i++<n:1:1;~T&X?D[i][T&=M-1]+=D[i-1][k-1],D[i][T]%=m:0)T=k+++k<<j;
	for(;M--;)s+=m-D[n][M];
	printf("%d",s%m);
} ./Main.c:2:1: warning: data definition has no type or storage class
 X,j,k,T,M=1<<17,q;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘X’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 X,j,k,T,M=1<<17,q;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 X,j,k,T,M=1<<17,q;
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘T’ [-Wimplicit-int]
 X,j,k,T,M=1<<17,q;
       ^
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
 X,j,k,T,M=1<<17,q;
         ^
./Main.c:2:17: warning: type defaults to ‘int’ in declaration of ‘q’ [-Wimplicit-int]
 X,j,k,T,M=1<<17,q;
                 ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,n){
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:4:2: wa...