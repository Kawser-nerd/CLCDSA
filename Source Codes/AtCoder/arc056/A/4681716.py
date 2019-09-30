import sys
input = sys.stdin.readline

a,b,k,l = map(int,input().split())

res = a*k
if k%l == 0:
    res = min(res,b*k//l)
else:
    res = min(res,(k//l+1)*b)
res = min(res,b*(k//l)+(k%l)*a)
print(res)