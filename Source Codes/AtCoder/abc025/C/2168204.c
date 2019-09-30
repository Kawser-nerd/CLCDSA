a[9],b[5][3],l,d,i,j;
/*f(s,m,i,j){
	m=d%2?1e9:0;
	if(d-9)for(i=3;i--;)for(j=3;j--;)a[i][j]||(s=f(a[i][j]=d++%2+1),m=--d%2?m>s?s:m:m<s?s:m,a[i][j]=0);
	else{
		m=0;
		for(i=2;i--;)for(j=3;j--;m+=a[i][j]-a[i+1][j]?0:b[i][j]);
		for(i=3;i--;)for(j=2;j--;m+=a[i][j]-a[i][j+1]?0:b[i+2][j]);
	}
	return m;
}*/
f(s,m,i){
	m=d%2?1e9:0;
	if(d-9)for(i=9;i--;a[i]||(s=f(a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));
	else{
		m=0;
		for(i=6;i--;)m+=a[i]-a[i+3]?0:b[i/3][i%3];
		for(i=8;i-->=0;i-=i%3<1)m+=a[i]-a[i+1]?0:b[i/3+2][i%3];
	}
	return m;
}
main(){
	for(;i<5;i++)for(j=0;j<2+(i<2);l+=b[i][j++])scanf("%d",b[i]+j);
	printf("%d\n%d\n",f(),l-f());
} ./Main.c:1:1: warning: data definition has no type or storage class
 a[9],b[5][3],l,d,i,j;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a[9],b[5][3],l,d,i,j;
      ^
./Main.c:1:14: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 a[9],b[5][3],l,d,i,j;
              ^
./Main.c:1:16: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 a[9],b[5][3],l,d,i,j;
                ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 a[9],b[5][3],l,d,i,j;
                  ^
./Main.c:1:20: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 a[9],b[5][3],l,d,i,j;
                    ^
./Main.c:12:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(s,m,i){
 ^
./Main.c: In function ‘f’:
./Main.c:12:1: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:12:1: warning: typ...