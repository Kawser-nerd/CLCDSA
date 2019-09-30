K = int(input())
N = 50
if K <= N:
    ans = [N]*K + [0]*(N-K)
    print(N)
    print(*ans)
    exit()

ans = list(range(N,0,-1))
d,m = divmod(K,N)
for i in range(N):
    ans[i] += d-1 + int(i < m)

print(N)
print(*ans)