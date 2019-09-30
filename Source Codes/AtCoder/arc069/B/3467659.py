def getSpecies(sw, ox, swAdj):
    if (sw == 'S' and ox == 'o') or (sw == 'W' and ox == 'x'):
        return swAdj
    else:
        return 'SW'[swAdj == 'S']

N = int(input())
ss = input()

for pat in ['SS', 'SW', 'WS', 'WW']:
    anss = list(pat) + [''] * (N - 2)
    for i in range(1, N - 1):
        anss[i + 1] = getSpecies(anss[i], ss[i], anss[i - 1])

    if (getSpecies(anss[-1], ss[-1], anss[-2]) == anss[0]) \
        and (getSpecies(anss[0], ss[0], anss[-1]) == anss[1]):
        print(''.join(anss))
        break
else:
    print(-1)