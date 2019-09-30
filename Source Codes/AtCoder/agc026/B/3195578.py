import sys

iT = int(input())
aR = [[int(x) for x in sLine.split()] for sLine in sys.stdin.readlines()]

def fGcd(iX,iY):
    while iY:
        iX,iY= iY,iX%iY
    return iX

def fFunc(iA,iB,iC,iD):
    ig = fGcd(iB,iD)
    if iA < iB or iD < iB:
        return False
    elif iC >= iB :
        return True
    elif iC < iA % iB :
        return False

# ??????
    elif iB <= ig + iC :
# AtCoder ???
#   elif iB <= iC +ig - iA % ig  :
        return True
    else:
        return False

for eR in aR:
    if fFunc(*eR) :
        print("Yes")
    else:
        print("No")