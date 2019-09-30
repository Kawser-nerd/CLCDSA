# coding: utf-8
sx, sy, ex, ey, T, V = map(int, input().split())
n = int(input())
girls = [list(map(int, input().split())) for _ in range(n)]
ans = 'NO'
for girl in girls:
    x, y = girl
    d = ((sx - x) ** 2 + (sy - y) ** 2) ** 0.5
    d += ((ex - x) ** 2 + (ey - y) ** 2) ** 0.5
    if d <= V * T:
        ans = 'YES'
print(ans)