#define f(a,b) for(a=-1;a++<b;)
w,s[101][101],m,i,j,k,l,a;main(h){scanf("%d%d",&h,&w);f(i,h-1)f(j,w-1)scanf("%d",&a),s[i+1][j+1]=((i+j)%2?-a:a)+s[i+1][j]+s[i][j+1]-s[i][j];f(k,h)f(l,w)f(i,h-k)f(j,w-l)m=s[i+k][j+l]-s[i+k][j]-s[i][j+l]+s[i][j]||m>k*l?m:k*l;printf("%d\n",m);} ./Main.c:2:1: warning: data definition has no type or storage class
 w,s[101][101],m,i,j,k,l,a;main(h){scanf("%d%d",&h,&w);f(i,h-1)f(j,w-1)scanf("%d",&a),s[i+1][j+1]=((i+j)%2?-a:a)+s[i+1][j]+s[i][j+1]-s[i][j];f(k,h)f(l,w)f(i,h-k)f(j,w-l)m=s[i+k][j+l]-s[i+k][j]-s[i][j+l]+s[i][j]||m>k*l?m:k*l;printf("%d\n",m);}
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 w,s[101][101],m,i,j,k,l,a;main(h){scanf("%d%d",&h,&w);f(i,h-1)f(j,w-1)scanf("%d",&a),s[i+1][j+1]=((i+j)%2?-a:a)+s[i+1][j]+s[i][j+1]-s[i][j];f(k,h)f(l,w)f(i,h-k)f(j,w-l)m=s[i+k][j+l]-s[i+k][j]-s[i][j+l]+s[i][j]||m>k*l?m:k*l;printf("%d\n",m);}
   ^
./Main.c:2:15: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
 w,s[101][101],m,i,j,k,l,a;main(h){scanf("%d%d",&h,&w);f(i,h-1)f(j,w-1)scanf("%d",&a),s[i+1][j+1]=((i+j)%2?-a:a)+s[i+1][j]+s[i][j+1]-s[i][j];f(k,h)f(l,w)f(i,h-k)f(j,w-l)m=s[i+k][j+l]-s[i+k][j]-s[i][j+l]+s[i...