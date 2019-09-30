"""
Google Code Jam 2015 Round 2 Problem D

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

st3 = dict()
no3 = dict()
def initialize():
    for i in [1,3,4,6,12]:
        st3[i] = [0]*8
        no3[i] = [0]*8
    st3[1][-1] = 1
    no3[1][-1] = 1

    for i in range(100):
        for i in [1,3,4,6,12]:
            st3[i].append(no3[i][-2])
            no3[i].append(0)

        no3[1][-1] = st3[1][-2]
        no3[3][-1] = (st3[1][-3]+st3[3][-3])*3 + st3[3][-2]
        no3[4][-1] = (st3[1][-4]+st3[4][-4])*4 + st3[4][-2]
        no3[6][-1] = (st3[1][-3]+st3[3][-3]+st3[6][-3])*6 + (st3[6][-3])*3 + st3[6][-2]
        no3[12][-1] = (
            (st3[4][-3]+st3[12][-3])*6 +
            (st3[4][-3]+st3[12][-3])*3 +
            (st3[3][-4]+st3[6][-4]+st3[12][-4])*4 +
            st3[12][-2]
        )

def solve():
    r,c = read()
    ans = sum(((st3[i][7+r]+no3[i][7+r])//i if c%i==0 else 0) for i in [1,3,4,6,12])
    write(ans % 1000000007)

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
