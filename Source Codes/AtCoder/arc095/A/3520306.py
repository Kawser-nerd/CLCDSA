import bisect

N = int(input())
X = [int(x) for x in input().split()]

X2 = sorted(X)

for i in range(0, N):
    # idx = X2.index(X[i])
    idx = bisect.bisect_left(X2, X[i])
    if idx < N // 2:
        print(X2[N // 2])
    else:
        print(X2[N // 2 - 1])