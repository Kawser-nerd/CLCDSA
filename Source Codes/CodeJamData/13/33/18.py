

def solve(n_t, tribes):
    attacks = {}
    for d, n, w, e, s, delta_d, delta_p, delta_s in tribes:
        for i in range(n):
            dist = delta_p * i
            day = d + delta_d * i
            east = e + dist
            west = w + dist
            strength = s + delta_s * i
            attacks_on_day = attacks.setdefault(day, [])
            attacks_on_day.append((east, west, strength))

    # print attacks

    max_dist = 10000000
    # max_dist = 100
    offset = max_dist + 1
    wall_len = 2 * max_dist + 1
    wall = wall_len * [0]

    days = sorted(attacks.keys())

    succeded_count = 0
    for day in days:
        new_wall = wall[:]
        for east, west, strength in attacks[day]:
            succeded = False
            for p in range(west, east):
                idx = p + offset
                if wall[idx] < strength:
                    succeded = True
                new_wall[idx] = max(new_wall[idx], strength)
            if succeded:
                succeded_count += 1
        wall = new_wall

    return succeded_count

##############################################################################

def read_ints(f):
    s = f.readline()
    return [int(w) for w in s.strip().split()]


from sys import argv

in_fn = argv[1]
out_fn = len(argv) > 2 and argv[2] or in_fn + '.out'

in_f = open(in_fn)
out_f = open(out_fn, 'w')

T = int(in_f.readline().strip())

for i_t in range(T):
    n_t = int(in_f.readline().strip())
    tribes = []
    for i in range(n_t):
        tribes.append(read_ints(in_f))
    # d, n, w, e, s, delta_d, delta_p, delta_s

    # cache = {}
    res = solve(n_t, tribes)
    out_ln =  'Case #%d: %s' % (i_t+1, res)
    print >> out_f, out_ln
    print out_ln



