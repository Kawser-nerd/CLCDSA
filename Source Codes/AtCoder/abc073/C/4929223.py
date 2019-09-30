import collections

n = int(input())

A = [0] * n
for i in range(n):
    A[i] = int(input())


d = [k for k, v in collections.Counter(A).items() if v%2 != 0]

print(len(d))