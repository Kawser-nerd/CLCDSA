"""
Google Code Jam 2016 Round 3 Problem B

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

import random, time

def initialize_solver():
    pass

def simulate(children, size, label):
    stack = [0]
    st = []
    left = len(children)
    while stack:
        n = random.randrange(left)
        left -= 1
        c = 0
        for i in range(len(stack)):
            c += size[stack[i]]
            if c > n: break
        chosen = stack[i]
        st.append(label[chosen])
        stack.remove(chosen)
        stack.extend(children[chosen])
    return "".join(st)

def solve_testcase():
    limit = 2000
    n = read(False)
    parent = [-1] + read()
    label = "_" + read(False, str)
    m = read(False)
    cool = read(rettype=str)
    ct = [0] * m

    children = [set() for _ in range(n+1)]
    ctemp = [set() for _ in range(n+1)]
    for i in range(1, n+1):
        children[parent[i]].add(i)
        ctemp[parent[i]].add(i)
    size = [1] * (n+1)
    done = 0
    while done < n:
        for i in range(n+1):
            if ctemp[i] == set():
                size[parent[i]] += size[i]
                ctemp[parent[i]].remove(i)
                ctemp[i] = 0
                done += 1

    start = time.clock()
    simul = 0
    while time.clock() < start + 1.5:
        res = simulate(children, size, label)
        for j in range(m):
            if cool[j] in res: ct[j] += 1
        simul += 1
    return [ct[i] / simul for i in range(m)]

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
        print("Case {} start".format(case_number))
        write(output_format.replace("%d", str(case_number)))
        write(solve_testcase())
        write("\n")
if tfile is not None: tfile.close()
