"""
Google Code Jam 2016 Round 2 Problem B

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

import itertools

def initialize():
    pass

def compute(chosen):
    k = len(chosen) // 2
    dp = [[0]*(2*k+1) for _ in range(2*k+2)]
    dp[0][0] = 1
    for done in range(1,2*k+1):
        for yes in range(2*k+1):
            dp[done][yes] = dp[done-1][yes-1] * chosen[done-1] + dp[done-1][yes] * (1 - chosen[done-1])
    return dp[2*k][k]

def solve():
    n,k = read()
    p = read(3)
    p.sort()
    return max([compute(p[:i] + p[-k+i:]) for i in range(k)] + [compute(p[:k])])

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
    # 3: List of floats
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if mode == 0: return input_line
    if mode == 1: return input_line.split()
    if mode == 2: return list(map(int, input_line.split()))
    if mode == 3: return list(map(float, input_line.split()))

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
        write(solve())
        write("\n")
if tfile is not None: tfile.close()
