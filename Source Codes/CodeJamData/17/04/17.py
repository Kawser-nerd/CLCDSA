import sys
import networkx as nx

#sys.stdin=open('datad.txt')

# Main insight is that rows and diagonals are independent problems.
# Placing a + and a - in the same location is equivalent to a o
# Then trying to find best way of matching rows/diagonals
# Row matching is actually trivial, but for simplicity use same algorithm

def find_connections(t,r,c,method):
    """Return start node, dest node, occupied.
    Using diagonals if method is true, else rows/columns"""
    if method:
        occupied = t=='o' or t=='+'
        return r+c,1000+r-c,occupied
    else:
        occupied = t=='o' or t=='x' # Note that + do not affect rows
        return r,1000+c,occupied

def find_flow(N,A,method):
    """Return flow dictionary for list of type,row,col starting locations"""
    G = nx.DiGraph()
    used=set()
    for t,r,c in A:
        s,e,occupied = find_connections(t,r,c,method)
        if occupied:
            assert s not in used
            assert e not in used
            used.add(s)
            used.add(e)
            G.add_edge('source',s,capacity=1)
            G.add_edge(e,'sink',capacity=1)
            G.add_edge(s,e,capacity=1)
    starts=set()
    ends=set()
    for r in range(1,N+1):
        for c in range(1,N+1):
            s,e,_=find_connections('o',r,c,method)
            starts.add(s)
            ends.add(e)
            if s in used or e in used:
                continue
            G.add_edge(s,e,capacity=1)
    for s in starts:
        if s in used:
            continue
        G.add_edge('source',s,capacity=1)
    for e in ends:
        if e in used:
            continue
        G.add_edge(e,'sink',capacity=1)
    value,flow_dict = nx.maximum_flow(G,'source','sink')
    return value,flow_dict

def has_flow(r,c,flow_dict,method):
    """Returns true if r is connected to c"""
    s,e,_=find_connections('o',r,c,method)
    if s in flow_dict:
        if e in flow_dict[s]:
            return flow_dict[s][e]>0.5
    return False
    
T=input()
for testcase in range(1,T+1):
    N,M = map(int,raw_input().split())
    A=[]
    D={} # Original contents
    for i in range(M):
        t,r,c = raw_input().split()
        r=int(r)
        c=int(c)
        A.append([t,r,c])
        D[r,c]=t
    VR,FR = find_flow(N,A,0)
    VD,FD = find_flow(N,A,1)
    score = 0
    B = []
    for r in range(1,N+1):
        for c in range(1,N+1):
            hasr = has_flow(r,c,FR,0) # connecting row resources by placing x/o's
            hasd = has_flow(r,c,FD,1)
            if hasr:
                score+=1
            if hasd:
                score+=1
            if hasr:
                newt = 'o' if hasd else 'x'
            else:
                newt = '+' if hasd else ' '
            key=r,c
            if key in D:
                oldt = D[key]
            else:
                oldt = ' '
            if oldt==newt:
                continue
            B.append([newt,r,c])  
        
    print "Case #{}: {} {}".format(testcase,score,len(B))
    for t,r,c in B:
        print"{} {} {}".format(t,r,c)

        
