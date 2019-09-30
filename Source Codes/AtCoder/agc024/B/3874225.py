n = int(input())
p = [int(input()) for _ in range(n)]
q = [-1] * n
for i, j in enumerate(p):
    q[j - 1] = i
res = n
tmp = 1
for i, j in zip(q, q[1:]):
    if i < j:
        tmp += 1
    else:
        res = min(res, n - tmp)
        tmp = 1
else:
    res = min(res, n - tmp)
print(res)