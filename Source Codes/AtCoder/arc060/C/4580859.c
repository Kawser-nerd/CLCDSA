L,x[1<<17];d[20][1<<17];i,k,l,r,m;
main(n){
	for(scanf("%d",&n);i<n;)scanf("%d",++i+x);
	for(scanf("%d\n",&L);k<20;k++)for(i=0;i++<n;)
		if(k)d[k][i]=d[k-1][d[k-1][i]];
		else for(l=0,r=n+1;r-l>1;d[k][i]=l)x[m=l+r>>1]>x[i]+L?r=m:(l=m);
	for(gets(x);~scanf("%d%d",&l,&r);printf("%d\n",m+1))
		for(l>r&&(l^=r^=l^=r),m=0,k=20;k--;)d[k][l]<r?m+=1<<k,l=d[k][l]:0;
} ./Main.c:1:1: warning: data definition has no type or storage class
 L,x[1<<17];d[20][1<<17];i,k,l,r,m;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘L’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 L,x[1<<17];d[20][1<<17];i,k,l,r,m;
   ^
./Main.c:1:12: warning: data definition has no type or storage class
 L,x[1<<17];d[20][1<<17];i,k,l,r,m;
            ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:25: warning: data definition has no type or storage class
 L,x[1<<17];d[20][1<<17];i,k,l,r,m;
                         ^
./Main.c:1:25: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:27: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 L,x[1<<17];d[20][1<<17];i,k,l,r,m;
                           ^
./Main.c:1:29: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 L,x[1<<17];d[20][1<<17];i,k,l,r,m;
          ...