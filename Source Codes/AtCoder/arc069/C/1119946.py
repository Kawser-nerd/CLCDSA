from collections import defaultdict, Counter
n = int(input())
a = list(map(int, input().split()))
c = Counter(a)


values = reversed(sorted(set(a)))
s = 0
m = 0
above = dict()
n_above = dict()
for v in values:
    above[v] = s
    n_above[v] = m
    s += c[v] * v
    m += c[v]
above[0] = s
n_above[0] = m


m = 0
u = [0]
for v in a:
    if v > m:
        u.append(v)
        m = v

r = defaultdict(int)
last = 0
for j, v in enumerate(u):
    r[v] = last - (above[v] - n_above[v] * v)
    last = above[v] - n_above[v] * v



m = 0
for v in a:
    if v > m:
        print(r[v])
        m = v
    else:
        print(0)