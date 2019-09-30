#import matplotlib.pyplot as plt


iR,iG,iB=[int(_) for _ in input().split()]

if iR < iB:
    iR,iB = iB,iR
def calcMoveEach(n):
    return n*(n+1) // 2
def calcMove(a,l):
    if l < a :
        return calcMoveEach(l) + calcMoveEach(a-l-1)
    else:
        return calcMoveEach(l) - calcMoveEach(l-a)
def diffmod2(t):
    return 1 if t % 2 == 0 else 0

if iR < 100 and iG < 100 and iB < 100 :
    print( calcMove(iR,iR//2) + calcMove(iG,iG//2)+calcMove(iB,iB//2))
else:
    #px = []
    #py = []
    iDiff = max(iG,iR,iB)
    iAns = calcMove(iDiff,900) #max
    for iED in range(-iDiff,iDiff):
        lG = iG + iED
        lR = max(100+ iR//2 , iR + lG)
        rB = max(100+ iB//2 , iB + (iG - lG -1) )

        iLLL = calcMove(iR,lR - 100) + calcMove(iG,max(lG,iG-lG-1))+ calcMove(iB,rB-100)
        #px.append(iED)
        #py.append(iLLL)
        iAns = min(iAns, iLLL)
    print(iAns)
    #plt.plot(px,py)
    #plt.show()