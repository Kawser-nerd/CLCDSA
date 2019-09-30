"""
Google Code Jam 2015 Round 2 Problem B

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

def initialize():
    pass

def solve():
    n,v,x = read()
    n = int(n)
    vol = int(v*10000+0.5)
    tgt = int(x*10000+0.5)
    tgt *= vol
    rate = []
    temp = []
    for i in range(n):
        r,c = read()
        rate.append(int(r*10000+0.5))
        temp.append(int(c*10000+0.5))
    if n == 1:
        if temp[0]*vol == tgt:
            write(vol/rate[0])
            return
        else:
            write("IMPOSSIBLE")
            return
    if n == 2:
        if temp[0] == temp[1]:
            if temp[0]*vol == tgt:
                write(vol/(rate[0]+rate[1]))
                return
            else:
                write("IMPOSSIBLE")
                return
        matrix = [[rate[0], rate[1]],
                  [temp[0]*rate[0], temp[1]*rate[1]]]
        det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]
        inverse = [[matrix[1][1], -matrix[0][1]],
                   [-matrix[1][0], matrix[0][0]]]
        result = [vol, tgt]
        ans = [0,0]
        ans[0] = inverse[0][0]*result[0] + inverse[0][1]*result[1]
        ans[1] = inverse[1][0]*result[0] + inverse[1][1]*result[1]
        ans[0] = ans[0]/det
        ans[1] = ans[1]/det
        if ans[0] < 0 or ans[1] < 0:
            write("IMPOSSIBLE")
        else:
            write(max(ans[0], ans[1]))

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
    # 2: List of floats
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if mode == 0: return input_line
    if mode == 1: return input_line.split()
    if mode == 2: return list(map(float, input_line.split()))

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
