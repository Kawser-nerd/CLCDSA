b;i;main(C,a,c){for(;a=getchar()-10;c=a)b|=i++?i<3|!C|a-57?a<87:(C=0,b):a-55;puts(b||C||c<87?"WA":"AC");} ./Main.c:1:1: warning: data definition has no type or storage class
 b;i;main(C,a,c){for(;a=getchar()-10;c=a)b|=i++?i<3|!C|a-57?a<87:(C=0,b):a-55;puts(b||C||c<87?"WA":"AC");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 b;i;main(C,a,c){for(;a=getchar()-10;c=a)b|=i++?i<3|!C|a-57?a<87:(C=0,b):a-55;puts(b||C||c<87?"WA":"AC");}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 b;i;main(C,a,c){for(;a=getchar()-10;c=a)b|=i++?i<3|!C|a-57?a<87:(C=0,b):a-55;puts(b||C||c<87?"WA":"AC");}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘C’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:24: warning: implicit declaration of function ‘getchar’ [-Wim...