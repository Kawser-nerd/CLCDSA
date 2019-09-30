import sys

def ta(x, y, p):
    xc = 0
    yc = 0

    for i in p[x]:
        bc = x
        c = i
        while True:
            if c == x:
                xc += 1
                break
            elif c == y:
                yc += 1
                break
            cs = p[c]
            for j in cs:
                if j != bc:
                    bc = c
                    c = j
                    break
    if xc == yc:
        return True
    else:
        return False


d = {}
p = {}
n, m = input().strip().split(" ")
for i in range(int(n)):
    i += 1
    d[i] = 0
    p[i] = list()

for line in sys.stdin:
    x, y = line.strip().split(" ")
    x, y = int(x), int(y)
    d[x] += 1
    d[y] += 1
    p[x].append(y)
    p[y].append(x)

r = None
fc = 0
fcs = []
for x in d:
    y = d[x]
    if y % 2 != 0:
        r = False
        break
    if y >= 6:
        r = True
    if y >= 4:
        fc += 1
        fcs.append(x)

if r == None:
    if fc >= 3:
        r = True
    elif fc == 2:
        x, y = fcs
        r = ta(x, y, p)
    else:
        r = False
if r:
    print("Yes")
else:
    print("No")