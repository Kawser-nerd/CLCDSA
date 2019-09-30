X, Y, W = [_ for _ in input().split()]
c = [input() for i in range(9)]

x, y = int(X) - 1, int(Y) - 1

dx, dy = {
    "U":  ( 0, -1),
    "D":  ( 0, +1),
    "R":  (+1,  0),
    "L":  (-1,  0),
    "RU": (+1, -1),
    "RD": (+1, +1),
    "LU": (-1, -1),
    "LD": (-1, +1),
}[W]

result = ""

for i in range(4):
    result += c[y][x]
    if x == 0: dx = +abs(dx)
    if x == 8: dx = -abs(dx)
    if y == 0: dy = +abs(dy)
    if y == 8: dy = -abs(dy)
    x += dx
    y += dy

print(result)