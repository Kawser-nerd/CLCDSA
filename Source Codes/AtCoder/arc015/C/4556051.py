import sys
from math import log
from fractions import gcd  # python<=3.4
from collections import defaultdict

def read_int():
  return int(input())

def read_fields():
  return input().split()

N = read_int()
names = set()
mag = defaultdict(dict)  # a/b
for i in range(N):
    big, _m, small = read_fields()
    m = int(_m)
    names.add(big)
    names.add(small)
    mag[small][big] = (m, 1)
    mag[big][small] = (1, m)

names = list(names)

q = [(names[0], (1,1))]
i = 0
val = {}

def mul(a, b):  # a * b
    n1, d1 = a
    n2, d2 = b
    n = n1*n2
    d = d1*d2
    g = gcd(n, d)
    return (n//g, d//g)

def div(a, b):  # a / b
    n1, d1 = a
    n2, d2 = b
    n = n1*d2
    d = d1*n2
    g = gcd(n, d)
    return (n//g, d//g)

while i < len(q):
    u, ur = q[i]
    i += 1
    val[u] = ur

    for v, m in mag[u].items():
        if v in val:
            continue
        q.append((v, mul(ur, m)))

tmp = sorted([(log(n)-log(d), u, (n,d)) for u,(n,d) in val.items()])

_, smallest, smallest_r = tmp[0]
_, largest, largest_r = tmp[-1]

n, d = div(largest_r, smallest_r)
ans = int(n / d)
print('1%s=%d%s' % (largest, ans, smallest))