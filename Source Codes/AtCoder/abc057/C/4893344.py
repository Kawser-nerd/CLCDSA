import numpy as np
 
n = int(input())
n_s = int(np.sqrt(n))
 
b = n
a = 1
 
for i in range(2, n_s+1):
  if n % i == 0:
    a = i
    b = n//i
 
print(int(max(np.log10(a), np.log10(b)))+1)