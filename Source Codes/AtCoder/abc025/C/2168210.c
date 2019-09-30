a[9],b[99],l,d,i,j;f(s,m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(s=f(a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else{m=0;for(i=6;i--;)m+=a[i]-a[i+3]?0:b[i];for(i=9;--i;)m+=a[i]-a[i-1]?0:b[i+5];}return m;}main(){for(;~scanf("%d",b+i);i+=i>6&i%3>1)l+=b[i++];printf("%d\n%d\n",f(),l-f());} ./Main.c:1:1: warning: data definition has no type or storage class
 a[9],b[99],l,d,i,j;f(s,m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(s=f(a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else{m=0;for(i=6;i--;)m+=a[i]-a[i+3]?0:b[i];for(i=9;--i;)m+=a[i]-a[i-1]?0:b[i+5];}return m;}main(){for(;~scanf("%d",b+i);i+=i>6&i%3>1)l+=b[i++];printf("%d\n%d\n",f(),l-f());}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a[9],b[99],l,d,i,j;f(s,m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(s=f(a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else{m=0;for(i=6;i--;)m+=a[i]-a[i+3]?0:b[i];for(i=9;--i;)m+=a[i]-a[i-1]?0:b[i+5];}return m;}main(){for(;~scanf("%d",b+i);i+=i>6&i%3>1)l+=b[i++];printf("%d\n%d\n",f(),l-f());}
      ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 a[9],b[99],l,d,i,j;f(s,m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(s=f(a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else{m=0;...