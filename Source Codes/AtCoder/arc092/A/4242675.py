from operator import itemgetter

n = int(input())
red = []
blue = []
for i in range(n):
    a, b = map(int, input().split())
    red.append([a, b, min(a, b)])
for i in range(n):
    c, d = map(int, input().split())
    blue.append([c, d, min(c, d)])
red = sorted(red, key=itemgetter(2))
blue = sorted(blue, key=itemgetter(2))
red_x = set()
red_y = set()
blue_x = set()
blue_y = set()
for i in red:
    red_x.add(i[0])
    red_y.add(i[1])
for i in blue:
    blue_x.add(i[0])
    blue_y.add(i[1])
red_kouho = []
blue_kouho = []
for i in red:
    rx = i[0]
    ry = i[1]
    kouho = []
    for j in blue:
        bx = j[0]
        by = j[1]
        if rx < bx and ry < by:
            kouho.append((bx, by))
    red_kouho.append([kouho, len(kouho)])
red_kouho = sorted(red_kouho, key=itemgetter(1))
count = 0
for i in red_kouho:
    for j in i[0]:
        if j[0] in blue_x and j[1] in blue_y:
            blue_x.discard(j[0])
            blue_y.discard(j[1])
            count += 1
            break
print(count)