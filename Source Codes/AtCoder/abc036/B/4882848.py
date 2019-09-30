import numpy as np

N = int(input())
x = [list(input()) for i in range(N)]
xn = np.array(x)
x = np.rot90(xn, k=-1)

for line in x:
    print('!'.join(line).replace('!',''))