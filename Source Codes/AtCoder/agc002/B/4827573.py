n, m = map(int, input().split())
a = [[1, 0] for _ in range(n)]
a[0][1] = 1
for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    a[x][0] -= 1
    a[y][0] += 1
    a[y][1] += a[x][1]
    if a[x][0] == 0:
        a[x][1] = 0
cnt = 0
for i in range(n):
    if a[i][1] > 0:
        cnt += 1
print(cnt)