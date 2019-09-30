N = int(input())

list = []
list.append((0, 0, 0))
for i in range(N):
    t, x, y = [int(x) for x in input().split()]
    list.append((t, x, y))


def isReachable(t1, x1, y1, t2, x2, y2):
    if (t2 - t1) < abs(x1 - x2) + abs(y1 - y2):
        return False
    if ((t2 - t1) - (abs(x1 - x2) + abs(y1 - y2))) % 2 == 0:
        return True
    else:
        return False


ret = True
for i in range(0, N):
    t1, x1, y1 = list[i]
    t2, x2, y2 = list[i + 1]
    b = isReachable(t1, x1, y1, t2, x2, y2)
    if b == False:
        ret = False
        break

if ret == True:
    print("Yes")
else:
    print("No")