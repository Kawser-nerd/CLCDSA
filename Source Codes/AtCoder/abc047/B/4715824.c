i;X,Y,Z,W;main(x,y,a){for(;~scanf("%d%d%d",&x,&y,&a);)!i++?Z=x,W=y:a>2?a%2?Y=y<Y?Y:y:(W=y>W?W:y):a%2?X=x<X?X:x:(Z=x>Z?Z:x);printf("%d",X<Z&Y<W?(Z-X)*(W-Y):0);} ./Main.c:1:1: warning: data definition has no type or storage class
 i;X,Y,Z,W;main(x,y,a){for(;~scanf("%d%d%d",&x,&y,&a);)!i++?Z=x,W=y:a>2?a%2?Y=y<Y?Y:y:(W=y>W?W:y):a%2?X=x<X?X:x:(Z=x>Z?Z:x);printf("%d",X<Z&Y<W?(Z-X)*(W-Y):0);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 i;X,Y,Z,W;main(x,y,a){for(;~scanf("%d%d%d",&x,&y,&a);)!i++?Z=x,W=y:a>2?a%2?Y=y<Y?Y:y:(W=y>W?W:y):a%2?X=x<X?X:x:(Z=x>Z?Z:x);printf("%d",X<Z&Y<W?(Z-X)*(W-Y):0);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘X’ [-Wimplicit-int]
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘Y’ [-Wimplicit-int]
 i;X,Y,Z,W;main(x,y,a){for(;~scanf("%d%d%d",&x,&y,&a);)!i++?Z=x,W=y:a>2?a%2?Y=y<Y?Y:y:(W=y>W?W:y):a%2?X=x<X?X:x:(Z=x>Z?Z:x);printf("%d",X<Z&Y<W?(Z-X)*(W-Y):0);}
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘Z’ [-Wimplicit-int]
 i;X,Y,Z,W;main(x,y,a){for(;~scanf("%d%d%d",&x,&y,...