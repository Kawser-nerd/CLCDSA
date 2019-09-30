import sys
#??????????????
def ?():
    iD = 10**9+7

    iN = int(input())
    aData = [[int(_) for _ in sLine.split()] for sLine in sys.stdin.readlines()]
    def addBlanch(D ,a,b):
        if a in D:
            D[a].add(b)
        else:
            D[a] = {b}
    aT ={}

    for a,b in aData:
        addBlanch(aT,a,b)
        addBlanch(aT,b,a)

    aL = {0:set()}
    def setLevel(iI,iL,iP):
        addBlanch(aL,iL,iI)
        for i in aT[iI] - {iP}:
            setLevel(i,iL+1,iI)
    setLevel(1,1,0)

    aF = [1]*(iN+1)
    aG = [1]*(iN+1)
    iL = len(aL)
    for i in range(iL-1,0,-1): #?????
        for x in aL[i] :
            dsChild = aT[x] - aL[i-1]
            aFChild = 1
            aGChild = 1
            for y in dsChild:
                aGChild *= aG[y] % iD
                aFChild *= aF[y] % iD
            #???????????????????????????
            aG[x] = aFChild
            aF[x] = aG[x] + aGChild
    print(aF[1] % iD)
?()