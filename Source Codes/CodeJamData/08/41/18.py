
from math import log

def dofile(fname,outfname):
    result = dostr(file(fname).read())
    file(outfname,'w').write(result)

def dostr(s):
    dat = s.splitlines()

    #split to data sets
    N = int(dat[0])
    dat = dat[1:]
    results = []
    for i in xrange(N):
        (M,V) = map(int,dat[0].split(' '))
        dat = dat[1:]
        results.append(solve(dat[:M],V,i+1))
        dat = dat[M:]

    return '\n'.join(results)


def solve(T,V,ind):
    print len(T),V,ind
    M = len(T)
    inner = T[:(M-1)/2]
    outer = T[(M-1)/2:]
    print M,len(inner),len(outer)
    nodes = [Node(s, None,None) for s in outer]
    while len(inner)>0:
        n = Node(inner[-1], nodes[-2],nodes[-1])
        nodes = [n,]+ nodes[:-2]
        inner = inner[:-1]
    ##    return nodes
    (a,aa) = nodes[0].check()
    print "final ",a,aa
    if a == V:
        res = 0
    else:
        if aa >= 100000:
            res = -1
        else:
            res = aa

    if res == -1:
        return "Case #%d: IMPOSSIBLE" % (ind,)
    return "Case #%d: %d" % (ind, res)
    


class Node:
    def __init__(self,s,left,right):
        sp = s.split(' ')
        if len(sp)==1:
            #leaf
            self.leaf = True
            self.val = int(sp[0])
            self.change = 0
        else:
            self.leaf = False
            self.val = int(sp[0])
            self.change = int(sp[1])
            self.left = left
            self.right = right
    def check(self):
        if self.leaf:
            return (self.val,100000)
        else:
            (a,aa) = self.left.check()
            #print (a,aa)
            (b,bb) = self.right.check()
            #print (b,bb)
            if (True):
                #AND
                vand = a and b
                # OR
                vor = a or b
                if a and b :
                    mand = min(aa,bb)
                if a and (not b):
                    mand = bb
                if b and (not a):
                    mand = aa
                if (not a) and (not b):
                    mand = aa + bb
                if a and not b:
                    mor = aa
                if (not a) and b:
                    mor = bb
                if (not a) and (not b):
                    mor = min(aa,bb)
                if a and b:
                    mor = aa + bb
            if not self.change:
                if self.val == 1:
                    return (vand,mand)
                else:
                    return (vor,mor)
            
            if self.val == 1:
                if vor != vand:
                    return (vand,1)
                else:
                    return (vand, min(mand, mor+1))
            else:
                if vor != vand:
                    return (vor,1)
                else:
                    return (vor, min(mor, mand+1))
            

exmple = """2
9 1
1 0
1 1
1 1
0 0
1
0
1
0
1
5 0
1 1
0 0
1
1
0"""


ex2 = "1\n10001 1\n"+"1 1\n"*5000+"0\n"*5001
