x1, y1, r = map(int, input().split())
x2, y2, x3, y3 = map(int, input().split())
a = x1 - r
b = y1 - r
c = x1 + r
d = y1 + r

#??????????
if x2 <= a and y2 <= b and x3 >= c and y3 >= d:
    print('NO')
else:
    print('YES')
    
#??????????
d1 = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
d2 = ((x1 - x3) ** 2 + (y1 - y3) ** 2) ** 0.5
d3 = ((x1 - x2) ** 2 + (y1 - y3) ** 2) ** 0.5
d4 = ((x1 - x3) ** 2 + (y1 - y2) ** 2) ** 0.5

if d1 <= r and d2 <= r and d3 <= r and d4 <= r:
    print('NO')
else:
    print('YES')