from operator import itemgetter
x1,y1,x2,y2,x3,y3 = map(int, input().split())
xy = [(x1, y1), (x2, y2), (x3, y3)]

# ????????????????
xy.sort(key=itemgetter(1))
xy.sort(key=itemgetter(0))
x1,y1 = xy[0]
xy = [(x-x1, y-y1) for x,y in xy]
x2,y2 = xy[1]
x3,y3 = xy[2]
print(1/2 * abs(x2*y3 - x3*y2))