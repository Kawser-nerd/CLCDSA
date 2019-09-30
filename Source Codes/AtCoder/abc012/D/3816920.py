import sys
def ?():
    input = sys.stdin.readline
    N,M = [int(_) for _ in input().split()]
    dT ={}
    def addData(dT:dict,a:int,b:int,t:int):
        if a in dT:
            dT[a][b]=t
        else:
            dT[a] = {b:t}
    for _ in range(M):
        a,b,t = [int(_) for _ in input().split()]
        addData(dT,a,b,t)
        addData(dT,b,a,t)
    for i in range(1,N+1):
        addData(dT,i,i,0)
    for k in range(1,N+1):
        aK = dT[k].keys()
        for i in aK:
            dI = dT[i]
            dK = dT[k]
            iRK = dI[k]
            for j in aK:
                iR = iRK + dK[j]
                if j in dI:
                    if dI[j] > iR:
                        dI[j] = iR
                else:
                    dI[j] = iR
    print(min(max(dD.values())for dD in dT.values()))
?()