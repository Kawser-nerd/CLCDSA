N = int(input())
*parent, = range(26)
D = [2**10-1]*26
def root(x):
    if x == parent[x]:
        return x
    parent[x] = y = root(parent[x])
    return y
def unite(x, y):
    px = root(x); py = root(y)
    if px < py:
        parent[py] = px
        D[px] &= D[py]
    else:
        parent[px] = py
        D[py] &= D[px]

NZ = 2**10-2
from string import digits
s1 = input()
s2 = input()
s = set()
for i in range(N):
    if s1[i] in digits and s2[i] in digits:
        continue
    if s1[i] in digits:
        c = ord(s2[i])-65
        x = root(c)
        s.add(c)
        D[x] &= 1 << int(s1[i])
        if not i:
            D[x] &= NZ
    elif s2[i] in digits:
        c = ord(s1[i])-65
        x = root(ord(s1[i])-65)
        s.add(c)
        D[x] &= 1 << int(s2[i])
        if not i:
            D[x] &= NZ
    else:
        c1 = ord(s1[i])-65
        c2 = ord(s2[i])-65
        s.add(c1); s.add(c2)
        unite(c1, c2)
        if not i:
            D[root(c1)] &= NZ
ans = 1
for i in range(26):
    if i in s and root(i) == i:
        ans *= bin(D[i]).count('1')
print(ans)