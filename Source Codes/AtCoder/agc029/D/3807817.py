import sys
def ?():
    input = sys.stdin.readline
    H,W,N = [int(_) for _ in input().split()]
    dT={}
    ?? = H
    if 0 < N  :
        for  _ in range(N):
            x,y = [int(_) - 1 for _ in input().split()]
            if x >= y:
                ?? = x-y
                if ?? in dT:
                    if x + y < dT[??][2] :
                        dT[??] = (x,y,x+y)
                else:
                    dT[??] = (x,y,x+y)
        aB = sorted(dT.items())
        iL = len(aB)
        if iL == 1:
            ??,??,?? = aB[0][1]
        else:
            #???2
            #[(0, (1, 1, 2)), (1, (3, 2, 5)), (2, (5, 3, 8)), (4, (6, 2, 8)), (7, (7, 0, 7))]
            if 0 < len(aB) :
                aG= [aB[0][1]]
                for i in range(1,iL):
                    if aB[i][0]-1 == aB[i-1][0]:
                        if aB[i][1][2] < aB[i-1][1][2] :
                            aG.append(aB[i][1])
                    else:
                        aG.append(aB[i][1])
                if 0 < len(aG) and  aG[0][0] - aG[0][1] == 0 :
                    del aG[0]
                if 0 < len(aG) :
                    ??,??,?? = sorted(aG,key=lambda x:x[0])[0]
    print(??)
?()