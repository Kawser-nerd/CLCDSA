import sys
import collections
import math
from collections import Counter
from collections import deque

N, M = [int(x) for x in input().split()]

D = 10 ** 9 + 7

if abs(N - M) >= 2:
    print(0)
    sys.exit(0)

ret = math.factorial(N) * math.factorial(M)

if N == M:
    ret *= 2


print(ret % D)