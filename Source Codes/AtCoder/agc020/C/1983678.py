import math
N = int(input())
A = list(map(int, input().split()))
sumA = sum(A)
halfA = math.ceil(sumA / 2)
bitset = 1
for a in A:bitset |= bitset << a
bitset >>= halfA
i = 0
while 1:
    if bitset & 1:
        print(i + halfA)
        exit()
    bitset >>= 1
    i += 1