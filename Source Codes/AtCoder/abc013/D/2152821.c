t[100][1<<17],n,d,i,j,k,l;
f(i){~scanf("%d",&i)?f(i),t[0][i]^=t[0][i+1]^=t[0][i]^=t[0][i+1]:0;}
main(){
	for(scanf("%d%*d%d",&n,&d);i++<n;)t[0][i]=i;
	for(f(i);j<99;j++)for(i=0;i++<n;)t[j+1][i]=t[j][t[j][i]];
	for(;l++<n;printf("%d\n",i))for(k=d,i=l,j=0;k;k/=2)k%2&&(i=t[j][i]),j++;
} ./Main.c:1:1: warning: data definition has no type or storage class
 t[100][1<<17],n,d,i,j,k,l;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 t[100][1<<17],n,d,i,j,k,l;
               ^
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 t[100][1<<17],n,d,i,j,k,l;
                 ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 t[100][1<<17],n,d,i,j,k,l;
                   ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 t[100][1<<17],n,d,i,j,k,l;
                     ^
./Main.c:1:23: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 t[100][1<<17],n,d,i,j,k,l;
                       ^
./Main.c:1:25: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 t[100][1<<17],n,d,i,j,k,l;
                         ^
./Main.c:2:1: war...