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

if ans == N:
    output = 'Perfect'
elif ans > N:
    output = 'Abundant'
else:
    output = 'Deficient'

print(output)