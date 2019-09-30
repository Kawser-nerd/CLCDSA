import functools

n = int(input())
d = [[] for i in range(n)]
for a in range(1, n):
    b = int(input()) - 1
    d[b].append(a)

@functools.lru_cache()
def solve(x):
    childs = d[x]
    if len(childs) == 0:
        return 1
    else:
        fees = [solve(child) for child in childs]
        return max(fees) + min(fees) + 1

print(solve(0))