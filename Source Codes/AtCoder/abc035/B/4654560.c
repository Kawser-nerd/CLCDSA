q;x;y;main(a){for(;a=getchar()-10;)a-53?*(a%6?&x:&y)+=a>66?:-1:q++;x=abs(x)+abs(y);gets(&a);printf("%d\n",a%2?x+q:q>x?q-x&1:x-q);} ./Main.c:1:1: warning: data definition has no type or storage class
 q;x;y;main(a){for(;a=getchar()-10;)a-53?*(a%6?&x:&y)+=a>66?:-1:q++;x=abs(x)+abs(y);gets(&a);printf("%d\n",a%2?x+q:q>x?q-x&1:x-q);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘q’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 q;x;y;main(a){for(;a=getchar()-10;)a-53?*(a%6?&x:&y)+=a>66?:-1:q++;x=abs(x)+abs(y);gets(&a);printf("%d\n",a%2?x+q:q>x?q-x&1:x-q);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 q;x;y;main(a){for(;a=getchar()-10;)a-53?*(a%6?&x:&y)+=a>66?:-1:q++;x=abs(x)+abs(y);gets(&a);printf("%d\n",a%2?x+q:q>x?q-x&1:x-q);}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 q;x;y;main(a){for(;a=getchar()-10;)a-53?*(a%6?&x:&y)+=a>66?:-1:q++;x=abs(x)+abs(y);...