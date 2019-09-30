from itertools import groupby as gb
N = int(input())
a,b = gb(input()),gb(input())
res = -1
for (w,x),(y,z) in zip(a,b):
    if res==-1:
        prev = w!=y
        res = 3 * (1+prev)
    elif prev:
        prev = w!=y
        res *= 1 + prev*2
    else:
        prev = w!=y
        res *= 2
print(res % (10**9+7))