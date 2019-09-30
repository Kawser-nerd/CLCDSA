from collections import defaultdict
################################################################
def solve():
    N = int(input.readline())
    M = [[int(x)-1 for x in input.readline().split(' ')][1:] # make 0-based
         for i in range(N)]
    E = [{} for i in range(N)] # Edges
    R = [{} for i in range(N)] # Reverse edges
    for i in range(N):
        for j in M[i]:
            E[i][j] = True
            R[j][i] = True
    L = list()
    S = [j for j in range(N) if len(R[j]) == 0]
    while (len(S) > 0):
        i = S.pop()
        L.append(i)
        for j in E[i]:
            del R[j][i]
            if len(R[j]) == 0:
                S.append(j)
    paths = [[0 for i in range(N)] for i in range(N)]

    R = [[] for i in range(N)] # Edges
    for i in range(N):
        for j in M[i]:
            R[j].append(i)

    for j in L:
        for i in range(N):
            x = i in R[j] and 1 or 0
            paths[i][j] = x + sum([paths[i][k] for k in R[j]])
            if paths[i][j] > 1:
                return "Yes"
    return "No"

# while S is non-empty do
#     remove a node n from S
#     insert n into L
#     for each node m with an edge e from n to m do
#         remove edge e from the graph
#         if m has no other incoming edges then
#             insert m into S
# if graph has edges then
#     return error (graph has at least one cycle)
# else 
#     return L (a topologically sorted order)            

    return M, R, S
################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start 

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
