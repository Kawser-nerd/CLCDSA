x1,y1,x2,y2,x3,y3 = map(int, input().split())
a = x2-x1
b = y2-y1
c = x3-x1
d = y3-y1
print(abs(a*d-b*c)/2)