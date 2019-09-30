import sys

N = int(input())
a = list(map(int, sys.stdin))
d = {n: i % 2 for i, n in enumerate(sorted(a))}
print(len([1 for i, n in enumerate(a) if i % 2 != d[n]]) // 2)