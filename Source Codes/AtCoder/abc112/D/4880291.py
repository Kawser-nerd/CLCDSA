from math import sqrt
N, M = map(int, input().split())
cand = 1
for i in range(1, int(sqrt(M))+1):
    if M % i == 0:
        if M >= (M // i) * N:
            cand = max(cand, M//i)
        elif M >= i * N:
            cand = max(cand, i)
print(cand)