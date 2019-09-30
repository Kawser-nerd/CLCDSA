import math

N = int(input())
a = [list(map(int, input().split())) for i in range(N)]

sum = 0
for i in range(N):
    sum += a[i][0] * a[i][1]

sum *= 1.05
print(math.floor(sum))