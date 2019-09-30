from collections import Counter
N = int(input())
A = list(map(int,input().split()))
ctr = Counter(A)
sa = sorted(ctr.keys(),reverse=True)

ans = 0
for a in sa:
    p = 2**(len(bin(a))-2)
    rem = p - a
    if a == rem:
        v = ctr[a] // 2
    else:
        v = min(ctr[a], ctr[rem])
    ans += v
    ctr[a] -= v
    ctr[rem] -= v
print(ans)