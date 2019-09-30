from math import sqrt
import sys

N = int(input())

for i in range(2, int(sqrt(N))+1):
    if N%i == 0:
        print('NO')
        sys.exit()
print('YES')