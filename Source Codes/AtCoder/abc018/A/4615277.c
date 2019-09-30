e,f;main(d,a,b,c){scanf("%d%d%d",&a,&b,&c);a<b?(++d,a<c?(++d,b<c?++e:++f):(f=2)):(++e,b<c?(++e,a<c?++d:++f):(f=2));printf("%d\n%d\n%d\n",d,++e,++f);} ./Main.c:1:1: warning: data definition has no type or storage class
 e,f;main(d,a,b,c){scanf("%d%d%d",&a,&b,&c);a<b?(++d,a<c?(++d,b<c?++e:++f):(f=2)):(++e,b<c?(++e,a<c?++d:++f):(f=2));printf("%d\n%d\n%d\n",d,++e,++f);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘e’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 e,f;main(d,a,b,c){scanf("%d%d%d",&a,&b,&c);a<b?(++d,a<c?(++d,b<c?++e:++f):(f=2)):(++e,b<c?(++e,a<c?++d:++f):(f=2));printf("%d\n%d\n%d\n",d,++e,++f);}
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 e,f;main(d,a,b,c){scanf("%d%d%d",&a,&b,&c);a<b?(++d,a<c?(++d,b<c?++e:++f):(f=2)):(++e,b<c?(++e,a<c?++d:++f):(f=2));printf("%d\n%d\n%d\n",d,++e,++f);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c...