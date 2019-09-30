import functools
print(functools.reduce(lambda x, y: x * y, [max(i) for i in zip(*[sorted(i) for i in [[int(j) for j in input().split()] for i in range(int(input()))]])]))