"""
Google Code Jam 2016 Round 2 Problem A

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def initialize():
    pass

def generate(n, ofs):
    return ["PRS"[(sum(map(int, bin(i)[2:])) + ofs) % 3] for i in range(2**n)]

def solve():
    n,r,p,s = read()
    k = 2**n // 3
    if r != k and r != k+1:
        write("IMPOSSIBLE")
        return
    if p != k and p != k+1:
        write("IMPOSSIBLE")
        return
    if s != k and s != k+1:
        write("IMPOSSIBLE")
        return

    for i in range(3):
        res = generate(n, i)
        if sum(j == "P" for j in res) != p: continue
        if sum(j == "R" for j in res) != r: continue
        break

    for level in range(n):
        for i in range(len(res) // 2):
            if res[2*i] > res[2*i+1]:
                res[2*i], res[2*i+1] = res[2*i+1], res[2*i]
        res = [res[2*i]+res[2*i+1] for i in range(len(res) // 2)]
    write(res[0])

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
if tfile is not None: tfile.close()
