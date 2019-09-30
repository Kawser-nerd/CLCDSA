import numpy as np
n = int(input())
t = int(np.log10(n) + 1)
s = (n + 1) // (10**(t-1))
print(9*(t-1) + s-1)