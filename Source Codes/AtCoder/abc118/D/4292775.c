C(int*a,int*b){return*a-*b;}
p['~~'];a[9];i,j,M;c[]={0,2,5,5,4,5,6,3,7,6};
main(n,m){
	for(scanf("%d%d",&n,&m);~scanf("%d",a+j++););
	for(qsort(a,m,4,C);i++<n;p[i]=M)
		for(M=-9,j=m;j--;)M=fmax(M,c[a[j]]>i?M:p[i-c[a[j]]]+1);
	for(i=n;p[i];putchar(a[j]+48),i-=c[a[j]])
		for(j=m;j--&&(i<c[a[j]]||p[i-c[a[j]]]+1-p[i]););
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 C(int*a,int*b){return*a-*b;}
 ^
./Main.c:2:3: warning: multi-character character constant [-Wmultichar]
 p['~~'];a[9];i,j,M;c[]={0,2,5,5,4,5,6,3,7,6};
   ^
./Main.c:2:1: warning: data definition has no type or storage class
 p['~~'];a[9];i,j,M;c[]={0,2,5,5,4,5,6,3,7,6};
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:2:9: warning: data definition has no type or storage class
 p['~~'];a[9];i,j,M;c[]={0,2,5,5,4,5,6,3,7,6};
         ^
./Main.c:2:9: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:14: warning: data definition has no type or storage class
 p['~~'];a[9];i,j,M;c[]={0,2,5,5,4,5,6,3,7,6};
              ^
./Main.c:2:14: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:2:16: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 p['~~'];a[9];i,j,M;c[]={0,2,5,5,4,5,6,3,7,6};
                ^
./Main.c...