from collections import Counter
N, M = map( int, input().split())
A = [ [] for _ in range(N)]
for i in range(N):
    A[i] = list( map( int, input().split())) 
V = [1]*(M+1)
ans = N
for _ in range(M-1):
    W = []
    for i in range(N):
        while True:
            if V[A[i][0]] == 1:
                W.append(A[i][0])
                break
            else:
                A[i].pop(0)
    a, c = Counter(W).most_common()[0]
    ans = min( ans, c)
    V[a] = 0
print(ans)