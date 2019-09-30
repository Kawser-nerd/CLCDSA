a,b,c,k = map(int,input().split())
s,t = map(int,input().split())
if s+t>k-1:
    print(s*a+t*b-(s+t)*c)
else:
    print(s*a+t*b)