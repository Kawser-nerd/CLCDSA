s;r;n;main(c){for(gets(&c);c=getchar()-10;s+=r-!!r)r=60-c,n++;printf("%.9f\n",1.*s/n);} ./Main.c:1:1: warning: data definition has no type or storage class
 s;r;n;main(c){for(gets(&c);c=getchar()-10;s+=r-!!r)r=60-c,n++;printf("%.9f\n",1.*s/n);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 s;r;n;main(c){for(gets(&c);c=getchar()-10;s+=r-!!r)r=60-c,n++;printf("%.9f\n",1.*s/n);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 s;r;n;main(c){for(gets(&c);c=getchar()-10;s+=r-!!r)r=60-c,n++;printf("%.9f\n",1.*s/n);}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s;r;n;main(c){for(gets(&c);c=getchar()-10;s+=r-!!r)r=60-c,n++;printf("%.9f\n",1.*s/n);}
       ^
./Main.c: In function ‘main’:
./Main.c:1:7: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: ...