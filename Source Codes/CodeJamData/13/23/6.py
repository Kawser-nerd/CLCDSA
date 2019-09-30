from itertools import izip
import time


def test(w, S, N, i, j):
    if len(w) > N - i: return False
    cnt = 0
    k = j - 5
    for n in xrange(len(w)):
        if w[n] != S[i + n]:
            if k + 5 > n:
                return False
            else:
                k = n
                cnt += 1
    if k + 5 <= len(w):
        return 0, cnt
    return 5 + k - len(w), cnt

#test("duction", 0, 4, "ductii")

D = {}
DD = [{} for i in xrange(6)]
c = 0
st = time.time()
with open("C.txt") as f:
    for l in f:
        w = l.strip()
        c += 1
        D[c] = w
        for i in xrange(5):
            wp = w[:i] + w[i+1:i+5]
            DD[i].setdefault(wp, []).append(c)
        DD[5].setdefault(w[:5], []).append(c)

#print "took ", time.time() - st

def _choose(S, N, i, j):
    key = S[i:i+j] + S[i+j+1:i+j+5]
    #print "<", i, j, key
    for k in xrange(len(key)+1):
        #print i, j, key[:k]
        yield DD[j].get(key[:k], [])

    for k in xrange(5):
        yield DD[5].get(S[i:i+k+1], [])

def choose(S, N, i, j):
    cnt = 0
    for J in xrange(j,5):
        for l in _choose(S,N,i,J):
            for c in l:
                yield D[c]
                cnt += 1
    #print i, j, "found ", cnt


def do(S, N, A, i, j):
    L = N - i

    res = 100000
    word = None
    """ 
    wds = set(choose(S,N,i,j))
    for w in D.itervalues():
        if test(w, S, N, i, j) and w not in wds:
            print S[i:], i, j, w
            raise Exception("WTF")
    """
    ii = 0
    for w in choose(S,N,i,j):
        ii+=1
        #print S[i:i+j], w
        ans = test(w, S, N, i, j)
        if ans is False:
            continue
        k, c = ans
        cnt, words, _ii = min(A[i+len(w)][k:5])
        if c + cnt < res:
            res = c + cnt
            word = [w] + words
    A[i][j] = [res, word, ii]

import pprint
pp = pprint.pprint
def CASE(IN):
    def rstr(): return IN.readline().strip()
    def rint(): return int(rstr())
    def rints(): return map(int, rstr().split())
    def nrints(N): return [rints() for i in xrange(N)]
    S = rstr() 
    N = len(S)
    A = [([[0,[None],0]]*5) for i in xrange(N+1)]
    for i in xrange(N-1,-1,-1):
        for j in xrange(5):
            #print ">>>", i, j
            do(S,N,A,i,j)
            #print i, j, A[i][j]
    #pp(A)
    result =  min(A[0])
    #print "RESULT: ", ' '.join(result[1][:-1])
    return result[0]

def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1,t+1):
        OUT.write("Case #%i: %s\n" % (i, CASE(IN)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
