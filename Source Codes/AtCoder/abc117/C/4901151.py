N,M = map(int, input().split())
X = [int(i) for i in input().split()]

if N >= M:
    print(0)
    exit()


X.sort()
L = [X[i+1] - X[i] for i in range(len(X)-1)]
L.sort()

print(sum(L[:(M-N)]))