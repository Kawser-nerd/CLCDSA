from copy import deepcopy
def swap(a, b, l):
    s = deepcopy(l)
    s[a], s[b] = s[b], s[a]
    return s

n, k = map(int, input().split())
raw = input()
s = list(raw)
f = lambda s: sum([1 for (i, j) in enumerate(s) if j != raw[i]])
g = lambda s: "".join(s)
l = []

for i in range(n):
    b = i
    for j in range(i + 1, n):
        if s[b] > s[j] and f(swap(i, j, s)) <= k:
            b = j
    s = swap(i, b, s)
print(g(s))