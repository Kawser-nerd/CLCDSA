import math

N = int(input())

ans = 0
square_root = int(math.sqrt(N))
end = square_root if square_root ** 2 == N else square_root + 1
for i in range(1, end):
    if N % i == 0:
        ans += (N // i + i)

ans -= N

if ans == N:
    output = 'Perfect'
elif ans > N:
    output = 'Abundant'
else:
    output = 'Deficient'

print(output)