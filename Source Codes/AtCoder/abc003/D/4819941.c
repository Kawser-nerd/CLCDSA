M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
long t[900][900],a;
f(long n){return n?n*f(n-1)%M:1;}
p(long x,int n){for(a=1;n;n/=2)n%2?a=a*x%M:0,x=x*x%M;return a;}
main(i){
	scanf("%d%d%d%d%d%d",&R,&C,&X,&Y,&D,&L);
	S=D+L;
	t[0][0]=1;
	for(;i<S;++i){
		for(k=0;k<R*C;++k){
			if(!t[i-1][k])continue;
			for(j=k;j<R*C;++j){
				r=j/C+1;
				c=j%C+1;
				s=k/C+1;
				d=k%C+1;
				if(r*c>i&s<=r&d<=c&s*d>=i){
					if(s<r&d<c)t[i][j]+=t[i-1][k]*4;
					else if(s<r)t[i][j]+=t[i-1][k]*d*2;
					else if(d<c)t[i][j]+=t[i-1][k]*s*2;
					else t[i][j]+=t[i-1][k]*(s*d-i);
					t[i][j]%=M;
				}
			}
		}
	}
	printf("%d\n",t[S-1][~-Y+~-X*C]*p(f(D),M-2)%M*p(f(L),M-2)%M*(R-X+1)*(C-Y+1)%M);
} ./Main.c:1:1: warning: data definition has no type or storage class
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘R’ [-Wimplicit-int]
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
         ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘C’ [-Wimplicit-int]
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
           ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘X’ [-Wimplicit-int]
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
             ^
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘Y’ [-Wimplicit-int]
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
               ^
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘D’ [-Wimplicit-int]
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
                 ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘L’ [-Wimplicit-int]
 M=1e9+7,R,C,X,Y,D,L,S;j,k,r,c,s,d;
                   ...