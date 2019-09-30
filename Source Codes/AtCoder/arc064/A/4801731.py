N,x = map(int,input().split())
A = [0] + [int(a) for a in input().split()]

ans = 0
for i in range(N):  
    if A[i] + A[i+1] >= x:
        ans += A[i] + A[i+1] - x
        A[i+1] -= A[i] + A[i+1] -x
print(ans)