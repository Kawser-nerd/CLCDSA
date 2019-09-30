n = int(input())
p = [int(input()) for _ in range(n)]

d = {pi: i for i, pi in enumerate(p)}
idx = -1
count = 0
ma = 0

for i in range(1, n+1):
    if d[i] > idx:
        count += 1
        idx = d[i]
    else:
        ma = max(ma, count)
        idx = d[i]
        count = 1

ma = max(ma, count)
print(n - ma)