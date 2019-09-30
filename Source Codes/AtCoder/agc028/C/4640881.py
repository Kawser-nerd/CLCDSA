N = int(input())
As, Bs = [], []
for i in range(N):
    A, B = map(int, input().split())
    As.append((A, i))
    Bs.append((B, i))

ansA = sum([A for A, i in As])
ansB = sum([B for B, i in Bs])

Cs = sorted(As + Bs)

useds = [False] * N
sumC = 0
for C, i in Cs[:N]:
    useds[i] = True
    sumC += C

if not all(useds):
    ansC = sumC
elif Cs[N-1][1] != Cs[N][1]:
    ansC = sumC - Cs[N-1][0] + Cs[N][0]
else:
    ansC = min(sumC - Cs[N-2][0] + Cs[N][0], sumC - Cs[N-1][0] + Cs[N+1][0])

print(min(ansA, ansB, ansC))