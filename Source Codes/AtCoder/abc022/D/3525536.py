N=int(input())
AXY=[tuple(map(int,input().split())) for i in range(N)]
BXY=[tuple(map(int,input().split())) for i in range(N)]

AX=[AXY[i][0] for i in range(N)]
AY=[AXY[i][1] for i in range(N)]
BX=[BXY[i][0] for i in range(N)]
BY=[BXY[i][1] for i in range(N)]
AVEAX,AVEAY=sum(AX)/N,sum(AY)/N
AVEBX,AVEBY=sum(BX)/N,sum(BY)/N

import math

A_sumdis=0
B_sumdis=0
for x,y in AXY:
    A_sumdis+=math.sqrt((x-AVEAX)**2+(y-AVEAY)**2)

for x,y in BXY:
    B_sumdis+=math.sqrt((x-AVEBX)**2+(y-AVEBY)**2)

print(B_sumdis/A_sumdis)