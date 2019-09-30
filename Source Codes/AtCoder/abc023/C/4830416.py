r, c, k = map(int, input().split())
n = int(input())
l = [list(map(int, input().split())) for _ in range(n)]

from collections import Counter
rows = [0] * r
cols = [0] * c
for i, j in l:
    rows[i - 1] += 1
    cols[j - 1] += 1
R = Counter(rows)
C = Counter(cols)
res = 0
for i in R.keys():
    res += R[i] * C[k - i]
for i, j in l:
    if rows[i - 1] + cols[j - 1] == k:
        res -= 1
    if rows[i - 1] + cols[j - 1] == k + 1:
        res += 1
print(res)