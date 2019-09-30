def inpl(): return [int(i) for i in input().split()]

N, T = inpl()
A = inpl()
minA = [0 for _ in range(N)]
minA[0] = A[0]
for i in range(N-1):
    minA[i+1] = min(minA[i], A[i+1]) 
ans = 1
maxpro = 0
for i in range(N-1):
    if A[i+1]-minA[i] == maxpro:
        ans += 1
    if A[i+1]-minA[i] > maxpro:
        ans = 1
        maxpro = A[i+1]-minA[i]

print(ans)