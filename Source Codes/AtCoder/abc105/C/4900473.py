import math
N = int(input())

s = ''

if N == 0:
    s = str(0)
while N != 0:
    if N%(-2) == -1:
        s += str(1)
        N //= (-2)
        N += 1
    else:
        s += str(N % (-2))
        N //= (-2)
print(s[::-1])