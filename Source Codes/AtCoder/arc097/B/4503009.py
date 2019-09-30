def f(r, a):
    if r[a] != a:
        r[a] = f(r, r[a])
    return r[a]


def union(r, x, y):
    a = f(r, x)
    b = f(r, y)
    if a != b:
        r[a] = b


n, m = list(map(int, input().split()))
p = list(map(int, input().split()))
r = [i for i in range(n)]

for i in range(m):
    x, y = list(map(int, input().split()))
    x = x - 1
    y = y - 1
    union(r, x, y)


c = 0
for i in range(n):
    if f(r, i) == f(r, p[i] - 1):
        c += 1

print(c)