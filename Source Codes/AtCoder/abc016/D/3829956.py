import sys
input = sys.stdin.readline
Ax,Ay,Bx,By=[int(_) for _ in  input().split()]
N = int(input())
aXY = [[int(_) for _ in sLine.split()] for sLine in sys.stdin.readlines()]
def ????(x1,y1,x2,y2,x3,y3,x4,y4):
    tc = (x1-x2)*(y3-y1)+(y1-y2)*(x1-x3)
    td = (x1-x2)*(y4-y1)+(y1-y2)*(x1-x4)
    ta = (x3-x4)*(y1-y3)+(y3-y4)*(x3-x1)
    tb = (x3-x4)*(y2-y3)+(y3-y4)*(x3-x2)
    if 0 > tc*td and 0 > ta*tb:
        return True
    else:
        return False

iC = 0
for i in range(N):
    x0,y0 = aXY[i-1]
    x1,y1 = aXY[i]
    if ????(Ax,Ay,Bx,By,x0,y0,x1,y1):
        iC += 1
print(iC//2 + 1)