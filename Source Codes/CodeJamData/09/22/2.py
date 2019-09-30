def next(s):
    s=list(s)
    l = len(s)
    i=None
    j=None
    for k in range(l-1):
        if s[k]<s[k+1]:
            i=k
    if i is None:
        s = sorted(s)
        j=0
        while s[j]=='0':
            j+=1
        c = s[j]
        del s[j]
        s.insert(0,c)
        s.insert(1,'0')
        s=''.join(s)
        return s

    for k in range(i,l):
        if s[i]<s[k]:
            j=k
    c=s[i]
    s[i]=s[j]
    s[j]=c
    t=s[i+1:]
    t.reverse()
    s=s[:i+1]+t

    return ''.join(s)

def main(fn):
    f=open(fn)
    n=int(f.readline())
    for i in range(n):
        n=f.readline().strip()
        nxt = next(n)
        print 'Case #%d: %s'%(i+1, nxt)
    return

import sys
main(*sys.argv[1:])
