N = int(input())
A = list(map(int,input().split()))

ans = 0
while any([a>N-1 for a in A]):
    A.sort()
    d = A[-1] - (N-1)
    k = -(-d//N)
    ans += k
    A[-1] -= k*N
    for i in range(N-1):
        A[i] += k
print(ans)