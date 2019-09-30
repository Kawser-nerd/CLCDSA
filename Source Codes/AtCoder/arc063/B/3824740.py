import sys
input = sys.stdin.readline

sys.setrecursionlimit(10000)


N, T = (int(i) for i in input().split())
A = [int(i) for i in input().split()]

ma = A[-1]
mas = 1
resma = 0
rescc = 0
for i in range(N-2, -1 ,-1):
    if A[i] > ma:
        ma = A[i]
        mas = 1
    elif A[i] == ma:
        mas += 1
    else:
        if ma - A[i] > resma:
            resma = ma - A[i]
            rescc = 1
        elif ma - A[i] == resma:
            rescc += 1
        else:
            pass

print(rescc)