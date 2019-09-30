def read_list(f):
    return [int(x) for x in f.readline().split()]
def read_tuple(f):
    return tuple(read_list(f))

def load_single_case(f):
    return read_tuple(f)


def load_cases(path):
    with open(path) as f:
        n=int(f.readline())
        cases=[]
        for _ in xrange(n):
            cases.append(load_single_case(f))
    return cases




def to_binary(a, l):
    if a==0:
        return "0"*l
    b=""
    while a>0:
        b=b+str(a%2)
        a=a/2
    if l<len(b):
        raise ValueError("Space too small!")
    b="".join(b)+"0"*(l-len(b))
    return b
def band(x, y):
    return "".join("1" if xe=="1" and ye=="1" else "0" for xe,ye in zip(x,y))
def gen_masks(a):
    masks=[]
    masks.append((0,a))
    for i,c in enumerate(a):
        if c=='1':
            masks.append((i,"0"*(i+1)+a[i+1:]))
    return masks
def count_single_maks(am, bm, km):
    if am[0]<bm[0]:
        am,bm=bm,am
    al,ap=am
    bl,bp=bm
    kl,kp=km
    if al<=kl and bl<=kl:
        #print "1"
        mpl=kl
        #print mpl,ap[mpl:],bp[mpl:],kp[mpl:]
        if band(ap[mpl:],bp[mpl:])!=kp[mpl:]:
            return 0
        return 2**(al+bl)
    if al>kl and bl<=kl:
        #print "2"
        mpl=al
        #print mpl,ap[mpl:],bp[mpl:],kp[mpl:]
        if band(ap[mpl:],bp[mpl:])!=kp[mpl:]:
            return 0
        wcn=2**(kl+bl)
        bovr=bp[kl:al]
        kovr=kp[kl:al]
        ovrl=0
        for bc,kc in zip(bovr,kovr):
            if bc=="0" and kc=="0":
                ovrl=ovrl+1
            elif bc=="0" and kc=="1":
                ovrl=None
                break
        if ovrl==None:
            return 0
        else:
            return wcn*2**ovrl
    if al>kl and bl>kl:
        #print "3"
        mpl=al
        #print mpl,ap[mpl:],bp[mpl:],kp[mpl:]
        if band(ap[mpl:],bp[mpl:])!=kp[mpl:]:
            return 0
        wcn=2**(kl*2)
        kovr=kp[kl:bl]
        ovrl=0
        for kc in kovr:
            if kc=="0":
                ovrl=ovrl+1
        wcn=wcn*3**ovrl
        bovr=bp[bl:al]
        kovr=kp[bl:al]
        ovrl=0
        for bc,kc in zip(bovr,kovr):
            if bc=="0" and kc=="0":
                ovrl=ovrl+1
            elif bc=="0" and kc=="1":
                ovrl=None
                break
        if ovrl==None:
            return 0
        else:
            return wcn*2**ovrl

def m2s(m):
    return "*"*m[0]+m[1][m[0]:]
maxl=32
def count_masks(A,B,K):
    Am=gen_masks(to_binary(A-1,maxl))
    Bm=gen_masks(to_binary(B-1,maxl))
    Km=gen_masks(to_binary(K-1,maxl))
    n=0
    for am in Am:
        for bm in Bm:
            for km in Km:
                mask_n=count_single_maks(am,bm,km)
                #print m2s(am),m2s(bm),m2s(km),mask_n
                n=n+mask_n
    return n         
        
def count_simple(A,B,K):
    n=0
    for a in xrange(A):
        for b in xrange(B):
            if a&b<K:
                n=n+1
    return n
def solve(case):
    A,B,K=case
    return count_masks(A,B,K)






def outcome_string(outcome):
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