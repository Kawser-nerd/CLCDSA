from random import sample
def gcd(x, y):
    if x < y:# x >= y ???
        x, y = y, x
    r = x % y
    res = y if r == 0 else gcd(y, r)
    return res

n = int(input())

nl = []
for j in range(1, 30000 + 1):
    if (j % 2 == 0 or j % 3 == 0 or j % 5 == 0):
        nl.append(j)
len_nl = len(nl)

while True:
    tl = sample(nl, len_nl)
    g = tl[0]
    total = 0
    for j in range(n):
        g = gcd(g, tl[j])
        total += tl[j]
    if total % 30 != 0:
        continue
    if g != 1:
        continue
    break
print(*tl[:n])