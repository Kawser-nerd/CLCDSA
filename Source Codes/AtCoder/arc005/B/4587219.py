from sys import stdin
input = stdin.readline

x, y, w = input().split()
x = int(x) - 1
y = int(y) - 1
L = []
for _ in range(9):
    L_ = input()
    L.append(L_)

R = [[y, x]]
for i in range(3):
    if "R" in w:
        x += 1
    if "L" in w:
        x -= 1
    if "U" in w:
        y -= 1
    if "D" in w:
        y += 1
    R.append([y, x])

ans = ""
for y, x in R:
    if x > 8:
        x = 16 - x
    if x < 0:
        x = -x
    if y > 8:
        y = 16 - y
    if y < 0:
        y = -y
    ans += L[y][x]

print(ans)