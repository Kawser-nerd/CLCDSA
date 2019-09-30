def simulate(N):
    for A in As:
        N -= N % A
    return N

K = int(input())
As = list(map(int, input().split()))

iLft, iRgt = 1, sum(As) - K + 3
while iRgt - iLft > 1:
    iMid = (iLft + iRgt) // 2
    if simulate(iMid) < 2:
        iLft = iMid
    else:
        iRgt = iMid
ansMin = iRgt

iLft, iRgt = 1, sum(As) - K + 3
while iRgt - iLft > 1:
    iMid = (iLft + iRgt) // 2
    if simulate(iMid) <= 2:
        iLft = iMid
    else:
        iRgt = iMid
ansMax = iLft

if ansMin <= ansMax:
    print(ansMin, ansMax)
else:
    print(-1)