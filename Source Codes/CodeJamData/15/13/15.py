def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    n,=read_tuple(f)
    pts=[]
    for _ in xrange(n):
        pts.append(read_tuple(f))
    return pts


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def getdir(p1,p2):
    return (p2[0]-p1[0],p2[1]-p1[1])
def classify(d1,d2):
    c=d1[0]*d2[1]-d1[1]*d2[0]
    return 1 if c>0 else (-1 if c<0 else 0)
def find_division(i, j, pts):
    nl,nr=0,0
    d0=getdir(pts[i],pts[j])
    for p in pts:
        d=getdir(pts[i],p)
        c=classify(d0,d)
        if c>0:
            nl=nl+1
        elif c<0:
            nr=nr+1
    return nl,nr
def find_min_cut(i, pts):
    if len(pts)<4:
        return 0
    mincut=len(pts)
    for j in xrange(len(pts)):
        if j!=i:
            nl,nr=find_division(i,j,pts)
            mincut=min(mincut,nl,nr)
    return mincut
def solve(case):
    pts=case
    log=[]
    for i in xrange(len(case)):
        log.append(find_min_cut(i,pts))
    return log





def outcome_string(outcome):
    return "\n"+"\n".join([str(i) for i in outcome])


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
    




def verify_outcome(case, outcome):
    ### IMPLEMENT ###
    return outcome==solve(case)

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