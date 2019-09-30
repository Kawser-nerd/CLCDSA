x1, y1, r = map(int, input().split()) # ?
x2, y2, x3, y3 = map(int, input().split()) # ???

x1_max = x1 + r
x1_min = x1 - r
y1_max = y1 + r
y1_min = y1 - r
# ?
# ?
def circle(x, y):
    global x1, y1
    return (x - x1) ** 2 + (y - y1) ** 2 <= r ** 2

# ?
if circle(x2, y2) and circle(x3, y3) and circle(x2, y3) and circle(x3, y2):
        print('YES')
        print('NO')
# ?
elif x2 <= x1_min and x1_max <= x3 and y2 <= y1_min and y3 >= y1_max:
    print('NO')
    print('YES')
else:
    print('YES')
    print('YES')