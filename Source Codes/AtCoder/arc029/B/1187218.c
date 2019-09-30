float a,b,c,d,e,f,g;h,i;
s(a,b,c,d)float a,b,c,d;{for(h|=a<c&b<d,f=1.57,i=e=0;i++<99;a*sin(g)+b*cos(g)>c?f=g:(e=g,0))h|=a*sin(g=(e+f)/2)+b*cos(g)<c&a*cos(g)+b*sin(g)<d;}
main(){for(scanf("%f%f%*d",&a,&b);~scanf("%f%f",&c,&d);h=!puts(h?"YES":"NO"))s(a,b,c,d),s(a,b,d,c),s(b,a,c,d),s(b,a,d,c);} ./Main.c:1:21: warning: data definition has no type or storage class
 float a,b,c,d,e,f,g;h,i;
                     ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
./Main.c:1:23: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 float a,b,c,d,e,f,g;h,i;
                       ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s(a,b,c,d)float a,b,c,d;{for(h|=a<c&b<d,f=1.57,i=e=0;i++<99;a*sin(g)+b*cos(g)>c?f=g:(e=g,0))h|=a*sin(g=(e+f)/2)+b*cos(g)<c&a*cos(g)+b*sin(g)<d;}
 ^
./Main.c: In function ‘s’:
./Main.c:2:63: warning: implicit declaration of function ‘sin’ [-Wimplicit-function-declaration]
 s(a,b,c,d)float a,b,c,d;{for(h|=a<c&b<d,f=1.57,i=e=0;i++<99;a*sin(g)+b*cos(g)>c?f=g:(e=g,0))h|=a*sin(g=(e+f)/2)+b*cos(g)<c&a*cos(g)+b*sin(g)<d;}
                                                               ^
./Main.c:2:63: warning: incompatible implicit declaration of built-in function ‘sin’
./Main.c:2:63: note: include ‘<math.h>’ ...