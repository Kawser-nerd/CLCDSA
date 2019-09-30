a,b,k,l = map(int,input().split())
m = k//l
res = b*m
k -= l*m
res += min(a*k,b)
print(res)