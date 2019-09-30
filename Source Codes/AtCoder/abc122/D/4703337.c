M=1e9+7,D[101][64];j,T;main(i,n){for(D[0][63]=scanf("%d",&n);T=j<256?:(j=0,i++<n);j++)D[i][T=j%64]+=T-9&&T-33&&T-6&&j-25&&j-41&&j-57&&j-37&&j-45?D[i-1][j/4]:0,D[i][T]%=M;for(;j<64;T%=M)T+=D[n][j++];printf("%d",T);} ./Main.c:1:1: warning: data definition has no type or storage class
 M=1e9+7,D[101][64];j,T;main(i,n){for(D[0][63]=scanf("%d",&n);T=j<256?:(j=0,i++<n);j++)D[i][T=j%64]+=T-9&&T-33&&T-6&&j-25&&j-41&&j-57&&j-37&&j-45?D[i-1][j/4]:0,D[i][T]%=M;for(;j<64;T%=M)T+=D[n][j++];printf("%d",T);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘D’ [-Wimplicit-int]
 M=1e9+7,D[101][64];j,T;main(i,n){for(D[0][63]=scanf("%d",&n);T=j<256?:(j=0,i++<n);j++)D[i][T=j%64]+=T-9&&T-33&&T-6&&j-25&&j-41&&j-57&&j-37&&j-45?D[i-1][j/4]:0,D[i][T]%=M;for(;j<64;T%=M)T+=D[n][j++];printf("%d",T);}
         ^
./Main.c:1:20: warning: data definition has no type or storage class
 M=1e9+7,D[101][64];j,T;main(i,n){for(D[0][63]=scanf("%d",&n);T=j<256?:(j=0,i++<n);j++)D[i][T=j%64]+=T-9&&T-33&&T-6&&j-25&&j-41&&j-57&&j-37&&j-45?D[i-1][j/4]:0,D[i][T]%=M;for(;j<64;T%=M)T+=D[n][j++];printf("%d",T);}
                    ^
./Main.c:1:20: warning: type defa...