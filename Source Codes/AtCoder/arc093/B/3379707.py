def makelist(n, m):
    return [['.' for _ in range(m)] for _ in range(n)]

a, b = map(int, input().split())
N = 100
h = N // 2
d = makelist(N, N)


for y in range(h):
    for x in range(N):
        d[y][x] = "#"

a, b = a-1, b-1

for y in range(h):
    for x in range(N):
        if a == 0:
            break
        if y % 2 == 0 and x % 2 == 0:
            a -= 1
            d[y][x] = "."

for y in reversed(range(h, N)):
    for x in range(N):
        if b == 0:
            break
        if y % 2 == 1 and x % 2 == 1:
            b -= 1
            d[y][x] = "#"

print(N, N)
for y in range(N):
    print("".join(d[y]))