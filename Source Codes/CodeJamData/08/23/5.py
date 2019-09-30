from sys import stdin

def foo(K):
    bit = list(xrange(K+1))
    x = 1
    for i in xrange(K):
        yield bit[x]
        if i+1 == K:
            break
        del bit[x]
        x = (x+i)%(K-i-1)+1
        


tno = int(stdin.readline())
for j in xrange(tno):
    K = int(stdin.readline().strip())
    x = map(int, stdin.readline().strip().split())[1:]
    t = [0]*(K+1)
    for i, v in enumerate(foo(K)):
        t[v] = i+1
    print "Case #%d: %s"%(j+1,' '.join(str(t[xx]) for xx in x))
