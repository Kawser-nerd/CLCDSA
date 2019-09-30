def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    N,=read_tuple(f)
    words=[]
    for _ in xrange(N):
        words.append(f.readline().strip())
    return words


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def compress_word(w):
    c=w[0]
    n=1
    cw=[]
    for i in xrange(1,len(w)):
        if w[i]==c:
            n=n+1
        else:
            cw.append((c,n))
            c=w[i]
            n=1
    cw.append((c,n))
    return cw
def words_compatible(w1, w2):
    if len(w1)!=len(w2):
        return False
    for p1,p2 in zip(w1,w2):
        if p1[0]!=p2[0]:
            return False
    return True
def find_min_distance(ls):
    min_d=sum(ls)
    for x in xrange(min(ls),max(ls)+1):
        d=sum([abs(x-l) for l in ls])
        min_d=min(min_d,d)
    return min_d
def solve(case):
    words=case
    words=[compress_word(w) for w in words]
    for w in words[1:]:
        if not words_compatible(w,words[0]):
            return None
    l=len(words[0])
    d=0
    for i in xrange(l):
        d=d+find_min_distance([w[i][1] for w in words])
    return d





def outcome_string(outcome):
    if outcome is None:
        return "Fegla Won"
    else:
        return "{}".format(outcome)


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