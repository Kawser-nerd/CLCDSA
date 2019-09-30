"""
Google Code Jam 2015 Round 3 Problem D

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

def initialize():
    pass

def solve():
    # only for small
    p, = read()
    e = read()
    f = read()
    els = {e[i]: f[i] for i in range(p)}
    s = []
    while len(els) > 1 or els[0] > 1:
        if els[0] > 1:
            s.append(0)
            for i in els: els[i] //= 2
        else:
            s.append(min(list(sorted(els.keys()))[1:]))
            els_new = dict()
            while els:
                i = min(els.keys())
                els_new[i] = els[i]
                del els[i]
                els[i+s[-1]] -= els_new[i]
                if els[i+s[-1]] == 0: del els[i+s[-1]]
            els = els_new
    s.sort()
    write(s)

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
