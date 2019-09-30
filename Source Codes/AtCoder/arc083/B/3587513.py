def inpl(): return [int(i) for i in input().split()]
import sys
import numpy 
N = int(input())
A = numpy.array([inpl() for _ in range(N)])
ans = 0
for i in range(N):
    A[i][i] = 10**9+1
for i in range(N):
    for j in range(i):
        mindis = numpy.min(A[i] + A[j])
        if mindis > A[i][j]:
            ans += A[i][j]
            continue
        if mindis < A[i][j]:
            print(-1)
            sys.exit()
print(ans)