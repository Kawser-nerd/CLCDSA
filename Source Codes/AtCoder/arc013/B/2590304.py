import numpy as np
C = int(input())
NML = np.array([list(sorted(map(int, input().split()))) for i in range(C)])
Z = [i for i in np.max(NML, axis=0)]
print(Z[0] * Z[1] * Z[2])