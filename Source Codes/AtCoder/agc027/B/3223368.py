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

def fSearchLowCost(iL,iLCost,iU,iUCost,iN,iX,aCum):
    if iU - iL <= iX :
        iTotalCost = min(iLCost,iUCost)
        for iK in range(iL+1,iU) :
            iTotalCost = min(iTotalCost,fCalcCost(iN,iX,aCum,iK))
        return iTotalCost
    else:
        iM = (iU + iL) // 2
        iMCost = fCalcCost(iN,iX,aCum,iM)
        if iLCost < iUCost :
            return fSearchLowCost(iL,iLCost,iM,iMCost,iN,iX,aCum)
        else :
            return fSearchLowCost(iM,iMCost,iU,iUCost,iN,iX,aCum)

if 1 < iN :

    iULim = fCeil(iN,2)+1
    iLLim = 1
    print(fSearchLowCost(iLLim,fCalcCost(iN,iX,aCum,iLLim),iULim,fCalcCost(iN,iX,aCum,iULim),iN,iX,aCum))
else:
    print(2*iX + 5*aX[0])