long r,b,x,y,l,f,m;main(i){for(f=!!scanf("%ld%ld%ld%ld",&r,&b,&x,&y)+fmin(r,b);i++<99;(r-m)/~-x+(b-m)/~-y<m?f=m:(l=m,0))m=l+f>>1;printf("%ld",l);} ./Main.c:1:20: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long r,b,x,y,l,f,m;main(i){for(f=!!scanf("%ld%ld%ld%ld",&r,&b,&x,&y)+fmin(r,b);i++<99;(r-m)/~-x+(b-m)/~-y<m?f=m:(l=m,0))m=l+f>>1;printf("%ld",l);}
                    ^
./Main.c: In function ‘main’:
./Main.c:1:20: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:36: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long r,b,x,y,l,f,m;main(i){for(f=!!scanf("%ld%ld%ld%ld",&r,&b,&x,&y)+fmin(r,b);i++<99;(r-m)/~-x+(b-m)/~-y<m?f=m:(l=m,0))m=l+f>>1;printf("%ld",l);}
                                    ^
./Main.c:1:36: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:36: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:70: warning: implicit declaration of function ‘fmin’ [-Wimplicit-function-declaration]
 long r,b,x,y,l,f,m;main(i){for(f=!!scanf("%ld%ld%ld%ld",&r,&b,&x,&y)+fmin(r,b);i++<99;(r-m)/~-x+(b-m)/~-y<m?f=m:(l=m,0))m=l+f>>1;print...