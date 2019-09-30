from fractions import Fraction as F


def RP(f):
    return f - int(f)

def solve():
    k = int(raw_input())
    hh = []
    for i in xrange(k):
        pos, h, m = map(int, raw_input().split())
        for j in xrange(h):
            hh.append((F(pos, 360), F(1, m + j)))

    me_with = 0
    for i, hiker in enumerate(hh):
        if hiker < hh[me_with]:
            me_with = i

    tm = F(0, 1)
    res = 0
    while True:
        closest = F(int(1e19), 1)
        hikers = set()
        for i, hi in enumerate(hh):
            for j in xrange(i):
                hj = hh[j]
                if hi[1] == hj[1]:
                    continue
                posi = RP(hi[0] + hi[1] * tm)
                posj = RP(hj[0] + hj[1] * tm)

                if hi[1] > hj[1]:
                    dist = posj - posi
                    if dist <= 0:
                        dist += 1
                    delta = dist / (hi[1] - hj[1])
                else:
                    dist = posi - posj
                    if dist <= 0:
                        dist += 1
                    delta = dist / (hj[1] - hi[1])

                if delta < closest:
                    closest = delta
                    hikers = set()

                if delta == closest:
                    hikers.add(i)
                    hikers.add(j)

        if hikers is None:
            return res

        tm += closest
        if hh[me_with][0] + hh[me_with][1] * tm > F(1, 1):
            return res

        if me_with in hikers:
            for o in hikers:
                if hh[o][1] > hh[me_with][1]:
                    res += 1

            for o in hikers:
                if o != me_with:
                    me_with = o
                    break

        if hh[me_with][0] + hh[me_with][1] * tm >= F(1, 1):
            return res

    return res


t = int(raw_input())
for i in xrange(1, t + 1):
    print "Case #{0}: {1}".format(i, solve())
