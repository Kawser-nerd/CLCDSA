"""
Google Code Jam 2017
Round 1B
Problem B

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

def initialize_solver():
    pass

def solve(r,y,b):
    res = [0]*(r+y+b)
    if (r+y+b) % 2 == 0:
        if y == r+b:
            for i in range(y):
                res[2*i] = 2
            for i in range(r):
                res[2*i+1] = 1
            for i in range(r+y+b):
                if res[i] == 0:
                    res[i] = 3
        else:
            for i in range(r):
                res[2*i] = 1
            for i in range(b):
                res[-2*i-1] = 3
            for i in range(r+y+b):
                if res[i] == 0:
                    res[i] = 2
    elif (r+y+b) % 2 == 1:
        for i in range(r):
            res[2*i+1] = 1
        for i in range(b):
            res[-2*i-1] = 3
        for i in range(r+y+b):
            if res[i] == 0:
                res[i] = 2
    return res

def solve_testcase():
    n,r,o,y,g,b,v = read()
    if y == v == b == o == 0 and r == g:
        return "RG"*r
    if r == g == b == o == 0 and y == v:
        return "YV"*y
    if r == g == y == v == 0 and b == o:
        return "BO"*b
    
    rn = r-g
    yn = y-v
    bn = b-o
    if rn < 0 or yn < 0 or bn < 0:
        return "IMPOSSIBLE"
    if rn == 0 and g > 0:
        return "IMPOSSIBLE"
    if yn == 0 and v > 0:
        return "IMPOSSIBLE"
    if bn == 0 and o > 0:
        return "IMPOSSIBLE"
    if rn+yn+bn == 1:
        return "IMPOSSIBLE"
    if rn > yn+bn or yn > bn+rn or bn > rn+yn:
        return "IMPOSSIBLE"
    res = solve(rn,yn,bn)
    rex = yex = bex = False
    final = []
    for i in res:
        if i == 1:
            final += ["R" + "GR"*g]
            g = 0
        if i == 2:
            final += ["Y" + "VY"*v]
            v = 0
        if i == 3:
            final += ["B" + "OB"*o]
            o = 0
    return "".join(final)

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
        tfile.write(value)
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
