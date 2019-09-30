import math
N, M = map(int, input().split())

n = 0
for i in range(1, int(math.sqrt(M))+1):
    if M < i * N:
        break

    if M % i == 0:
        n = max(i, n)
        if i >= N:
            n = max(M//i, n)

print(n)