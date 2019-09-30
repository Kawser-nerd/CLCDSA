import math

N = int(input())
A = list(map(int, input().split()))

s = 0
c = 0
for a in A:
    if a != 0:
        c += 1
    s += a

print(int(math.ceil(s/c)))