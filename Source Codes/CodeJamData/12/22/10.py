import sys
from collections import deque
from heapq import *

casenum = 1
def doit():
    global casenum
    ans = -1

    H, N, M = map(int, lines.popleft().split(' '))

    C = []
    F = []
    T = []
    P = []

    for i in range(N):
        C.append(map(int, lines.popleft().split(' ')))
        T.append([float('inf')] * M)
        P.append([None] * M)

    for i in range(N):
        F.append(map(int, lines.popleft().split(' ')))

    T[0][0] = 0

    # Dijkstra's to find earliest time each cell can be reached
    #
    # REMEMBER: Smallest element is first

    # (value, (row, col))

    done = set([])
    discovered = []

    heappush(discovered, (0, (0, 0), None))

    def oob(r, c):
        return r < 0 or r >= N or c < 0 or c >= M

    def earliest_pass(src_row, src_col, dest_row, dest_col):
        src_ceil = C[src_row][src_col]
        src_floor = F[src_row][src_col]

        dest_ceil = C[dest_row][dest_col]
        dest_floor = F[dest_row][dest_col]

        # Not enough room in dest room
        if dest_ceil - dest_floor < 50:
            return -1

        # Not enough room to cross
        if dest_ceil - src_floor < 50 or src_ceil - dest_floor < 50:
            return -1

        # Can cross immediately
        if dest_ceil - H > 50:
            return 0
        else:
            # when will the water level be low enough?
            return (50 - dest_ceil + H)/10.0

    while discovered:
        best = heappop(discovered)

        (best_time, (best_row, best_col), parent) = best

        if (best_row, best_col) in done:
            continue

        done.add( (best_row, best_col) )

        T[best_row][best_col] = best_time
        P[best_row][best_col] = parent

        def add(dr, dc):
            row = best_row + dr
            col = best_col + dc

            if oob(row, col):
                return

            next_t = earliest_pass(best_row, best_col, row, col)

            if next_t == -1:
                # Can't enter from here
                return

            next_t = max(best_time, next_t)

            if next_t > 0:
                # We had to wait for water to fall

                src_floor = F[best_row][best_col]

                if ((H - 10 * next_t) - src_floor) < 20:
                    # Need to drag kayak
                    next_t += 10
                else:
                    next_t += 1

            heappush(discovered, (next_t, (row, col), (best_row, best_col)))

        add(-1, 0)
        add(+1, 0)
        add(0, -1)
        add(0, +1)

    # DEBUG
    """
    print N, 'rows'
    print M, 'cols'
    print 'water', H
    for i in range(N):
        for j in range(M):
            print "%25s" % (str((T[i][j], F[i][j], C[i][j], P[i][j]))),
        print '\n',
    """

    print 'Case #%d: %.5f' % (casenum, T[N-1][M-1])
    casenum += 1

lines = deque([x.strip() for x in sys.stdin.readlines()])
ZZZ = int(lines.popleft())
for case in range(ZZZ):
    doit()
