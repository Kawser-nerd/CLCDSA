import sys
sys.setrecursionlimit(10000)

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
    return read_tuple(f)[1:]


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases



def solve_simple(R, B, Y):
    N=R+B+Y
    if R*2>N or B*2>N or Y*2>N:
        return None
    #cs=[(R,"R"),(B,"B"),(Y,"Y")]
    cs={"R":R,"B":B,"Y":Y}
    csa=[(v,k) for (k,v) in cs.iteritems()]
    csa.sort()
    arr=csa[-1][1]
    cs[arr]-=1
    for _ in xrange(N-1):
        nk=arr[-1]
        maxc=max(v for (k,v) in cs.iteritems() if k!=nk)
        if (arr[0]!=nk) and (cs[arr[0]]==maxc):
            arr+=arr[0]
            cs[arr[0]]-=1
        else:
            maxk=[k for (k,v) in cs.iteritems() if (v==maxc and k!=nk)][0]
            arr+=maxk
            cs[maxk]-=1
    return arr if arr[0]!=arr[-1] else None

def solve_bf(case):
    R,O,Y,G,B,V=case
    if (O+G+V):
        return None
    return solve_simple(R,B,Y)



def solve_full(R, B, Y, V, G, O):
    if V>Y:
        return None
    if V and V==Y:
        if R+B+G+O==0:
            return "VY"*V
        return None
    if G>R:
        return None
    if G and G==R:
        if B+Y+V+O==0:
            return "GR"*G
        return None
    if O>B:
        return None
    if O and O==B:
        if R+Y+V+G==0:
            return "OB"*O
        return None
    subs={}
    subs["Y"]="Y"+"VY"*V
    subs["R"]="R"+"GR"*G
    subs["B"]="B"+"OB"*O
    Y-=V
    R-=G
    B-=O
    N=R+B+Y
    if R*2>N or B*2>N or Y*2>N:
        return None
    cs={"R":R,"B":B,"Y":Y}
    csa=[(v,k) for (k,v) in cs.iteritems()]
    csa.sort()
    arr=csa[-1][1]
    cs[arr]-=1
    for _ in xrange(N-1):
        nk=arr[-1]
        maxc=max(v for (k,v) in cs.iteritems() if k!=nk)
        if (arr[0]!=nk) and (cs[arr[0]]==maxc):
            arr+=arr[0]
            cs[arr[0]]-=1
        else:
            maxk=[k for (k,v) in cs.iteritems() if (v==maxc and k!=nk)][0]
            arr+=maxk
            cs[maxk]-=1
    if arr[0]==arr[-1]:
        return None
    for c,s in subs.iteritems():
        arr=arr.replace(c,s,1)
    return arr

def solve(case):
    R,O,Y,G,B,V=case
    soln=solve_full(R,B,Y,V,G,O)
    if soln is None:
        return None
#     for c,n in [("R",R),("O",O),("Y",Y),("G",G),("B",B),("V",V)]:
#         assert soln.count(c)==n
    return soln






def outcome_string(outcome):
    return "{}".format(outcome) if outcome else "IMPOSSIBLE"


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
    ### IMPLEMENT ###
    return outcome==solve_bf(case)

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
    ### IMPLEMENT ###
    return []

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