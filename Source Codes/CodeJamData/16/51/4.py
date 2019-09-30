"""
Google Code Jam 2016 Round 3 Problem A

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def initialize_solver():
    pass

def solve_testcase():
    s = read(False, str)
    c1 = 0
    c2 = 0
    j1 = 0
    j2 = 0
    for i in range(len(s)):
        if i % 2 == 0:
            if s[i] == "C":
                c1 += 1
            else:
                j1 += 1
        else:
            if s[i] == "C":
                c2 += 1
            else:
                j2 += 1
    return 10*(min([c1, c2]) + min([j1, j2])) + 5*abs(c1-c2)

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
