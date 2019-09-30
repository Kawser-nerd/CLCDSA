import sys


_in = sys.stdin
#_out = sys.stdout


T = int(_in.readline())

for ci in range(T):
    [N,M] = list(map(int,_in.readline().split()))

    boxs = list(map(int,_in.readline().split()))
    toys = list(map(int,_in.readline().split()))

#    box = [0] * N
#    toy = [0] * M

    d = {}

    def LCS(n,m,nr,mr):

        if n == 0 or m ==0:
            return 0

        key = (n,m,nr,mr)
        if key in d:
            return d[key]

        nq=2*n-2
        nt=2*n-1
        mq=2*m-2
        mt=2*m-1

        if boxs[nt]==toys[mt]:
            qb = boxs[nq]-nr
            qt = toys[mq]-mr
            q = min(qb,qt)
            if (qb > qt):
                v = q + LCS(n,m-1,nr+q,0)
            else:
                v = q + LCS(n-1,m,0,mr+q)
        else:
            v = max(LCS(n-1,m,0,mr),LCS(n,m-1,nr,0))

        d[key]=v
        return v
    

    print("Case #{}: {}".format(ci+1,LCS(N,M,0,0)))
