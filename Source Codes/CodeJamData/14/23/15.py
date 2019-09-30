def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    N,M=read_tuple(f)
    zc=[]
    for _ in xrange(N):
        zc.append(read_tuple(f)[0])
    conn=[]
    for _ in xrange(M):
        edge=read_tuple(f)
        conn.append((edge[0]-1,edge[1]-1))
    return zc,conn


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases





def test_possible(route, chain, visited, reach):
    if route==[]:
        return True
    if chain==[]:
        visited.add(route[0])
        return test_possible(route[1:],[route[0]],visited,reach)
    n=route[0]
    for i in xrange(len(chain)-1,-1,-1):
        v=chain[i]
        if n in reach[v]:
            visited.add(n)
            return test_possible(route[1:],chain[:i+1]+[n],visited,reach)
    return False
def gen_perm(elts):
    if elts==[]:
        return [[]]
    ps=[]
    for i in xrange(len(elts)):
        sps=gen_perm(elts[:i]+elts[i+1:])
        ps=ps+[[elts[i]]+sp for sp in sps]
    return ps
def solve(case):
    zc,conn=case
    N=len(zc)
    cities=range(N)
    cities.sort(key = lambda i:zc[i])
    reach=dict([(i,[]) for i in xrange(N)])
    for c in conn:
        reach[c[0]].append(c[1])
        reach[c[1]].append(c[0])
    routes=gen_perm(cities[1:])
    routes=[[cities[0]]+r for r in routes]
    min_r=None
    for r in routes:
        if test_possible(r,[],set(),reach):
            min_r=r
            break
    return [zc[i] for i in min_r]





def outcome_string(outcome):
    return "".join([str(z) for z in outcome])


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