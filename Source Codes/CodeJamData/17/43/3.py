"""
Google Code Jam 2017
Round 2
Problem C

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

import collections

def initialize_solver():
    pass

def go(grid, r, c, d):
    rows, cols = len(grid), len(grid[0])
    mirror1 = {0: 1, 1: 0, 2: 3, 3: 2}    # /
    mirror2 = {0: 3, 1: 2, 2: 1, 3: 0}    # \
    cells = []
    while True:
        if d == 0: r -= 1    # up
        if d == 1: c += 1    # right
        if d == 2: r += 1    # down
        if d == 3: c -= 1    # left
        if not ((0 <= r < rows) and (0 <= c < cols)): return (True, cells)
        g = grid[r][c]
        if g == "#": return (True, cells)
        if g == "-" or g == "|": return (False, [])
        if g == ".": cells.append((r,c))
        if g == "/": d = mirror1[d]
        if g == "\\": d = mirror2[d]

def find_nonassign(assignments):
    for i in range(len(assignments)):
        if assignments[i] == 0: return i
    return -1

def propagate_once(implications, assignments, stack):
    v = stack.pop()
    for i in implications[v]:
        if i > 0:
            if assignments[i] == -1: return False
            if assignments[i] == 0:
                assignments[i] = 1
                stack.add(i)
        if i < 0:
            if assignments[-i] == 1: return False
            if assignments[-i] == 0:
                assignments[-i] = -1
                stack.add(i)
    return True

def solve_2sat(var, clauses):
    assignments0, assignments1 = [0]*(var+1), [0]*(var+1)
    stack0, stack1 = set(), set()    # assignments not yet propagated
    true0, true1 = True, False
    implications = collections.defaultdict(set)
    for c in clauses:
        c = list(c)
        if len(c) == 0: return False
        if len(c) == 1:
            if c[0] > 0:
                if assignments0[c[0]] == -1: return False
                assignments0[c[0]] = 1
            if c[0] < 0:
                if assignments0[-c[0]] == 1: return False
                assignments0[-c[0]] = -1
            stack0.add(c[0])
        else:
            if c[0] == -c[1]: continue
            implications[-c[0]].add(c[1])
            implications[-c[1]].add(c[0])
    assignments0[0] = 1
    
    while True:
        #print(assignments0, stack0, true0, "\n", assignments1, stack1, true1, "\n\n")
        if true0 and stack0: true0 = propagate_once(implications, assignments0, stack0)
        if true1 and stack1: true1 = propagate_once(implications, assignments1, stack1)
        #print(assignments0, stack0, true0, "\n", assignments1, stack1, true1, "\n\n")
        if not true0 and not true1: return False
        if true1 and not stack1:
            assignments0 = assignments1
            stack0 = stack1
            true0 = true1
        if true0 and not stack0:
            i = find_nonassign(assignments0)
            if i == -1: return assignments0
            assignments1 = assignments0[:]
            assignments0[i] = 1
            stack0 = {i}
            assignments1[i] = -1
            stack1 = {-i}
            true1 = True

def solve_testcase():
    rows, cols = read()
    grid = [read(callback=str, split=False) for _ in range(rows)]
    clauses = collections.defaultdict(set)
    realclauses = []

    t = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "-" or grid[r][c] == "|":
                valid_orient = set()
                t += 1
                res = [go(grid, r, c, d) for d in range(4)]
                if res[0][0] and res[2][0]:
                    valid_orient.add(t)
                    for cell in res[0][1] + res[2][1]:
                        clauses[cell].add(t)                # positive = vertical
                if res[1][0] and res[3][0]:
                    valid_orient.add(-t)
                    for cell in res[1][1] + res[3][1]:
                        clauses[cell].add(-t)               # negative = horizontal
                realclauses.append(valid_orient)

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == ".": realclauses.append(clauses[r,c])
    assignments = solve_2sat(t, realclauses)
    if not assignments:
        write("IMPOSSIBLE")
    else:
        write("POSSIBLE\n")
        t = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] != "-" and grid[r][c] != "|":
                    write(grid[r][c])
                else:
                    t += 1
                    if assignments[t] == 1:
                        write("|")
                    else:
                        write("-")
            if r != rows-1: write("\n")

#################################################### HELPERS

def read(callback=int, split=True):
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if split:
        return list(map(callback, input_line.split()))
    else:
        return callback(input_line)

def write(value="\n"):
    if value is None: return
    try:
        if not isinstance(value, str):
            value = " ".join(map(str, value))
    except:
        pass
    if tfile:
        tfile.write(str(value))
    else:
        print(value, end="")

# None: Single testcase, solve_testcase() only
# str : Multiple testcase, print output_format before
#                          %d replaced with case number
output_format = "Case #%d: "

filename = input().strip()
sfile = None
tfile = None
if filename != "":
    sfile = open(filename + ".in", "r")
    sfile.seek(0)
    tfile = open(filename + ".out", "w")

if output_format == None:
    solve_testcase()
else:
    initialize_solver()
    total_cases, = read()
    for case_number in range(1, total_cases+1):
        write(output_format.replace("%d", str(case_number)))
        solve_testcase()
        write()
if tfile is not None: tfile.close()
