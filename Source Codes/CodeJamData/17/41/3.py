"""
Google Code Jam 2017
Round 2
Problem A

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

def initialize_solver():
    pass

def solve_testcase():
    n,p = read()
    a = read()
    counts = [0]*p
    for i in a: counts[i%p] += 1

    res = counts[0]
    if p == 2:
        res += (counts[1]+1)//2
    if p == 3:
        packs = min(counts[1], counts[2])
        counts[1] -= packs
        counts[2] -= packs
        res += packs
        res += (counts[1]+2)//3 + (counts[2]+2)//3
    if p == 4:
        p1 = min(counts[1], counts[3])
        counts[1] -= p1
        counts[3] -= p1
        res += p1 + counts[2]//2
        counts[2] %= 2
        if counts[2] == 1 and counts[1] >= 2:
            res += 1
            counts[2] = 0
            counts[1] -= 2
        elif counts[2] == 1 and counts[3] >= 2:
            res += 1
            counts[2] = 0
            counts[3] -= 2
        if counts[2] == 1 and (counts[1] + counts[3] > 0): counts[2] = 0
        res += (counts[1]+3)//4 + (counts[2]+1)//2 + (counts[3]+3)//4
    return res

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
        write(solve_testcase())
        write()
if tfile is not None: tfile.close()
