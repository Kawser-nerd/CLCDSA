x, y, W = map(str, input().split())
x = int(x)
y = int(y)
c = []
yoko = []
sita = []
yokosita = []
for i in range(9):
    ci = list(input())
    yoko = ci[::-1]
    yoko = yoko[1:-1]
    if i != 8 and i != 0:
        sita.insert(0,ci)
        yokosita.insert(0,yoko)
    c.append(ci + yoko)
for i in range(7):
    bf = sita[i] + yokosita[i]
    c.append(bf)

sousax = {"R": 1, "L": -1, "U": 0, "D": 0, "RU": 1, "RD": 1, "LU": -1, "LD": -1}
sousay = {"R": 0, "L": 0, "U": -1, "D": 1, "RU": -1, "RD": 1, "LU": -1, "LD": 1}

ans = ""
x -= 1
y -= 1
for i in range(4):
    ans += c[y][x]
    x += sousax[W]
    y += sousay[W]
print(ans)