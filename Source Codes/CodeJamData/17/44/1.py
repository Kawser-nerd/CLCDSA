import sys
import collections

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        C, R, M = map(int, f.readline().split())

        turrets = []
        soldiers = []

        themap = []
        for i in xrange(R):
            themap.append(f.readline().strip())
            assert len(themap[-1]) == C

            for j in xrange(C):
                if themap[-1][j] == 'S':
                    soldiers.append((i, j))
                if themap[-1][j] == 'T':
                    turrets.append((i, j))

        visible_from = {} # pos => list of turrets
        def scan(ti, (r, c), dr, dc):
            while True:
                if r < 0 or c < 0 or c >= C or r >= R or themap[r][c] == '#':
                    return
                visible_from.setdefault((r, c), set()).add(ti)
                r += dr
                c += dc

        for ti in xrange(len(turrets)):
            scan(ti, turrets[ti], 1, 0)
            scan(ti, turrets[ti], -1, 0)
            scan(ti, turrets[ti], 0, 1)
            scan(ti, turrets[ti], 0, -1)

        # print visible_from

        can_kill = {}
        for si in xrange(len(soldiers)):
            for talive in xrange(2 ** len(turrets)):
                q = collections.deque([(soldiers[si], 0)])
                got_to = set([soldiers[si]])
                killable = set()

                while q:
                    pos, dist = q.popleft()

                    can_move = dist < M
                    for ti in visible_from.get(pos, ()):
                        if talive & (1 << ti):
                            killable.add(ti)
                            can_move = False

                    if can_move:
                        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                            r = pos[0] + dr
                            c = pos[1] + dc
                            if r < 0 or c < 0 or r >= R or c >= C or themap[r][c] == '#' or (r, c) in got_to:
                                continue
                            got_to.add((r, c))
                            q.append(((r, c), dist + 1))
                can_kill[(si, talive)] = list(killable)
                # print si, talive, killable

        tpow = 1 << len(turrets)
        spow = 1 << len(soldiers)
        reachable = [[None] * tpow for i in xrange(spow)]
        reachable[0][tpow - 1] = "start"

        def nalive(n):
            t = 0
            while n:
                if n & 1:
                    t += 1
                n >>= 1
            return t

        best = 0, tpow - 1
        bestkill = 0
        for sused in xrange(spow):
            for talive in xrange(tpow - 1, -1, -1):
                if not reachable[sused][talive]:
                    continue

                for si in xrange(len(soldiers)):
                    if sused & (1 << si):
                        continue
                    new_sused = sused | (1 << si)
                    for killable in can_kill.get((si, talive)):
                        new_talive = talive & ~(1 << killable)
                        reachable[new_sused][new_talive] = (si, killable)

                        killed = len(turrets) - nalive(talive) + 1
                        if killed > bestkill:
                            bestkill = killed
                            best = new_sused, new_talive

        print "Case #%d: %d" % (_T + 1, bestkill)

        # print bestkill, best
        r = []
        while True:
            last = reachable[best[0]][best[1]]
            # print last
            if last == "start":
                break
            r.append(last)

            best = list(best)
            best[0] &= ~(1 << last[0])
            best[1] |= (1 << last[1])
            # print best

        r.reverse()
        for last in r:
            print last[0] + 1, last[1] + 1
