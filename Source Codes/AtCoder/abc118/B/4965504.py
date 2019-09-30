import functools
N, M = map(int, input().split())
A = [set(map(int, input().split()[1:])) for _ in range(N)]
print(len(functools.reduce(set.intersection, A)))