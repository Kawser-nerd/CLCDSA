import numpy as np

D = np.array([int(_) for _ in input().split()])
J = np.array([int(_) for _ in input().split()])
print(sum(np.maximum(D, J)))