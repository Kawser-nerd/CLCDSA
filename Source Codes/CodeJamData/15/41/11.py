"""
Google Code Jam 2015 Round 2 Problem A

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

def initialize():
    pass

def solve():
    r,c = read()
    ans = 0
    grid = []
    lone = []
    for i in range(r):
        grid.append(read(0))
        lone.append([0]*c)
    for i in range(r):
        fi, la, fo = "", "", -1
        for j in range(c):
            if grid[i][j] == ".": continue
            if fo != -1: fo = 999
            if fo == -1:
                fo = j
                fi = grid[i][j]
            la = grid[i][j]
        if -1 < fo < 999:
            lone[i][fo] = 1
        if fi == "<": ans += 1
        if la == ">": ans += 1
    for j in range(c):
        fi, la, fo = "", "", -1
        for i in range(r):
            if grid[i][j] == ".": continue
            if fo != -1: fo = 999
            if fo == -1:
                fo = i
                fi = grid[i][j]
            la = grid[i][j]
        if -1 < fo < 999 and lone[fo][j]:
            write("IMPOSSIBLE")
            return
        if fi == "^": ans += 1
        if la == "v": ans += 1
    write(ans)


#################################################### HELPERS

# 0  : Single testcase, solve() only
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

def read(mode=2):
    # 0: String
    # 1: List of strings
    # 2: List of integers
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if mode == 0: return input_line
    if mode == 1: return input_line.split()
    if mode == 2: return list(map(int, input_line.split()))

def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    if tfile:
        tfile.write(s)
    else:
        print(s, end="")

if output_format == 0:
    solve()
else:
    initialize()
    total_cases = int(read(0))
    for case_number in range(1, total_cases+1):
        write(output_format.replace("%d", str(case_number)))
        solve()
        write("\n")
