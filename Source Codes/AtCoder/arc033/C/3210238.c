b=1<<18;s[1<<19];x,y,z;main(q){for(scanf("%d",&q);q--;){scanf("%d%d",&x,&y);if(x-1)for(z=1;z<b||!printf("%d\n",y=z-b);x=-1)if(s[z*=2]<y)y-=s[z++];for(y+=b;y;y/=2)s[y]+=x;}} ./Main.c:1:1: warning: data definition has no type or storage class
 b=1<<18;s[1<<19];x,y,z;main(q){for(scanf("%d",&q);q--;){scanf("%d%d",&x,&y);if(x-1)for(z=1;z<b||!printf("%d\n",y=z-b);x=-1)if(s[z*=2]<y)y-=s[z++];for(y+=b;y;y/=2)s[y]+=x;}}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:9: warning: data definition has no type or storage class
 b=1<<18;s[1<<19];x,y,z;main(q){for(scanf("%d",&q);q--;){scanf("%d%d",&x,&y);if(x-1)for(z=1;z<b||!printf("%d\n",y=z-b);x=-1)if(s[z*=2]<y)y-=s[z++];for(y+=b;y;y/=2)s[y]+=x;}}
         ^
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:18: warning: data definition has no type or storage class
 b=1<<18;s[1<<19];x,y,z;main(q){for(scanf("%d",&q);q--;){scanf("%d%d",&x,&y);if(x-1)for(z=1;z<b||!printf("%d\n",y=z-b);x=-1)if(s[z*=2]<y)y-=s[z++];for(y+=b;y;y/=2)s[y]+=x;}}
                  ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main....