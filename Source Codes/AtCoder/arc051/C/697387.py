f=lambda:map(int,input().split());n,a,b=f();s=list(f());c=s.sort;c();d,m=max(s),10**9+7
if~-a:
	while(s[0]<d)*b:s[0]*=a;b-=1;c()
for i in range(b%n):s[i]*=a
c()
for x in s:print(x*pow(a,b//n,m)%m)