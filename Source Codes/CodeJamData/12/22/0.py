import sys
import heapq


def valid(x, y, n, m):
    return x >= 0 and y >= 0 and x < n and y < m

def calc_t(c0, f0, c1, f1, h, t):
    if c1 - f1 < 50:
        return None
    if c1 - f0 < 50:
        return None
    if c0 - f1 < 50:
        return None

    h2 = h - t*10

    waiting_time = max(0.0, (h2 + 50 - c1) / 10.0)
    #print c1, h2
    #print waiting_time

    h3 = h2 - waiting_time * 10
    drag_time = 1.0 if h3-f0 >= 20.0 else 10.0
    if t == 0 and waiting_time == 0.0:
        drag_time = 0.0
    return t+waiting_time+drag_time


def foo(ifile):
    h, n, m = [int(x) for x in ifile.readline().split()]
    ceils = [[int(x) for x in ifile.readline().split()] for i in range(n)]
    floors = [[int(x) for x in ifile.readline().split()] for i in range(n)]
    res = [[None] * m for i in range(n)]
    res[0][0] = 0.0
    queue = []
    heapq.heappush(queue, (0.0, 0, 0))
    while len(queue) != 0:
        time, x, y = heapq.heappop(queue)
        if time > res[x][y]:
            continue
        for x1, y1 in [[x-1, y], [x+1, y], [x, y-1], [x, y+1]]:
            if not valid(x1, y1, n, m):
                continue
            t2 = calc_t(ceils[x][y], floors[x][y],
                        ceils[x1][y1], floors[x1][y1],
                        h, time)
            if t2 is None:
                continue
            #print x, y, x1, y1, t2

            if res[x1][y1] is None or res[x1][y1] > t2:
                res[x1][y1] = t2
                if x1 != n-1 or y1 != m-1:
                    heapq.heappush(queue, (t2, x1, y1))
    return res[-1][-1]

def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

