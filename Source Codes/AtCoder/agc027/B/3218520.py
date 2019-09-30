iN ,iX  = [int(x) for x in input().split()]
aX = [int(x) for x in input().split()]

aCum = [0]*iN
aCum[0] = aX[0]
for i in range(1,iN):
    aCum[i]=aCum[i-1]+aX[i]

def fCeil(iT,iR):
    return -1 * iT // iR * -1
#???????????????????
def fCalcCost(iN,iX,aCum,iK):
    return (iN + iK ) * iX + 5 * aCum[-1] +sum(2*aCum[-i*iK -1] for i in range(2,fCeil(iN,iK)))

iTotalCost = fCalcCost(iN,iX,aCum,1)
iULim = fCeil(iN,2) + 1
for iK in range(2,fCeil(iN,2)+1):
    iThisCost = fCalcCost(iN,iX,aCum,iK)
    if iThisCost > iTotalCost:
        break
    else:
        iTotalCost = iThisCost
print(iTotalCost)