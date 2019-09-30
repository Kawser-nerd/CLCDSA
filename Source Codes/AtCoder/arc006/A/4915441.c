b;c;i;j;E[9];main(l){for(;i<7;)scanf("%d",E+i++);for(;~scanf("%d",&l);l-E[j]?l-E[6]?:b++:c++)for(;j<5&&E[j]<l;)j++;c+b<6?c=c<3?8:c:c++;printf("%d\n",8-c);} ./Main.c:1:1: warning: data definition has no type or storage class
 b;c;i;j;E[9];main(l){for(;i<7;)scanf("%d",E+i++);for(;~scanf("%d",&l);l-E[j]?l-E[6]?:b++:c++)for(;j<5&&E[j]<l;)j++;c+b<6?c=c<3?8:c:c++;printf("%d\n",8-c);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 b;c;i;j;E[9];main(l){for(;i<7;)scanf("%d",E+i++);for(;~scanf("%d",&l);l-E[j]?l-E[6]?:b++:c++)for(;j<5&&E[j]<l;)j++;c+b<6?c=c<3?8:c:c++;printf("%d\n",8-c);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 b;c;i;j;E[9];main(l){for(;i<7;)scanf("%d",E+i++);for(;~scanf("%d",&l);l-E[j]?l-E[6]?:b++:c++)for(;j<5&&E[j]<l;)j++;c+b<6?c=c<3?8:c:c++;printf("%d\n",8-c);}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:7: warning: data definition has no type or storage class
 b;c;i;j;E[...