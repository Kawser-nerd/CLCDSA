A, B, C, D, E, F = [int(x) for x in input().split()]


ablist = []

a, b = 0, 0
while (100 * A * a + 100 * B * b <= F):
    while (100 * A * a + 100 * B * b <= F):
        ablist.append((a, b))
        b += 1
    a += 1
    b = 0
ablist.remove((0, 0))

wlist = [100 * A * ab[0] + 100 * B * ab[1] for ab in ablist]
wset = set(wlist)

cdlist = []
c, d = 0, 0
while (C * c + D*d <= F):
    while (C * c + D * d <= F):
        cdlist.append((c, d))
        d += 1
    c += 1
    d = 0

slist = [C * cd[0] + D * cd[1] for cd in cdlist]
sset = set(slist)

max_rate = -1
ret_sw = 0
ret_s = 0

for w in wset:
    for s in sset:
        if s + w <= F:
            rate = s / (s + w)
            if rate <= E/(E+100):
                if max_rate < rate:
                    max_rate = rate
                    ret_sw = s + w
                    ret_s = s

print("{} {}".format(ret_sw, ret_s))