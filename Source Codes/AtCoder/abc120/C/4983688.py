import numpy as np
s = [int(i) for i in input()]
array = np.array(s)
zero = np.sum(array==0)
one = np.sum(array==1)
print(2*min(zero,one))