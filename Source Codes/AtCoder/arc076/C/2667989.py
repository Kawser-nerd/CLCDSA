r, c, n = list(map(int, input().split()))

p = []
for i in range(n):
    x1, y1, x2, y2 = list(map(int, input().split()))
    if x1 == 0 or x1 == r or y1 == 0 or y1 == c:
        if x2 == 0 or x2 == r or y2 == 0 or y2 == c:
            if y1 == 0:
                p.append([x1, i])
            elif x1 == r:
                p.append([r + y1, i])
            elif y1 == c:
                p.append([2 * r + c - x1, i])
            else:
                p.append([2 * r + 2 * c - y1, i])

            if y2 == 0:
                p.append([x2, i])
            elif x2 == r:
                p.append([r + y2, i])
            elif y2 == c:
                p.append([2 * r + c - x2, i])
            else:
                p.append([2 * r + 2 * c - y2, i])

p.sort()

t = []

old = -1
for i in range(0, len(p)):
    temp = p[i][1]

    if temp == old:
        t.pop()
        if len(t) == 0:
            old = -1
        else:
            old = t[-1]
    else:
        t.append(temp)
        old = temp
if len(t) > 0:
    print("NO")
else:
    print("YES")