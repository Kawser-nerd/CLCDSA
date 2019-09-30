from bisect import*
A, N, M = map(int, input().split())
L = [int(input()) for i in range(N)]
D = [a - b - 1 for a, b in zip(L[1:], L)]
D.sort()
E = [0]*(N)
for i in range(N-1):
    E[i+1] = D[i] + E[i]

ans = []
for i in range(M):
    x, y = map(int, input().split())
    j = bisect(D, x+y)
    res = E[j] + (N-j-1)*(x+y) + min(L[0]-1, x) + min(A-L[-1], y) + N
    ans.append(res)
print(*ans, sep='\n')