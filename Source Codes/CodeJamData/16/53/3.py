"""
Google Code Jam 2016 Round 3 Problem C

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

import heapq

def initialize_solver():
    pass

def dis(pos, a, b):
    return sum((pos[a][i] - pos[b][i])**2 for i in range(3)) ** .5

def dijk(pos):
    e = [(10000, i) for i in range(len(pos))]
    e[0] = (0, 0)
    visited = [0] * len(pos)
    visited[0] = 1
    while True:
        d, i = min(e)
        if i == 1: return d
        visited[i] = 1
        for j in range(len(pos)):
            if visited[j]: continue
            e[j] = (min(e[j][0], max(e[i][0], dis(pos, i, j))), j)
        e[i] = (99999, j)

def dfs(pos, limit):
    visited = [0] * len(pos)
    visited[0] = 1
    stack = [0]
    while stack:
        curr = stack.pop()
        for i in range(len(pos)):
            if visited[i]: continue
            if dis(pos, curr, i) < limit:
                if i == 1: return True
                stack.append(i)
                visited[i] = 1
    return False

def solve_testcase():
    n, s = read()
    pos = [read()[:3] for _ in range(n)]
    return dijk(pos)

#################################################### HELPERS

# 0  : Single testcase, solve_testcase() only
# str: Multiple testcase, print output_format before
#                         %d replaced with case number
output_format = "Case #%d: "

filename = input().strip()
sfile = None
tfile = None
if filename != "":
    sfile = open(filename + ".in", "r")
    sfile.seek(0)
    tfile = open(filename + ".out", "w")

def read(split=True, rettype=int):
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if split:
        return list(map(rettype, input_line.split()))
    else:
        return rettype(input_line)

def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    if tfile:
        tfile.write(s)
    else:
        print(s, end="")

if output_format == 0:
    solve_testcase()
else:
    initialize_solver()
    total_cases = read(split=False)
    for case_number in range(1, total_cases+1):
        write(output_format.replace("%d", str(case_number)))
        write(solve_testcase())
        write("\n")
if tfile is not None: tfile.close()
