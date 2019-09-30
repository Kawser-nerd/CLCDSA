n, m = map(int, input().split())
if n > 11:
    n -= 12

x = 30 * n + 0.5 * m
y = 6 * m
x, y = sorted((x, y))
z = y - x

if z > 180:
    z = 360 - z

print(z)