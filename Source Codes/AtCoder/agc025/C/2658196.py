from itertools import accumulate

N = int(input())
L, R = [0], [0]
for i in range(N):
    li, ri = map(int, input().split())
    L.append(li)
    R.append(ri)

L.sort(reverse=True)
R.sort()

L = list(accumulate(L))
R = list(accumulate(R))

ans = 0
for k in range(N+1):
    ans = max(ans, 2*(L[k]-R[k]))

print(ans)