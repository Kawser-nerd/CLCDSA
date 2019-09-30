# E
import numpy as np

N = int(input())

X = [0]*N
Y = [0]*N

for i in range(N):
    x, y = map(int, input().split())
    X[i] = min(x, y)
    Y[i] = max(x, y)


# CASE1
res1 = (max(Y) - min(Y)) * (max(X) - min(X))

# CASE2
x_arg = np.argsort(X)
max_a = max(X)
min_a = min(X)
min_b = 1000000001
max_b = 0
res2 = max_a - min_a

for i in range(N-1):
    min_b = min(min_b, Y[x_arg[i]])
    max_a = max(max_a, Y[x_arg[i]])
    if min_b <= X[x_arg[i]]:
        break
    else:
        min_a = min(X[x_arg[i+1]], min_b)
        res2 = min(res2, max_a - min_a)
print(min(res1, res2*(max(Y)-min(X))))