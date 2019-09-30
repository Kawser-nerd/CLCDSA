from math import ceil
N = int(input())
C = [int(input()) for i in range(N)]
C += C

if len(set(C)) == 1:
    print(-1)
else:
    X = 1
    tmp = 1
    for i in range(len(C)):
        if C[i] == C[i-1]:
            tmp += 1
        else:
            X = max(X, tmp)
            tmp = 1
    print(ceil(X / 2))