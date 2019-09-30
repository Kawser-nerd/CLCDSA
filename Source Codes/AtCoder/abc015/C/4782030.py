N, K = list(map(int, input().split()))
T = [list(map(int, input().split())) for _ in range(N)]

from itertools import product
from functools import reduce
from operator import xor

for cand in product(*T):
  if reduce(xor, cand):
    pass
  else:
    print('Found')
    exit()
else:
  print('Nothing')