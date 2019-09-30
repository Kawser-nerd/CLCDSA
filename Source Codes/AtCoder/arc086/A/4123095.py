from collections import Counter

N, K = map(int, input().split())

A = list(map(int, input().split()))

C = Counter(A)
v = list(C.values())
v = sorted(v)

div = len(v)
ans = 0
if div <= K:
    ans = 0
else:
    ans += sum(v[0:div-K])
print(ans)