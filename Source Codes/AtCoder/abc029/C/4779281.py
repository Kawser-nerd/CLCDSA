from itertools import product
N=int(input())

for p in product(['a','b','c'], repeat=N):
  print(''.join(p))