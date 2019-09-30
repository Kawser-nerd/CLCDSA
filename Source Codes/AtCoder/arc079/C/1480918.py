n,*A=map(int,open(0).read().split())
ans = 0
while 1:
    A.sort(reverse=1)
    if A[0] > A[-1]+n:
        p = (A[0] - A[-1]) // (n+1)
        for j in range(n):
            A[j] += p
        A[0] -= p*(n+1)
        ans += p
    else:
        break
if max(A) >= 2*n:
    ans += (max(A) - 2*n)*n
    ma = max(A) - 2*n
    for i in range(n):
        A[i] -= ma
while max(A) >= n:
    for i in range(n):
        A[i] += 1
    A[A.index(max(A))] -= n+1
    ans += 1
print(ans)