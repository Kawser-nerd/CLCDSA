import sys

infile=open(sys.argv[1])
#infile=open('C-sample.txt')

choose=[[1 for i in range(41)] for j in range(41)]

def fchoose():
    for n in range(1,41):
        for k in range(1,n):
            choose[n][k]=choose[n-1][k-1]+choose[n-1][k]


def U(s,t):
    k=t-s
    r=N
    n=C
    return choose[s][r-k]*choose[n-s][k]/float(choose[n][r])

def M():
    r=N
    n=C
    for s in range(C-1,N-1,-1):
        S=sum([U(s,t)*m[t] for t in range(s+1,min(n,s+r)+1)])
        m[s]=(1+S)/(1-U(s,s))

if __name__ == '__main__':
    fchoose()
    T=int(infile.readline())
    for i in range(T):
        C,N=[int(x) for x in infile.readline().split()]
        m=[0 for j in range(C+1)]
        M()
        print 'Case #%s: %.7f' % (i+1,1+m[N])
