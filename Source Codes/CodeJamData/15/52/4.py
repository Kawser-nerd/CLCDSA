"""
Google Code Jam 2015 Round 3 Problem B

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

def initialize():
    pass

def solve():
    n,k = read()
    s = read()
    mins = [0]*k
    maxs = [0]*k
    for i in range(k):
        diff = 0
        j = i
        while j < n-k:
            diff += s[j+1] - s[j]
            if diff < -mins[i]: mins[i] = -diff
            if diff > maxs[i]: maxs[i] = diff
            j += k
    sm = (s[0] - sum(mins)) % k
    for i in range(k): maxs[i] = maxs[i] + mins[i]
    mx = max(maxs)
    avail = sum(mx-i for i in maxs)
    if sm > avail:
        write(mx+1)
    else:
        write(mx)

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
