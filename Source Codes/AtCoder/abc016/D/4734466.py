def ok(x1, y1, x2, y2, x3, y3, x4, y4):
    a = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)
    b = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)
    c = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)
    d = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2)
    return a * b <= 0 and c * d <= 0


ax, ay, bx, by = map(int, input().split())
n = int(input())
z = [list(map(int, input().split())) for i in range(n)]
p = 0
for i in range(n + 1):
    if (ok(ax, ay, bx, by, z[i - 1][0], z[i - 1][1], z[i % n][0], z[i % n][1])):
        p += 1
print(p//2+1)