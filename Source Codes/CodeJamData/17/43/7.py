import pycosat
import sys

sys.setrecursionlimit(1000000)

num_testcases = int(input())

move = {
    "l": (0, -1),
    "r": (0, +1),
    "u": (-1, 0),
    "d": (+1, 0)
}

mirrors = {
    "/": {
        "l": "d",
        "r": "u",
        "u": "r",
        "d": "l"
    },
    "\\": {
        "l": "u",
        "r": "d",
        "u": "l",
        "d": "r"
    }
}

axis = {
    "l": "h",
    "r": "h",
    "u": "v",
    "d": "v"
}

other_axis = {
    "h": "v",
    "v": "h"
}


class Impossible(Exception):
    pass


def explore(r, c, m, i, j, d, s, n):
    # out of the box
    if not (0 <= i < r) or not (0 <= j < c):
        return [], [], False
    # hit a wall
    if m[i][j] == "#":
        return [], [], False
    # looped
    if s == (i, j, axis[d]) and n > 0:
        return [], [], True
    #print("at %d %d (%s)" % (i, j, d))
    if m[i][j] in {"/", "\\"}:
        next_d = mirrors[m[i][j]][d]
    else:
        next_d = d
    next_i = i + move[next_d][0]
    next_j = j + move[next_d][1]
    #print("nx %d %d (%s)" % (next_i, next_j, next_d))
    lasers, cells, looped = explore(r, c, m, next_i, next_j, next_d, s, n + 1)
    if m[i][j] in {"|", "-"}:
        lasers.append((i, j, axis[d]))
    if m[i][j] == ".":
        cells.append((i, j, axis[d]))
    return lasers, cells, looped


def assign(p, n, v):
    if n in p and p[n] != v:
        raise Impossible("conflicting assignments")
    else:
        p[n] = v


def get_var_name(s, r, n):
    if n in s:
        return s[n]
    s[n] = len(s) + 1
    r[s[n]] = n
    return s[n]


for testcase_num in range(1, num_testcases + 1):
    r, c = tuple(int(x) for x in input().split())
    
    matrix = tuple(tuple(input().strip()) for _ in range(r))
    
    lasers = dict()
    cells = dict()
    cycles = list()
    
    for i in range(r):
        for j in range(c):
            if matrix[i][j] in {"|", "-", "."}:
                if "h" not in (cells if matrix[i][j] == "." else lasers).get((i, j), {}):
                    lasers1, cells1, looped1 = explore(r, c, matrix, i, j, "l", (i, j, "h"), 0)
                    lasers2, cells2, looped2 = explore(r, c, matrix, i, j, "r", (i, j, "h"), 0)
                    assert looped1 == looped2
                    cycle = (frozenset(lasers1 + lasers2), frozenset(cells1 + cells2), looped1)
                    for laser in cycle[0]:
                        lasers.setdefault((laser[0], laser[1]), {})[laser[2]] = cycle
                    for cell in cycle[1]:
                        cells.setdefault((cell[0], cell[1]), {})[cell[2]] = cycle
                    cycles.append(cycle)
                if "v" not in (cells if matrix[i][j] == "." else lasers).get((i, j), {}):
                    lasers1, cells1, looped1 = explore(r, c, matrix, i, j, "u", (i, j, "v"), 0)
                    lasers2, cells2, looped2 = explore(r, c, matrix, i, j, "d", (i, j, "v"), 0)
                    assert looped1 == looped2
                    cycle = (frozenset(lasers1 + lasers2), frozenset(cells1 + cells2), looped1)
                    for laser in cycle[0]:
                        lasers.setdefault((laser[0], laser[1]), {})[laser[2]] = cycle
                    for cell in cycle[1]:
                        cells.setdefault((cell[0], cell[1]), {})[cell[2]] = cycle
                    cycles.append(cycle)
    
    try:
        if any(sum(len(v[0]) for v in c.values()) == 0 for c in cells.values()):
            raise Impossible()
        ass = dict()
        for c in cycles:
            if len(c[0]) > 1:
                for lx, ly, ld in c[0]:
                    assign(ass, (lx, ly), other_axis[ld])
            if len(c[0]) == 1 and c[2]:
                for lx, ly, ld in c[0]:
                    assign(ass, (lx, ly), other_axis[ld])
        for c in cycles:
            for lx, ly, ld in c[0]:
                if ass.get((lx, ly), None) == ld:
                    if len(c[0]) > 1 or c[2]:
                        raise Impossible("forced assignment kills laser")
        conds = list()
        for c in cells.values():
            if len(c["h"][0]) == 0:
                l = next(iter(c["v"][0]))
                conds.append((l,))
            elif len(c["v"][0]) == 0:
                l = next(iter(c["h"][0]))
                conds.append((l,))
            else:
                conds.append((next(iter(c["v"][0])), next(iter(c["h"][0]))))
        var_names = dict()
        rev_var_names = dict()
        conds2 = list()
        for c in conds:
            c2 = list()
            for l in c:
                if l[:2] not in ass:
                    #print("%d,%d %s" % l)
                    c2.append(get_var_name(var_names, rev_var_names, l[:2]) * (1 if l[2] == "h" else -1))
                elif ass[l[:2]] == l[2]:
                    break
            else:
                conds2.append(c2)
        sol = pycosat.solve(conds2)
        if sol == "UNSAT":
            raise Impossible("unsat")
    except Impossible as e:
        print("Case #%d: %s" % (testcase_num, "IMPOSSIBLE"))
    else:
        print("Case #%d: %s" % (testcase_num, "POSSIBLE"))
        for v in sol:
            l = rev_var_names[abs(v)]
            ass[l] = "h" if v > 0 else "v"
        for i in range(r):
            print("".join(matrix[i][j] if matrix[i][j] not in {"|", "-"} else (("-" if ass[i,j] == "h" else "|") if (i,j) in ass else matrix[i][j]) for j in range(len(matrix[0]))))
