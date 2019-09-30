import math

N,D=[int(_) for  _ in input().split()]
X,Y=[abs(int(_)) for  _ in input().split()]
if X % D != 0 and Y % D != 0 :
    print(0)
    exit()
X //= D
Y //= D

#def nCr(n,r):
#   if n-r < r :
#       r = n-r
#   if n == 0:
#       return 0
#   elif r == 0 :
#       return 1
#   elif r == 1:
#       return n
#   else:
#       return n / r * nCr(n-1,r-1)

aM = [1] *(N+1)
for i in range(1,N+1):
    aM[i] = aM[i-1]*i
def nCr(n,r):
    return aM[n] / aM[n-r] / aM[r]
def nCrlog(n,r):
    return math.log10(aM[n]) - math.log10(aM[n-r]) - math.log10(aM[r])

if N < X+Y :
    print(0)
elif N == X+Y:
    print(10 **( N * math.log10(0.25) + nCrlog(N,X)))
    #print(0.25**N * nCr(N,X))
elif (N - (X+Y)) % 2:
    print(0)
else:
    dxy = N - (X+Y)
    iC = 0
    for dx in range(dxy//2 + 1):
        dy = (dxy - 2*dx) // 2
        #iC += (0.25**N)* nCr(N,X+dx) * nCr(N-(X+dx),dx) * nCr(Y+2*dy,dy)
        iC += 10 **(N * math.log10(0.25) + nCrlog(N,X+dx) + nCrlog(N-(X+dx),dx) + nCrlog(Y+2*dy,dy))
    print( iC )