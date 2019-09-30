iN ,iX  = [int(x) for x in input().split()]
aCum = [0]
for x in input().split():
    aCum += [aCum[-1] + int(x)]

def fCeil(iT,iR):
    return -1 * iT // iR * -1

def fCalcCost(iN,iX,aCum,iK):
    iCost = (iN + iK ) * iX + 5 * aCum[iN]
    for i in range(2,fCeil(iN,iK) ):
        iCost += 2 * aCum[iN - i * iK ]
    return iCost

#???
iTotalCost = fCalcCost(iN,iX,aCum,1)
for iK in range(2,fCeil(iN,2) + 1):
    iThisCost = fCalcCost(iN,iX,aCum,iK)
    if iThisCost > iTotalCost:
        break
    else:
        iTotalCost = iThisCost
print(iTotalCost)