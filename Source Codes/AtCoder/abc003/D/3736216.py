R,C = [int(_) for _ in input().split()]
X,Y = [int(_) for _ in input().split()]
D,L = [int(_) for _ in input().split()]
iD = 10**9+7

iMax = X*Y
aM = [1]*(iMax+1)
for i in range(1,iMax+1):
    aM[i]= aM[i-1]*i %iD
aInvM = [1]*(iMax+1)
aInvM[iMax] = pow(aM[iMax],iD-2,iD)
for i in range(iMax,0,-1):
    aInvM[i-1]=aInvM[i]*i % iD
def nCr(n,r):
    if n >= r:
        return aM[n] *  aInvM[r] * aInvM[n-r] %iD
    else:
        return 0

dxy = (R-X+1)*(C-Y+1)
NCR = nCr(iMax,D)

if X*Y == D+L :
    print( NCR * dxy % iD)

else:
    if X*Y -D -L < min(X,Y) :
        print( NCR * nCr(iMax-D,L) * dxy % iD)
    else: #????????
        A = NCR * nCr(iMax-D,L) %iD #?
        #??
        A -= nCr((X-1)*(Y),D)*nCr((X-1)*(Y) - D,L) * 2 %iD
        A -= nCr((X)*(Y-1),D)*nCr((X)*(Y-1) - D,L) * 2 %iD
        A += nCr((X-2)*(Y),D)*nCr((X-2)*(Y) - D,L)  %iD
        A += nCr((X)*(Y-2),D)*nCr((X)*(Y-2) - D,L)  %iD
        A += nCr((X-1)*(Y-1),D)*nCr((X-1)*(Y-1) - D,L) * 4 %iD
        A -= nCr((X-2)*(Y-1),D)*nCr((X-2)*(Y-1) - D,L) * 2 %iD
        A -= nCr((X-1)*(Y-2),D)*nCr((X-1)*(Y-2) - D,L) * 2 %iD
        A += nCr((X-2)*(Y-2),D)*nCr((X-2)*(Y-2) - D,L)  %iD
        print( A*dxy%iD )