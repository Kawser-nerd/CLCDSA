def claim_differ(hp, mydmg, twrdmg):
    towShots = hp / twrdmg
    hp %= twrdmg

    if hp == 0:
        towShots -= 1
        hp += twrdmg

    myShots = hp / mydmg
    hp %= mydmg

    if hp > 0:
        myShots += 1
        hp = 0

    return towShots - myShots



def leave_differ(hp, twrdmg):
    towShots = hp / twrdmg
    hp %= twrdmg
    if hp > 0:
        towShots += 1
        hp = 0

    return towShots

INF = 10**12

def max_gain(mem, hps, glds, mydmg, twrdmg, mstr, extra_shots):
    if extra_shots < 0:
        return -INF

    if len(hps) == mstr:
        return 0

    key = (mstr, extra_shots)
    if key in mem:
        return mem[key]

    cd = claim_differ(hps[mstr], mydmg, twrdmg)
    res1 = glds[mstr] + max_gain(mem, hps, glds, mydmg, twrdmg, mstr + 1, extra_shots + cd)

    ld = leave_differ(hps[mstr], twrdmg)
    res2 =              max_gain(mem, hps, glds, mydmg, twrdmg, mstr + 1, extra_shots + ld)


    best = max(res1, res2)
    mem[key] = best

    return best


import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            mydmg, twrdmg, N  = map(int, inf.readline().split())
            hps, glds = [], []
            for _ in range(N):
                hp, gld = map(int, inf.readline().split())
                hps.append(hp)
                glds.append(gld)
            outf.write('Case #{}: {}\n'.format(t, max_gain({}, hps, glds, mydmg, twrdmg, 0, 1)))
