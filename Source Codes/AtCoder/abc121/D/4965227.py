import sys
import numpy as np

reatInt = lambda: int(sys.stdin.readline())
reatIntN = lambda: [int(v) for v in sys.stdin.readline().split(' ')]

a, b = reatIntN()
b += 1
a = ((a // 2) % 2) ^ ((a-1) * (a % 2))
b = ((b // 2) % 2) ^ ((b-1) * (b % 2))
ret = a ^ b
print(ret)