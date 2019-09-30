import sys

def revBit(Ai):
    return '1' if Ai == '0' else '0'

def rec(binA, binB):
    if len(binA) == 1:
        return [binA, binB]

    for i, (Ai, Bi) in enumerate(zip(binA, binB)):
        if Ai != Bi:
            x = i
            Ax, Bx = Ai, Bi
            break

    binA2 = binA[:x] + binA[x+1:]
    binB2 = binB[:x] + binB[x+1:]
    binC = binA2[:-1] + revBit(binA2[-1])

    ptn1s = rec(binA2, binC)
    ptn2s = rec(binC, binB2)

    ptns = []
    for ptn1 in ptn1s:
        ptns.append(ptn1[:x] + Ax + ptn1[x:])
    for ptn2 in ptn2s:
        ptns.append(ptn2[:x] + Bx + ptn2[x:])

    return ptns


N, A, B = map(int, input().split())

binA, binB = bin(A)[2:].zfill(N), bin(B)[2:].zfill(N)
numDiff = sum([Ai != Bi for Ai, Bi in zip(binA, binB)])

if numDiff % 2 == 0:
    print('NO')
    sys.exit()

ptns = rec(binA, binB)
print('YES')
print(' '.join([str(int(ptn, 2)) for ptn in ptns]))