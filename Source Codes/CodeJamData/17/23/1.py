"""
Google Code Jam 2017
Round 1B
Problem C

Author  : chaotic_iak
Language: Python 3.5.2
"""

################################################### SOLUTION

def initialize_solver():
    pass

def dijkstra(G, s):
    n = len(G)
    dist = [10**17] * n
    dist[s] = 0
    locked = [False] * n

    while not all(locked):
        curr = -1
        mindist = 10**18
        for i in range(n):
            if not locked[i]:
                if dist[i] < mindist:
                    curr = i
                    mindist = dist[i]
        locked[curr] = True
        for i in range(n):
            if G[curr][i] != -1:
                dist[i] = min(dist[i], dist[curr] + G[curr][i])

    return dist

def solve_testcase():
    n,q = read()
    e,s = [],[]
    for i in range(n):
        t1, t2 = read()
        e.append(t1)
        s.append(t2)
    G = [read() for _ in range(n)]
    newG = []
    for i in range(n):
        dist = dijkstra(G, i)
        for j in range(n):
            if j == i:
                dist[j] = -1
            else:
                if dist[j] > e[i]:
                    dist[j] = -1
                else:
                    dist[j] /= s[i]
        newG.append(dist)

    results = []
    for i in range(q):
        fro, to = read()
        results.append(dijkstra(newG, fro-1)[to-1])
    return results

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
