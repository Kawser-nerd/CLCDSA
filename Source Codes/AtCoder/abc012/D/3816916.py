import sys
def ?():
    input = sys.stdin.readline
    N,M = [int(_) for _ in input().split()]
    aB = [list(map(int,input().split())) for i in range(M)]
    dT ={}
    def addData(dT:dict,a:int,b:int,t:int):
        if a in dT:
            dT[a][b]=t
        else:
            dT[a] = {b:t}
    #for _ in range(M):
    for a,b,t in aB:
        addData(dT,a,b,t)
        addData(dT,b,a,t)
#   for i in range(1,N+1):
#       addData(dT,i,i,0)
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
    iAns =float("inf")
    for i,dD in dT.items():
        iD = 0
        for j,v in dD.items():
            if i==j:
                continue
            if v > iD:
                iD = v
        if iAns > iD:
            iAns = iD
    print(iAns)

    #print(min(max(dD.values())for dD in dT.values()))
?()