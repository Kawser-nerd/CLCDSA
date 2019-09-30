from math import ceil
N = int(input())
A = [int(a) for a in input().split()]

DP = 1
for a in A:
    DP |= DP << a

Shalf = ceil(sum(A)/2)
DP >>= Shalf
for i in range(N * max(A)):
    if DP & 1:
        print(Shalf + i)
        break
    DP >>= 1