N = int(input())
A = [int(i) for i in input().split()]
dnm = N
bugs = 0
for i in range(N):
    if A[i] == 0:
        dnm -= 1
    else:
        bugs += A[i]
import math
print(math.ceil(bugs / dnm))