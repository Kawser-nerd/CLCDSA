import math

N = int(input())

ans = (-1) * N
square_root = int(math.sqrt(N))
if square_root ** 2 == N:
    end = square_root
    ans -= square_root
else:
    end = square_root + 1

for i in range(1, end):
    if N % i == 0:
        ans += (N // i + i)

print('Perfect' if ans == N else 'Abundant' if ans > N else 'Deficient')