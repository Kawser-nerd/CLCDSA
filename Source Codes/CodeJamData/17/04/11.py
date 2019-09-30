import sys
import networkx as nx
from networkx.algorithms import bipartite

fileName = "D-large"
sys.stdin = open(fileName+".in", 'r')
output = open(fileName+".out", 'w')
T = int(input())
for case in range(1,T+1):

    ###################### input data ###############################

    N,M = input().split(" ")
    print("N="+N+", M="+M)
    N,M = int(N),int(M)
    rook = set()
    bishop = set()
    for _ in range(M):
        t,i,j = input().split(" ")
        if t=="x" or t=="o":
            rook.add((int(i),int(j)))
        if t=="+" or t=="o":
            bishop.add((int(i),int(j)))
    nr = len(rook)
    nb = len(bishop)

    ###################### compute new rooks ###############################

    filledRows = set()
    filledCols = set()
    for r in rook:
        filledCols.add(r[1])
        filledRows.add(r[0])
    emptyRow = list(set([i for i in range(1,N+1)]) - filledRows)
    emptyCol = list(set([i for i in range(1,N+1)]) - filledCols)
    newRook = set([(emptyRow[i],emptyCol[i]) for i in range(len(emptyRow))])
    allRook = rook|newRook

    ###################### compute new bishops ###############################

    G = nx.Graph()
    G.add_nodes_from(range(2,2*N+1))
    G.add_nodes_from(range(4*N-N+1,4*N-1+N))
    for i in range(1,N+1):
        for j in range(1,N+1):
            G.add_edge(i+j,4*N-i+j)
    for b in bishop:
        d = b[0]+b[1]
        e = 4*N-b[0]+b[1]
        if d in G.nodes():
            G.remove_node(d)
        if e in G.nodes():
            G.remove_node(e)
    matching = nx.bipartite.maximum_matching(G)
    newBishop = set()
    for d in matching:
        if d>2*N: continue
        e = matching[d]-4*N
        j = (d+e)//2
        i = (d-e)//2
        newBishop.add((i,j))
    allBishop = bishop|newBishop

    ######################### compute answer ##################################

    newModels = []
    for i in range(1,N+1):
        for j in range(1,N+1):
            m = (i,j)
            if (m in newRook) or (m in newBishop):
                if m in allRook:
                    if m in allBishop:
                        newModels.append(["o",str(i),str(j)])
                    else:
                        newModels.append(["x",str(i),str(j)])
                else:
                    newModels.append(["+",str(i),str(j)])
    totalScore = len(allRook)+len(allBishop)

    answer = str(totalScore)+" "+str(len(newModels))
    for m in newModels:
        answer += "\n"+m[0]+" "+m[1]+" "+m[2]

    ######################################################################
    print("Case #%d:" % case, answer)
    print("Case #%d:" % case, answer, file = output)
    ######################################################################
