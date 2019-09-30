import sys
from collections import Counter

N, X = map(int, input().split())
n1, n2 = N//2, N-N//2
a = list(map(int, sys.stdin))
w1, w2 = [0], [0]

for items, n, weights in ((a[:n1], n1, w1), (a[n1:], n2, w2)):
    for w in items:
        weights += [w+_w for _w in weights]

counter1, counter2 = Counter(w1), Counter(w2)
print(sum(counter2[X-k]*v for k, v in counter1.items() if k <= X))