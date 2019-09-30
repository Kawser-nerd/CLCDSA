from collections import Counter


def inpl():
    return list(map(int, input().split()))


N = int(input())
A = inpl()

oe = [0, 0]
for k, v in Counter(A).items():
    oe[v % 2] += 1

if oe[0] % 2 == 0:
    print(sum(oe))
else:
    print(sum(oe) - 1)