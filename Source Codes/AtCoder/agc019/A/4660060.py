q,h,s,d,n=map(int,open(0).read().split())
q*=4
h*=2
m=min(q,h,s)
if m<d/2:
    print(n*m)
else:
    print(n//2*d+m*(n%2==1))