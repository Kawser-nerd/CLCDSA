"""
Google Code Jam 2017
Round 2
Problem B

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

def initialize_solver():
    pass

def solve_testcase():
    n,c,m = read()
    a = [tuple(read()) for _ in range(m)] + [(n+1, c+1)]
    a.sort(key=lambda x: x[1])
    r = 0
    ct = 0
    lastpass = 0
    for p,b in a:
        if b != lastpass:
            r = max(r, ct)
            ct = 1
            lastpass = b
        else:
            ct += 1
    a.sort(key=lambda x: x[0])
    ct = 0
    for p,b in a:
        ct += 1
        while r*p < ct: r += 1
    s = 0
    ct = 0
    lastp = 0
    for p,b in a:
        if p != lastp:
            s += max(0, ct-r)
            ct = 1
            lastp = p
        else:
            ct += 1
    return (r, s)

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
