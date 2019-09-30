def binom(n,m):
    if m<0 or m>n: return 0
    return bin[n][m]

def binoms(n):
    #if m<=0: return 0
    b = [0] * (n + 1)
    b[0] = 1
    for i in xrange(1, n + 1):
        b[i] = 1
        j = i - 1
        while j > 0:
            b[j] += b[j - 1]
            j -= 1
    return b

bin=[binoms(n) for n in xrange(41)]

for case in range(input()):
    print "Case #"+str(case+1)+":",
    C,N=map(int,raw_input().split())
    ex=[0.0 for i in xrange(C+N+1)]
    ex[C]=0
    CcN=float(binom(C,N))
    for i in xrange(C-1,-1,-1):
        ex[i]=(1.0+sum(binom(i,k)*binom(C-i,N-k)*ex[i+N-k]/CcN for k in xrange(N)))/(1-binom(i,N)*binom(C-i,0)/CcN)
        #print ex[i]
    print ex[0]
