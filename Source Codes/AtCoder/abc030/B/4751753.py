n,m = map(int,input().split())
n=n%12
s=30*n+0.5*m
l= 6*m
ans=abs(l-s)
if ans>180:
    ans=360-ans
print(ans)