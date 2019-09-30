from itertools import product
n = int(input())
for s in sorted(product('abc', repeat=n)):
  print(''.join(s))