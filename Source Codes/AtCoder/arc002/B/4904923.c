y,m,d;main(b){for(scanf("%d/%d/%d",&y,&m,&d);b;++y,m=1)for(;b&m<13;++m,d=1)for(;b&d<31+(m>7?-~m:m)%2-(m-2?0:2-!(y%25?y%4:y%16));++d)b=y%(m*d)?1:!printf("%d/%02d/%02d\n",y,m,d);} ./Main.c:1:1: warning: data definition has no type or storage class
 y,m,d;main(b){for(scanf("%d/%d/%d",&y,&m,&d);b;++y,m=1)for(;b&m<13;++m,d=1)for(;b&d<31+(m>7?-~m:m)%2-(m-2?0:2-!(y%25?y%4:y%16));++d)b=y%(m*d)?1:!printf("%d/%02d/%02d\n",y,m,d);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 y,m,d;main(b){for(scanf("%d/%d/%d",&y,&m,&d);b;++y,m=1)for(;b&m<13;++m,d=1)for(;b&d<31+(m>7?-~m:m)%2-(m-2?0:2-!(y%25?y%4:y%16));++d)b=y%(m*d)?1:!printf("%d/%02d/%02d\n",y,m,d);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 y,m,d;main(b){for(scanf("%d/%d/%d",&y,&m,&d);b;++y,m=1)for(;b&m<13;++m,d=1)for(;b&d<31+(m>7?-~m:m)%2-(m-2?0:2-!(y%25?y%4:y%16));++d)b=y%(m*d)?1:!printf("%d/%02d/%02d\n",y,m,d);}
     ^
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 y,m,d;main(b){for(scanf("%d/%d/%d",&y,&m,&d);b;++y,m=1)for(;b&m<13;++m,d=1)for...