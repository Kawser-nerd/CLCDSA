n, m = map(int, input().split())

l = []
r = []
s = []

for i in range(n):
    _l, _r, _s = map(int, input().split())
    l.append(_l)
    r.append(_r)
    s.append(_s)

imos = [0 for i in range(m + 1)]
imos[m] = 10 ** 14

for i in range(n):
    imos[l[i] - 1] += s[i]
    imos[r[i]] -= s[i]

for i in range(m):
    imos[i + 1] += imos[i]

print(sum(s) - min(imos))