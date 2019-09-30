import numpy as np

N, L, T = map(int, input().split())

X0 = np.zeros(N, dtype=np.int)
W = np.zeros(N, dtype=np.int)
for i in range(N):
    X0[i], W[i] = map(np.int, input().split())

X = X0 + T * (3 - 2*W) #(2*(1.5 - W))
count = np.sum(X // L)	#x=0????????0????????????????
#print(count)
count %= N

X %= L
X.sort()

for x in X[count:]:
    print(x)
for x in X[:count]:
    print(x)