import psyco
psyco.full()

#def get_state(S, W, T, x, y, t):
#    s, w, t0 = S[y][x], W[y][x], T[y][x]

#    st = (t - t0) % (s + w)
#    return 1 if st < s else 2

def get_next_state_time(S, W, T, x, y, t, dest_st):
    s, w, t0 = S[y][x], W[y][x], T[y][x]

    st = (t - t0) % (s + w)
    if st < s:
        if dest_st == 1:
            return 0
        else:
            return s - st
    if st >= s:
        if dest_st == 2:
            return 0
        else:
            return s + w - st

def get_neighbors(S, W, T, X, Y, x, y, p, t):
#    st = get_state(S, W, T, x, y, t)
    if p == 0:
        no_cross = [(x - 1, y, 3, t + 2),
                    (x, y + 1, 1, t + 2)]
        cross = [(x, y, 3, t + 1 + get_next_state_time(S, W, T, x, y, t, 2)),
                 (x, y, 1, t + 1 + get_next_state_time(S, W, T, x, y, t, 1))]
    elif p == 1:
        no_cross = [(x - 1, y, 2, t + 2),
                    (x, y - 1, 0, t + 2)]
        cross = [(x, y, 2, t + 1 + get_next_state_time(S, W, T, x, y, t, 2)),
                 (x, y, 0, t + 1 + get_next_state_time(S, W, T, x, y, t, 1))]
    elif p == 2:
        no_cross = [(x + 1, y, 1, t + 2),
                    (x, y - 1, 3, t + 2)]
        cross = [(x, y, 1, t + 1 + get_next_state_time(S, W, T, x, y, t, 2)),
                 (x, y, 3, t + 1 + get_next_state_time(S, W, T, x, y, t, 1))]
    elif p == 3:
        no_cross = [(x + 1, y, 0, t + 2),
                    (x, y + 1, 2, t + 2)]
        cross = [(x, y, 0, t + 1 + get_next_state_time(S, W, T, x, y, t, 2)),
                 (x, y, 2, t + 1 + get_next_state_time(S, W, T, x, y, t, 1))]

    nbs = no_cross + cross
    ret = []
    for nx, ny, np, nt in nbs:
        if nx >= 0 and nx < X and ny >= 0 and ny < Y:
            ret += [(nx, ny, np, nt)]

    return ret

def solve():
    for case in xrange(input()):
        Y, X = [int(s) for s in raw_input().split()]

        # 3 - 0
        # |   |
        # 2 - 1

        best = [[[None for p in xrange(4)] for x in xrange(X)] for y in xrange(Y)]
        S, W, T = [], [], []
        for y in xrange(Y):
            line = [int(s) for s in raw_input().split()]
            S += [line[::3]]
            W += [line[1::3]]
            T += [line[2::3]]

        sx, sy, sp = 0, Y - 1, 0
        dx, dy, dp = X - 1, 0, 2
        start = (sx, sy, sp)
        best[sy][sx][sp] = 0
        q = [start]
        while q:
            ux, uy, up = q[0]
#            if ux == dx and uy == dy and up == dp:
#                break
            ut = best[uy][ux][up]
            q = q[1:]

            nbs = get_neighbors(S, W, T, X, Y, ux, uy, up, ut)
            for nx, ny, np, nt in nbs:
                if (best[ny][nx][np] is None or
                    best[ny][nx][np] > nt):
                    best[ny][nx][np] = nt
                    q += [(nx, ny, np)]

        res = best[dy][dx][dp]

        print 'Case #%d: %d' % (case+1, res)

solve() # so that psyco can do its magic
