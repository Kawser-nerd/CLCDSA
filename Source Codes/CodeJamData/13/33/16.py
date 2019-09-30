f = open('in.txt')

T = int(f.readline())


LEN = 100000
spots = None
def qu(s):
    return spots[s - LEN/2]

def set(s, n):
    spots[s - LEN/2] = n

def solve():
    nsuc = 0
    last_day = -1
    to_build = []

    #print attacks
    for attack in attacks:
        suc = 0
        #print 'day ', attack[0]

        if attack[0] != last_day:
            for pos,h in to_build:
                if qu(pos) < h:
                    set(pos, h)

        for p in xrange(attack[2][0], attack[2][1]):
            if qu(p) < attack[1]:
                to_build.append((p, attack[1]))
                suc = 1
        #if suc:
        #    print 'suc', attack[1], attack[2][0], attack[2][1]
        nsuc += suc
        last_day = attack[0]

    return nsuc

for i in xrange(T):
    attacks = []
    spots = [0] * LEN

    N = int(f.readline())
    for j in xrange(N):
        d, n, w, e, s, dd, dp, ds = map(int, f.readline().split())
        attack = []

        for k in xrange(n):
            attack = []
            # print d
            attack.append(d + dd*k)
            attack.append(s + ds*k)
            attack.append((w+dp*k, e+dp*k))

            attacks.append(attack)

    attacks.sort()
    print 'Case #%d: %d' % (i+1, solve())



