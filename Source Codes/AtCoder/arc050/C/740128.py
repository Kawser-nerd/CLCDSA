def f(x,d,n):z=f((x*d+x)%m,d*d%m,n//2) if n else 0;return[z,z*d+x][n%2]
import fractions as L;a,b,m=map(int,input().split());k=L.gcd(a,b);print(f(1,10,a)*f(1,pow(10,k,m),b//k)%m)