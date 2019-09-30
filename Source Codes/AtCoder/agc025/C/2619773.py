from itertools import accumulate

N = int(input())
L, R = [0], [0]
for i in range(N):
    li, ri = map(int, input().split())
    L.append(li)
    R.append(ri)

L = list(accumulate(sorted(L, reverse=True)))
R = list(accumulate(sorted(R)))

ans = 0
for k in range(N):
    ans = max(ans, 2*(L[k] - R[k]))

print(ans)