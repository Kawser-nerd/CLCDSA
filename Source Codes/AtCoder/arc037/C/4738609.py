import sys,bisect
input = sys.stdin.readline
n,k = map(int,input().split())
a = sorted(tuple(map(int,input().split())))
b = tuple(map(int,input().split()))

sma = 1
big = 10**18
while big - sma > 1:
    mid = (big+sma)//2
    cnt = 0
    for e in b:
        p = mid//e
        q = bisect.bisect_right(a,p)
        cnt += q
    if cnt >= k:
        big = mid
    else:
        sma = mid
cnt = 0
for e in b:
    p = sma//e
    q = bisect.bisect_right(a,p)
    cnt += q
if cnt >= k:
    print(sma)
else:
    print(big)