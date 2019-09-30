def crosscheck(p1, p2, p3, p4):
    tc1 = (p1[0] - p2[0]) * (p3[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p3[0])
    tc2 = (p1[0] - p2[0]) * (p4[1] - p1[1]) + (p1[1] - p2[1]) * (p1[0] - p4[0])
    td1 = (p3[0] - p4[0]) * (p1[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p1[0])
    td2 = (p3[0] - p4[0]) * (p2[1] - p3[1]) + (p3[1] - p4[1]) * (p3[0] - p2[0])

    if tc1*tc2 < 0 and td1*td2 < 0:
        return True
    else:
        return False


ax, ay, bx, by = map(int, input().split())
n = int(input())

xlist = []
ylist = []
for _ in range(n):
    x, y = map(int, input().split())
    xlist.append(x)
    ylist.append(y)

x1 = xlist.pop(0)
y1 = ylist.pop(0)
xlist.append(x1)
ylist.append(y1)

p1 = [ax, ay]
p2 = [bx, by]
p3 = [x1, y1]
cnt = 0

for x2, y2 in zip(xlist, ylist):
    p4 = [x2, y2]
    if crosscheck(p1, p2, p3, p4):
        cnt += 1
    p3 = p4

print(cnt // 2 + 1)