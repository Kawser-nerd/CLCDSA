import math

N = int(input())

ans = 0
end = int(math.sqrt(N)) if int(math.sqrt(N)) ** 2 == N else int(math.sqrt(N)) + 1
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