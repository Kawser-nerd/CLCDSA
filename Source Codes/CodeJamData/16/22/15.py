import sys
from collections import defaultdict
import operator

def prefixes(C,J,k):
    c = []
    j = []
    for i in range(k): # maybe doesn't go till end?
        if C[i] == '?' and J[i] == '?':
            c.append('0')
            j.append('0')
        if C[i] == '?' and J[i] != '?':
            c.append(J[i])
            j.append(J[i])
        if C[i] != '?' and J[i] == '?':
            c.append(C[i])
            j.append(C[i])
        if C[i] != '?' and J[i] != '?':
            c.append(C[i])
            j.append(J[i])
    return ''.join(c), ''.join(j)

def tomin(x):
    return x.replace('?','0')

def tomax(x):
    return x.replace('?','9')

def p1(l):
    if l =='9':
        return None
    else: return str(int(l)+1)

def m1(l):
    if l =='0':
        return None
    else: return str(int(l)-1)

def run(C,J):
    poss = []
    poss.append(prefixes(C,J,len(C)))

    for i in range(len(C)):
        c,j = prefixes(C,J,i)
        if C[i] != '?' and J[i] != '?':
            poss.append((c+tomin(C[i:]), j+tomax(J[i:])))
            poss.append((c+tomax(C[i:]), j+tomin(J[i:])))
        if C[i] != '?' and J[i] == '?':
            if p1(C[i]):
                poss.append((c+tomax(C[i:]), j + p1(C[i]) + tomin(J[i+1:])))
            if m1(C[i]):
                poss.append((c+tomin(C[i:]), j + m1(C[i]) + tomax(J[i+1:])))
        if C[i] == '?' and J[i] != '?':
            if p1(J[i]):
                poss.append((c+ p1(J[i]) + tomin(C[i+1:]), j + tomax(J[i:])))
            if m1(J[i]):
                poss.append((c+ m1(J[i]) + tomax(C[i+1:]), j + tomin(J[i:])))
        if C[i] == '?' and J[i] == '?':
            poss.append((c+ '1' + tomin(C[i+1:]), j + '0' + tomax(J[i+1:])))
            poss.append((c+ '0' + tomax(C[i+1:]), j + '1' + tomin(J[i+1:])))

    nposs = [(abs(int(a) - int(b)), a, b) for a,b in poss]
    nposs.sort(key = operator.itemgetter(0,1,2))
    return nposs[0][1] + ' ' + nposs[0][2]


f = file(sys.argv[1],'r')
T = int(f.readline().strip())
for case in range(1,T+1):
    C,J = f.readline().strip().split()
    ans = run(C,J)
    print 'Case #%d: %s' % (case, ans)
