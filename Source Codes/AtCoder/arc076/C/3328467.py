R, C, N = map(int, input().split())

def makexy(x1, y1):
    if y1 == 0:
        return x1
    elif x1==R:
        return R+y1
    elif y1 == C:
        return R*2 + C - x1
    else:
        return R*2 + C*2 - y1


XY = []
XY2 = []
D = []
for _ in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    if (x1 in [0, R] or y1 in [0, C]) and (x2 in [0, R] or y2 in [0, C]):
        xy1 = makexy(x1, y1)
        xy2 = makexy(x2, y2)
        xy1, xy2 = sorted((xy1, xy2))
        XY.append((xy1, xy2))
        XY2.append((xy1, 0))
        XY2.append((xy2, 1))
        D.append(xy2-xy1)

#print(XY)
XY.sort()
XY2.sort()
D.sort()

D2 = []
Stack = []
for xy in XY2:
    if xy[1] == 0:
        Stack.append(xy)
    else:
        D2.append(xy[0]-Stack[-1][0])
        del Stack[-1]

D2.sort()
#print(D, D2)
if D == D2:
    print("YES")
else:
    print("NO")