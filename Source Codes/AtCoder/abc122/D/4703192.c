M=1e9+7,D[101][64];
i,j,k,t,T;
main(n){
for(D[0][63]=scanf("%d",&n);T=i++<n;)for(j=0;k<4?:(k=0,++j<64);D[i][T]%=M)t=j*4+k++,D[i][T=t%64]+=T-9&&T-33&&T-6&&t-25&&t-41&&t-57&&t-37&&t-45?D[i-1][j]:0;
for(;j--;T%=M)T+=D[n][j];
printf("%d",T);
}
/////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ./Main.c:1:1: warning: data definition has no type or storage class
 M=1e9+7,D[101][64];
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘D’ [-Wimplicit-int]
 M=1e9+7,D[101][64];
         ^
./Main.c:2:1: warning: data definition has no type or storage class
 i,j,k,t,T;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j,k,t,T;
   ^
./Main.c:2:5: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 i,j,k,t,T;
     ^
./Main.c:2:7: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 i,j,k,t,T;
       ^
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘T’ [-Wimplicit-int]
 i,j,k,t,T;
         ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n){
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning...