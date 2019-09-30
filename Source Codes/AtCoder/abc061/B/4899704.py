from collections import OrderedDict
N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(M)]
X = OrderedDict([(i + 1, []) for i in range(N)])
for a, b in L:
    X[a].append(b)
    X[b].append(a)
for _, x in X.items():
    print(len(x))