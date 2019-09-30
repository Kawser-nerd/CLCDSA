a,b;main(){scanf("%d%d",&a,&b);puts(((long)a*b>0)?((a>0||(b-a)%2)?"Positive":"Negative"):"Zero");} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b;main(){scanf("%d%d",&a,&b);puts(((long)a*b>0)?((a>0||(b-a)%2)?"Positive":"Negative"):"Zero");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b;main(){scanf("%d%d",&a,&b);puts(((long)a*b>0)?((a>0||(b-a)%2)?"Positive":"Negative"):"Zero");}
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a,b;main(){scanf("%d%d",&a,&b);puts(((long)a*b>0)?((a>0||(b-a)%2)?"Positive":"Negative"):"Zero");}
     ^
./Main.c: In function ‘main’:
./Main.c:1:12: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a,b;main(){scanf("%d%d",&a,&b);puts(((long)a*b>0)?((a>0||(b-a)%2)?"Positive":"Negative"):"Zero");}
            ^
./Main.c:1:12: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:12: note: include ‘<stdio.h>’ or provide a declaration of ‘s...