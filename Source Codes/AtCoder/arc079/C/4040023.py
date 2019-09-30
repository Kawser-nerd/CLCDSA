N = int(input())
A = list(map(int,input().split()))

ans = 0
while any([a>N-1 for a in A]):
    for i in range(N):
        if A[i] <= N-1: continue
        d = A[i] - (N-1)
        k = -(-d//N)
        A[i] -= k*N
        ans += k
        for j in range(N):
            if j==i: continue
            A[j] += k
print(ans)