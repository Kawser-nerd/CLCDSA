from itertools import accumulate
from operator import add

def getAccAss(Ass):
    accAss = [[0]*(len(Ass[0])+1)] + [[0] + As for As in Ass]
    accAss = [accumulate(accAs) for accAs in accAss]
    accAss[0] = list(accAss[0])
    for x in range(1, len(accAss)):
        accAss[x] = list(map(add, accAss[x], accAss[x-1]))
    return accAss

def getRangeSum2D(accAss, xFr, xTo, yFr, yTo):
    return accAss[xTo+1][yTo+1] - accAss[xTo+1][yFr] - accAss[xFr][yTo+1] + accAss[xFr][yFr]

N = int(input())
Dss = [list(map(int, input().split())) for _ in range(N)]
Q = int(input())
Ps = [int(input()) for _ in range(Q)]

accDss = getAccAss(Dss)

sumDs = [0] * (N*N+1)
for xFr in range(N):
    for xTo in range(xFr, N):
        for yFr in range(N):
            for yTo in range(yFr, N):
                area = (xTo-xFr+1) * (yTo-yFr+1)
                sumD = getRangeSum2D(accDss, xFr, xTo, yFr, yTo)
                if sumD > sumDs[area]:
                    sumDs[area] = sumD

sumDs = list(accumulate(sumDs, lambda x, y: x if x >= y else y))

for P in Ps:
    print(sumDs[P])