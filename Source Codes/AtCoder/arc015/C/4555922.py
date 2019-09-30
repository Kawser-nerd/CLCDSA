from fractions import Fraction

par = [i for i in range(400)]
diff = [1 for _ in range(400)]

def find(x):
    if par[x] == x: return x
    r = find(par[x])
    diff[x] *= diff[par[x]]
    par[x] = r
    return par[x]

def weight(x):
    find(x)
    return diff[x]

def unite(x, y, w):
    w *= weight(x)
    w /= weight(y)
    x = find(x)
    y = find(y)
    par[y] = x
    diff[y] = w

n = int(input())
id = {}
rev = {}
N = 0
for _ in range(n):
    [a, d, b] = input().split()
    d = int(d)
    if a not in id:
        id[a] = N
        rev[N] = a
        N += 1
    if b not in id:
        id[b] = N
        rev[N] = b
        N += 1
    unite(id[a], id[b], Fraction(d, 1))

ws = {}
for i in range(N):
    if find(i) not in ws:
        ws[find(i)] = [[weight(i), i]]
    else:
        ws[find(i)].append([weight(i), i])

ans = 0
for r in ws:
    w = sorted(ws[r])
    if ans < w[-1][0] / w[0][0]:
        ans = w[-1][0] / w[0][0]
        small = rev[w[-1][1]]
        large = rev[w[0][1]]


print("1{}={}{}".format(large, ans, small))