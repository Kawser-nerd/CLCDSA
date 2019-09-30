def getGrundyNumber(x):
    ans = 1
    while x % (ans * 2) == 0:
        ans *= 2
    return ans


N, L = map(int, input().split())
Ss = [input() for i in range(N)]

Ss.sort()

Hgts = {L: 2}
prev = '_'
for S in Ss:
    for iS, (a, b) in enumerate(zip(prev, S)):
        if a != b:
            Hgts[L - iS] -= 1
            for h in range(L - len(S) + 1, L - iS):
                Hgts[h] = Hgts.get(h, 0) + 1
            break
    prev = S

ans = 0
for Hgt, num in Hgts.items():
    if num % 2:
        ans ^= getGrundyNumber(Hgt)

if ans:
    print('Alice')
else:
    print('Bob')