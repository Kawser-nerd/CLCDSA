import itertools
import math
x1,y1,r = map(int,input().split())
x2,y2,x3,y3 = map(int,input().split())
X = [x2,x3]
Y = [y2,y3]
dots = list(itertools.product(X,Y))
k = 0
for i in dots:
    x = i[0]
    y = i[1]
    D = (x1-x)**2 + (y1-y)**2
    dis = math.sqrt(D)
    if dis <= r:
        k += 1
if k == 4:
    print("YES")
    print("NO")
    exit()
if x2 <= x1 - r and x1 + r <= x3 and y2 <= y1 - r and y1 + r <= y3:
    print("NO")
    print("YES")
else:
    print("YES")
    print("YES")