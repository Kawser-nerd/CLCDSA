from collections import defaultdict
H = defaultdict(lambda: 0)
H[0] = 1
N = int(input())
for _ in range(N):
    i = int(input())
    for ni,nv in H.copy().items():
        H[ni+i] = 1
K = reversed(sorted(list(H.keys())))
ans = 0
for j in K:
    if j%10 != 0:
        ans = j
        break
print(ans)