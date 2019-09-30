import sys
import collections
import math
from collections import Counter
from collections import deque

n = int(input())
A = [int(x) for x in input().split()]

Q = deque()

f = True
if n % 2 == 0:
    f = not f

for a in A:
    if f:
        Q.appendleft(a)
    else:
        Q.append(a)
    f = not f

print(" ".join([str(q) for q in Q]))

sys.exit(0)