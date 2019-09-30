A,B,C;a,b,c;p;main(X){scanf("%d%d%d%d",&A,&B,&C,&X);for(;a<=A;a++)for(b=0;b<=B;b++)for(c=0;c<=C;c++)p+=!((10*a+2*b+c)*50-X);printf("%d",p);} ./Main.c:1:1: warning: data definition has no type or storage class
 A,B,C;a,b,c;p;main(X){scanf("%d%d%d%d",&A,&B,&C,&X);for(;a<=A;a++)for(b=0;b<=B;b++)for(c=0;c<=C;c++)p+=!((10*a+2*b+c)*50-X);printf("%d",p);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘B’ [-Wimplicit-int]
 A,B,C;a,b,c;p;main(X){scanf("%d%d%d%d",&A,&B,&C,&X);for(;a<=A;a++)for(b=0;b<=B;b++)for(c=0;c<=C;c++)p+=!((10*a+2*b+c)*50-X);printf("%d",p);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘C’ [-Wimplicit-int]
 A,B,C;a,b,c;p;main(X){scanf("%d%d%d%d",&A,&B,&C,&X);for(;a<=A;a++)for(b=0;b<=B;b++)for(c=0;c<=C;c++)p+=!((10*a+2*b+c)*50-X);printf("%d",p);}
     ^
./Main.c:1:7: warning: data definition has no type or storage class
 A,B,C;a,b,c;p;main(X){scanf("%d%d%d%d",&A,&B,&C,&X);for(;a<=A;a++)for(b=0;b<=B;b++)for(c=0;c<=C;c++)p+=!((10*a+2*b+c)*50-X);printf("%d",p);}
       ^
./Main.c:1:7: warning: type defaults to ‘...