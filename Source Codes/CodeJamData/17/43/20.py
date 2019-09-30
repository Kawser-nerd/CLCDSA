from pprint import pprint
import pycosat
import sys

sys.setrecursionlimit(100000)

def task():
    r, c = map(int, input().split())
    tiles = [input() for i in range(r)]

    def trace(pos, dir, first=False):
        if pos[0] < 0 or pos[0] >= r or pos[1] < 0 or pos[1] >= c:
            return None
        tile = tiles[pos[0]][pos[1]]
        if tile == '#':
            return None
        if tile in ('-', '|') and not first:
            return (pos, dir[0] == 0)
        if tile == '.' or first:
            return trace((pos[0] + dir[0], pos[1] + dir[1]), dir)
        if tile == '/':
            if dir == (1, 0):
                dir = (0, -1)
            elif dir == (0, 1):
                dir = (-1, 0)
            elif dir == (-1, 0):
                dir = (0, 1)
            elif dir == (0, -1):
                dir = (1, 0)
        if tile == '\\':
            if dir == (1, 0):
                dir = (0, 1)
            elif dir == (0, 1):
                dir = (1, 0)
            elif dir == (-1, 0):
                dir = (0, -1)
            elif dir == (0, -1):
                dir = (-1, 0)
        return trace((pos[0] + dir[0], pos[1] + dir[1]), dir)

    f = []
    for i in range(r):
        for j in range(c):
            if tiles[i][j] == '.':
                res = []
                for dir in ((0,1), (0, -1), (1,0), (-1, 0)):
                    res.append(trace((i, j), dir, True))
                if (res[0] is not None and res[1] is not None) or (res[0] is None and res[1] is None):
                    if (res[2] is not None and res[3] is not None) or (res[2] is None and res[3] is None):
                        return "IMPOSSIBLE"
                f.append([x for x in res if x is not None])
            if tiles[i][j] in "-|":
                res = []
                for dir in ((0,1), (0, -1), (1,0), (-1, 0)):
                    res.append(trace((i, j), dir, True))
                for a, b in [x for x in res if x is not None]:
                    f.append([(a, not b)])
    cf = []
    for v in f:
        cv = []
        for x, tr in v:
            id = x[0] * c + x[1] + 1
            if not tr: id = -id
            cv.append(id)
        cf.append(cv)

    res = pycosat.solve(cf)
    if res == 'UNSAT':
        return "IMPOSSIBLE"

    tiles = list(map(list, tiles))
    for v in res:
        av = abs(v) - 1
        i = av // c
        j = av % c
        if tiles[i][j] in '-|':
            tiles[i][j] = '|' if v < 0 else '-'
    result = "POSSIBLE\n"
    for row in tiles:
        result += ''.join(row) + "\n"

    return result[:-1]


t = int(input())
for i in range(t):
    print("Case #{}: {}".format(i+1, task()))
