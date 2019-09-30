r,c,d = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(r)]

for j in range(r):
    for i in range(c):
        if j > 1:
            a[j][i] = max(a[j][i], a[j-2][i])
        if i > 1:
            a[j][i] = max(a[j][i], a[j][i-2])
        if i > 0 and j > 0:
            a[j][i] = max(a[j][i], a[j-1][i-1])

if d+2 > r+c:
    d = r+c-2 - (r+c+d)%2

ans = 0
for i in range(0, d+1):
    j = d-i
    if j < r and i < c:
        ans = max(ans, a[j][i])
print(ans)