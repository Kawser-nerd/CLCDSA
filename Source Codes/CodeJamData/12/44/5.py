
BACKWARD = [(-1, 0), (1, 0), (0, -1)]
FORWARD = [(-1, 0), (1, 0), (0, 1)]
def around(x, y, moves=[(-1, 0), (1, 0), (0, -1), (0, 1)]):
    for (px, py) in moves:
        if 0 <= x + px < W and 0 <= y + py < H:
            yield (x + px, y + py)

def reachable(p):
    frontier = [p]
    points = set(frontier)
    while frontier:
        (x, y) = frontier[0]
        del frontier[0]
        for (px, py) in around(x, y, BACKWARD):
            if cavemap[py][px] != '#':
                if (px, py) not in points:
                    frontier.append((px, py))
                    points.add((px, py))
    return points


def gomove(move, points, allowed):
    res = set()
    (dx, dy) = move
    for (x, y) in points:
        if cavemap[y+dy][x+dx] != '#':
            res.add((x+dx, y+dy))
            if (x+dx, y+dy) not in allowed:
                return None
        else:
            res.add((x, y))
    return res

def lucky(p, points):
    frontier = [points]
    visited = [points]
    while frontier:
        head = frontier[0]
        if head == {p}:
            return 'Lucky'
        del frontier[0]
        for move in FORWARD:
            r = gomove(move, head, points)
            if (not r) or [v for v in visited if r >= v]:
                continue
            frontier.append(r)
            visited.append(r)
    return 'Unlucky'

if __name__ == '__main__':
    file = open('D-small-attempt0.in', 'r')
    T = int(file.readline())
    for case in range(1, T+1):
        (H, W) = tuple(map(int, file.readline().split()))
        cavemap = []
        caves = {}
        for y in range(H):
            cavemap.append(file.readline().strip())
            for x in range(W):
                if cavemap[y][x].isdigit():
                    caves[int(cavemap[y][x])] = (x, y)
        # print '\n'.join(cavemap)
        # print caves
        # for c in caves:
        #     print reachable(caves[c])
        #     print lucky(caves[c], reachable(caves[c]))
        print 'Case #{}:'.format(case)
        for c in caves:
            r = reachable(caves[c])
            l = lucky(caves[c], r)
            print '{}: {} {}'.format(c, len(r), l) 
