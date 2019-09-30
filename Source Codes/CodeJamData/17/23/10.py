import sys
sys.setrecursionlimit(10000)

import heapq
import random

def read_line(f):
    while True:
        s=f.readline().strip()
        if s:
            return s
def read_list(f):
    return [int(x) for x in read_line(f).split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    N,Q=read_tuple(f)
    horses=[read_tuple(f) for _ in xrange(N)]
    dists=[read_list(f) for _ in xrange(N)]
    routes=[read_tuple(f) for _ in xrange(Q)]
    return horses,dists,routes


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



def get_min_dists(s, dists, md):
    N=len(dists)
    bheap=[]
    for n in xrange(N):
        if dists[s][n]>0:
            heapq.heappush(bheap,(dists[s][n],n))
    minds=[-1]*N
    minds[s]=0
    addn=1
    while bheap and addn<N:
        d,n=heapq.heappop(bheap)
        if d>md:
            break
        if minds[n]<0:
            addn+=1
            minds[n]=d
            for nn in xrange(N):
                if dists[n][nn]>0 and minds[nn]<0:
                    heapq.heappush(bheap,(d+dists[n][nn],nn))
    minds[s]=-1
    return minds

def setup_time_graph(horses, dists):
    time_graph=[]
    for i,(E,S) in enumerate(horses):
        minds=get_min_distsf(i,dists,E)
        mints=[(d/float(S) if d>0 else -1) for d in minds]
        time_graph.append(mints)
    return time_graph


def get_min_distsf(s, dists, md):
    N=len(dists)
    bheap=[]
    for n in xrange(N):
        if dists[s][n]>0:
            heapq.heappush(bheap,(dists[s][n],n))
    minds=[-1]*N
    minds[s]=0
    mindst={}
    addn=1
    while bheap and addn<N:
        d,n=heapq.heappop(bheap)
        if d>md:
            break
        if minds[n]<0:
            addn+=1
            minds[n]=d
            for nn in xrange(N):
                if dists[n][nn]>0 and minds[nn]<0:
                    if (nn not in mindst) or (mindst[nn]>d+dists[n][nn]):
                        heapq.heappush(bheap,(d+dists[n][nn],nn))
                        mindst[nn]=d+dists[n][nn]
    minds[s]=-1
    return minds

def setup_time_graphf(horses, dists):
    time_graph=[]
    for i,(E,S) in enumerate(horses):
        minds=get_min_distsf(i,dists,E)
        mints=[(d/float(S) if d>0 else -1) for d in minds]
        time_graph.append(mints)
    return time_graph

def get_min_time(s, e, time_graph):
    N=len(time_graph)
    bheap=[]
    v={s}
    for n in xrange(N):
        if time_graph[s][n]>0:
            heapq.heappush(bheap,(time_graph[s][n],n))
    while True:
        t,n=heapq.heappop(bheap)
        if n==e:
            return t
        if n not in v:
            v.add(n)
            for nn in xrange(N):
                if time_graph[n][nn]>0:
                    heapq.heappush(bheap,(t+time_graph[n][nn],nn))
    

def solve(case):
    horses,dists,routes=case
    time_graph=setup_time_graph(horses,dists)
    mints=[get_min_time(s-1,e-1,time_graph) for (s,e) in routes]
    return mints


def solvef(case):
    horses,dists,routes=case
    time_graph=setup_time_graphf(horses,dists)
    mints=[get_min_time(s-1,e-1,time_graph) for (s,e) in routes]
    return mints






def outcome_string(outcome):
    return " ".join(["{:.8f}".format(o) for o in outcome])


def save_outcomes(path, outcomes):
    with open(path,'w') as f:
        for n,o in enumerate(outcomes):
            f.write("Case #{0}: {1}\n".format( n+1 , outcome_string(o) ))
def process(path_in, path_out=None):
    if path_out==None:
        path_out=path_in.rsplit(".",1)[0]+".out"
    cases=load_cases(path_in)
    outcomes=[solve(c) for c in cases]
    save_outcomes(path_out, outcomes)
    





########## SOLUTIONS TESTING ##########


def verify_outcome(case, outcome):
#     return outcome==solvef(case)
    return True

def test_solutions(path_in, until_first_fail=True):
    cases=load_cases(path_in)
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print c
            print "Outcome:"
            print o
            if until_first_fail:
                return c
            else:
                print "\n\n"
                
def gen_cases():
    nc=1
    cases=[]
    for _ in xrange(nc):
        N=100
        horses=[(random.randint(100,1000),random.randint(100,1000)) for _ in xrange(N)]
        dists=[[random.randint(30,200) for _ in xrange(N)] for _ in xrange(N)]
        for i in xrange(N):
            dists[i][i]=-1
        ss=[random.randint(0,N-1) for _ in xrange(N)]
        routes=[(s+1,(s+random.randint(1,N-3))%N+1) for s in ss]
        cases.append((horses,dists,routes))
    return cases
    

def test_solutions_gen(until_first_fail=True):
    cases=gen_cases()
    for cn,c in enumerate(cases):
        o=solve(c)
        if not verify_outcome(c,o):
            print "Wrong outcome!"
            print "Case #{0}:".format(cn)
            print c
            print "Outcome:"
            print o
            if until_first_fail:
                return c
            else:
                print "\n\n"