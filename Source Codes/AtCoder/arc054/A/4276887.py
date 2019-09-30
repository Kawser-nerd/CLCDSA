l,x,y,s,d = map(int,input().split())
clockwise = d - s
if clockwise < 0:
    clockwise += l
anticlockwise = l - clockwise
res = clockwise / (x + y)
if y - x > 0:
    res = min(res, anticlockwise / (y - x))
# print(clockwise, anticlockwise)
print(res)