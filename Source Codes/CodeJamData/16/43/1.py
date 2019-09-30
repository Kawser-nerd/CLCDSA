"""
Google Code Jam 2016 Round 2 Problem C

Author  : chaotic_iak
Language: Python 3.4.3
"""

################################################### SOLUTION

def initialize():
    pass

def translate(r,c,n):
    if 1 <= n <= c:
        return (0, n)
    if c+1 <= n <= c+r:
        return (n-c, c+1)
    if r+c+1 <= n <= r+c+c:
        return (r+1, r+c+c+1-n)
    return (2*r+2*c+1-n, 0)

def draw_path(r0, c0, G):
    E = 0
    N = 1
    W = 2
    S = 3
    r = len(G)
    c = len(G[0])

    if r0 == 0:
        di = S
    elif c0 == c+1:
        di = W
    elif r0 == r+1:
        di = N
    elif c0 == 0:
        di = E

    while True:
        if di == N:
            r0 -= 1
        elif di == W:
            c0 -= 1
        elif di == S:
            r0 += 1
        elif di == E:
            c0 += 1
        if r0 == 0 or r0 == r+1 or c0 == 0 or c0 == c+1:
            return (r0, c0)
        if G[r0-1][c0-1] == "/":
            if di == N:
                di = E
            elif di == E:
                di = N
            elif di == W:
                di = S
            elif di == S:
                di = W
        elif G[r0-1][c0-1] == "\\":
            if di == N:
                di = W
            elif di == W:
                di = N
            elif di == E:
                di = S
            elif di == S:
                di = E
        else:
            if di == N:
                di = W
                G[r0-1][c0-1] = "\\"
            elif di == W:
                di = S
                G[r0-1][c0-1] = "/"
            elif di == S:
                di = E
                G[r0-1][c0-1] = "\\"
            elif di == E:
                di = N
                G[r0-1][c0-1] = "/"

def solve():
    r,c = read()
    G = [["."]*c for _ in range(r)]
    temp = read()
    pairs = [(temp[2*i], temp[2*i+1]) for i in range(len(temp)//2)]
    left = [1]*(2*r+2*c+1)

    while pairs:
        for pair in pairs:
            x,y = pair
            if x > y: x,y = y,x
            if sum(left[x+1:y]): continue
            r0, c0 = translate(r,c,x)
            r1, c1 = draw_path(r0, c0, G)
            if (r1, c1) != translate(r,c,y):
                write("IMPOSSIBLE")
                return
            left[x] = 0
            left[y] = 0
            pairs.remove(pair)
            break
        else:
            write("IMPOSSIBLE")
            return
    
    for i in range(r):
        for j in range(c):
            if G[i][j] == ".": G[i][j] = "/"

    write("\n".join("".join(G[i]) for i in range(r)))

#################################################### HELPERS

# 0  : Single testcase, solve() only
# str: Multiple testcase, print output_format before
#                         %d replaced with case number
output_format = "Case #%d:\n"

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
        write(solve())
        write("\n")
if tfile is not None: tfile.close()
