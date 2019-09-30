c,j,k,m;main(w,d){for(scanf("%*d%d%d",&w,&d);~scanf("%d",&c);j++)m=m<(c*=!((k=j/w+j%w)>d||k+d&1))?c:m;printf("%d\n",m);} ./Main.c:1:1: warning: data definition has no type or storage class
 c,j,k,m;main(w,d){for(scanf("%*d%d%d",&w,&d);~scanf("%d",&c);j++)m=m<(c*=!((k=j/w+j%w)>d||k+d&1))?c:m;printf("%d\n",m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 c,j,k,m;main(w,d){for(scanf("%*d%d%d",&w,&d);~scanf("%d",&c);j++)m=m<(c*=!((k=j/w+j%w)>d||k+d&1))?c:m;printf("%d\n",m);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 c,j,k,m;main(w,d){for(scanf("%*d%d%d",&w,&d);~scanf("%d",&c);j++)m=m<(c*=!((k=j/w+j%w)>d||k+d&1))?c:m;printf("%d\n",m);}
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 c,j,k,m;main(w,d){for(scanf("%*d%d%d",&w,&d);~scanf("%d",&c);j++)m=m<(c*=!((k=j/w+j%w)>d||k+d&1))?c:m;printf("%d\n",m);}
       ^
./Main.c:1:9: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c,j,k,m;main(w,d){for(scanf("%*d%...