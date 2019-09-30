N, M = map(int, input().split())

A = [0]*(M+1)

s_sum = 0
for i in range(N):
    l, r, s = map(int, input().split())
    A[l-1] += s
    A[r] -= s
    s_sum += s

import itertools

B = list(itertools.accumulate(A))

print(s_sum - min(B[0:-1]))