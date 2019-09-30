from math import ceil
N = int(input())
A = [int(a) for a in input().split()]

if A[-1] != 2: print(-1)
else:
    PossibleMin, PossibleMax = A[-1], A[-1] + 1
    for i in reversed(range(N-1)):
        PossibleMin = ceil(PossibleMin/A[i]) * A[i]
        PossibleMax = (PossibleMax//A[i]) * A[i] + A[i] - 1
    if PossibleMax >= PossibleMin: print(PossibleMin, PossibleMax)
    else: print(-1)