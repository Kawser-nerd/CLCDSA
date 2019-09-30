a[9],b[99],l,d,i,s;f(m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(f(s=a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else for(m=0,i=14;i--;)m+=a[i<6?i:i-5]-a[i<6?i+3:i-6]?0:b[i];s=m;}main(){for(;~scanf("%d",b+i);i+=i>6&i%3>1)l+=b[i++];f();printf("%d\n%d\n",s,l-s);} ./Main.c:1:1: warning: data definition has no type or storage class
 a[9],b[99],l,d,i,s;f(m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(f(s=a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else for(m=0,i=14;i--;)m+=a[i<6?i:i-5]-a[i<6?i+3:i-6]?0:b[i];s=m;}main(){for(;~scanf("%d",b+i);i+=i>6&i%3>1)l+=b[i++];f();printf("%d\n%d\n",s,l-s);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a[9],b[99],l,d,i,s;f(m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(f(s=a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else for(m=0,i=14;i--;)m+=a[i<6?i:i-5]-a[i<6?i+3:i-6]?0:b[i];s=m;}main(){for(;~scanf("%d",b+i);i+=i>6&i%3>1)l+=b[i++];f();printf("%d\n%d\n",s,l-s);}
      ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 a[9],b[99],l,d,i,s;f(m,i){m=d%2?1e9:0;if(d-9)for(i=9;i--;a[i]||(f(s=a[i]=d++%2+1),m=--d%2^m>s?m:s,a[i]=0));else for(m=0,i=14;i--;)m+=a[i<6?i:i-5]-a[i<6?i+3:i-6]?0:b[i];s=m;}m...