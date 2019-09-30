import numpy as np 
N, P = map(int, input().split())
A = np.array(list(map(int, input().split())))

even = ((A % 2) == 0).sum()
odd = len(A) - even
flag = True

if (P == 1) & (odd == 0):
  print(0)
  flag = False

if flag:
  if odd == 0:
    print(2**even)
  else:
    print((2**even) * (2**(odd - 1)))