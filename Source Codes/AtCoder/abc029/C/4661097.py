from itertools import product
n=int(input())
for i in [''.join(s) for s in list(product(['a','b','c'], repeat=n))]:
  print(i)