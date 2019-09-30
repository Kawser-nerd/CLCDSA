N = int(input())
A = list(map(int, input().split()))
cnt = 0
f = True
while f:
    f = False
    for i in range(N):
        if A[i] >= N - cnt:
            q, m = divmod(A[i] + cnt + 1, N+1)
            A[i] = m - cnt - 1
            cnt += q
            f = True
print(cnt)