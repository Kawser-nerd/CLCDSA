C(int*a,int*b){return*a-*b;}
dp[11111];
n,m,a[9];
i,j,M;
c[]={0,2,5,5,4,5,6,3,7,6};
main(){
	scanf("%d%d",&n,&m);
	for(;~scanf("%d",a+i++););
	qsort(a,m,4,C);
	for(i=0;i++<n;){
		M=-9;
		for(j=m;j--;)M=fmax(M,c[a[j]]>i?M:dp[i-c[a[j]]]+1);
		dp[i]=M;
	}
	for(i=n;dp[i];){
		for(j=m;j--&&(i<c[a[j]]||dp[i-c[a[j]]]+1-dp[i]););
		putchar(a[j]+48);
		i-=c[a[j]];
	}
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 C(int*a,int*b){return*a-*b;}
 ^
./Main.c:2:1: warning: data definition has no type or storage class
 dp[11111];
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘dp’ [-Wimplicit-int]
./Main.c:3:1: warning: data definition has no type or storage class
 n,m,a[9];
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:3:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 n,m,a[9];
   ^
./Main.c:3:5: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 n,m,a[9];
     ^
./Main.c:4:1: warning: data definition has no type or storage class
 i,j,M;
 ^
./Main.c:4:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:4:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j,M;
   ^
./Main.c:4:5: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
 i,j,M;
     ^
./Main.c:5:...