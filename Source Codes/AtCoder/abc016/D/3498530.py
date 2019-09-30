Ax,Ay,Bx,By=map(int,input().split())

N=int(input())
XY=[list(map(int,input().split())) for i in range(N)]

XY.append(XY[0])

#????????
#http://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm
#????.

def cross(x1,y1,x2,y2,x3,y3,x4,y4):
    tc=(x1-x2)*(y3-y1)+(y1-y2)*(x1-x3)
    td=(x1-x2)*(y4-y1)+(y1-y2)*(x1-x4)

    ta=(x3-x4)*(y1-y3)+(y3-y4)*(x3-x1)
    tb=(x3-x4)*(y2-y3)+(y3-y4)*(x3-x2)

    if ta*tb<0 and tc*td<0:
        return 1
    else:
        return 0

ANS=0
for i in range(N):
    if cross(Ax,Ay,Bx,By,XY[i][0],XY[i][1],XY[i+1][0],XY[i+1][1])==1:
        ANS+=1

print(ANS//2+1)