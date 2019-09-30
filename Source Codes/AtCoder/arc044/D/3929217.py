N = int(input())
*A, = map(int, input().split())

A = [N+1] + A
C = [0]*(N+1)
for i, b in enumerate(A):
    C[b-1] = i

cur = ord('A')
end = ord('Z')
ans = [None]*N
ans[A[1]-1] = cur
for i in range(1, N):
    a = A[i]; b = A[i+1]
    if C[a] > C[b]:
        cur += 1
    ans[A[i+1]-1] = cur
if cur > end:
    print(-1)
else:
    print(*map(chr, ans), sep='')