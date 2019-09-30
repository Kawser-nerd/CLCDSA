n, t = map(int, input().split())
inf = 10**9
a = []
for _ in range(n):
    a.append(int(input()))
c = 0
b = a[1:] + [inf]
for i in range(n):
    c += min(b[i]-a[i], t)
print(c)