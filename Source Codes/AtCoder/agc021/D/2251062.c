#define F(a,b,c) for(a=b;a<=c;++a)
#define upd(a,b) (a<b?a=b:0)
char s[301];c,i,j,k,n,f[301][301][301],a;main(){
scanf("%s%d",s,&c);for(n=0;s[n];++n);F(i,0,n)f[0][i][i]=1;
F(k,0,c)F(i,1,n)F(j,i,n-1)
if(s[j-i]-s[j]){if(k)upd(f[k][j-i][j],f[k-1][j-i+1][j-1]+2);
upd(f[k][j-i][j],f[k][j-i+1][j]);upd(f[k][j-i][j],f[k][j-i][j-1]);
}else upd(f[k][j-i][j],f[k][j-i+1][j-1]+2);
F(i,0,c)upd(a,f[i][0][n-1]);printf("%d\n",a);exit(0);} ./Main.c:3:13: warning: data definition has no type or storage class
 char s[301];c,i,j,k,n,f[301][301][301],a;main(){
             ^
./Main.c:3:13: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:3:15: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 char s[301];c,i,j,k,n,f[301][301][301],a;main(){
               ^
./Main.c:3:17: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 char s[301];c,i,j,k,n,f[301][301][301],a;main(){
                 ^
./Main.c:3:19: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 char s[301];c,i,j,k,n,f[301][301][301],a;main(){
                   ^
./Main.c:3:21: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 char s[301];c,i,j,k,n,f[301][301][301],a;main(){
                     ^
./Main.c:3:23: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 char s[301];c,i,j,k,n,f[301][301][301],a;main(){
                       ^
./Main.c:3:40: warn...