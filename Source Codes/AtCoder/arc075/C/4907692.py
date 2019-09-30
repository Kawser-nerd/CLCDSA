from itertools import accumulate

def init(As):
    numPow2 = 2 ** (len(As)-1).bit_length()
    data = [0] * (numPow2+1)
    return data, numPow2

def addValue(iA, A):
    iA += 1
    while iA <= numPow2:
        data[iA] += A
        iA += iA & -iA

def getSum(iA):
    iA += 1
    ans = 0
    while iA > 0:
        ans += data[iA]
        iA -= iA & -iA
    return ans


N, K = map(int, input().split())
As = [int(input()) for _ in range(N)]

Bs = list(accumulate([0]+[A-K for A in As]))
iBs = list(range(N+1))
iBs.sort(key=lambda iB: Bs[iB])

data, numPow2 = init([0]*(N+1))

ans = 0
for iB in iBs:
    addValue(iB, 1)
    ans += getSum(iB-1)

print(ans)