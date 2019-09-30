import math
N = int(input())
xy = []
ans = 0
for i in range(N):
    xy.append(list(map(int, input().split())))
for i in range(N):
    for k in range(N):
        for l in range(N):
            if l != k and i != k and l != i:
                x1 = xy[i][0]
                y1 = xy[i][1]
                x2 = xy[k][0]
                y2 = xy[k][1]
                x3 = xy[l][0]
                y3 = xy[l][1] 
                S = (x1-x3)*(y2-y3)-(x2-x3)*(y1-y3)
            
                if S % 2 == 0 and S != 0:
                    ans += 1
print(ans//6)