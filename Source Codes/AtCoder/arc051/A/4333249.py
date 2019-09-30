import math
def caldistance(x, y, s, t):
    return math.sqrt((x-s)**2+(y-t)**2)

x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())

if x2 <= x1-r and x3>= x1 + r and y2 <= y1 - r and y3 >= y1 + r:
    print('NO')
else:
    print('YES')

if caldistance(x2, y2, x1, y1) <= r and caldistance(x2, y3, x1, y1) <= r \
    and caldistance(x3, y2, x1, y1) <= r and caldistance(x3, y3, x1, y1) <= r:
    print('NO')
else:
    print('YES')