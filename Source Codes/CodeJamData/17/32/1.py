import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

def main():
    tt = I()
    rr = []
    TM = 60*24
    for ti in range(1,tt+1):
        kk,jj = LI()
        a = sorted([LI() for _ in range(kk)])
        b = sorted([LI() for _ in range(jj)])

        r = 0
        m = 0
        for i in range(kk):
            if i == 0:
                a[0].append(a[0][0] - a[-1][1] + TM)
            else:
                a[i].append(a[i][0] - a[i-1][1])
            a[i].append(i)
            m += a[i][1] - a[i][0]

        c = sorted(a, key=lambda x: x[2])
        for i in range(kk):
            ci = c[i]
            if ci[2] + m > 720:
                break
            f = False
            for j in range(jj):
                if ci[3] == 0:
                    if a[ci[3]-1][1] <= b[j][0]+TM <= ci[0]+TM or\
                       a[ci[3]-1][1] <= b[j][1]+TM <= ci[0]+TM or\
                       a[ci[3]-1][1] <= b[j][0] <= ci[0]+TM or\
                       a[ci[3]-1][1] <= b[j][1] <= ci[0]+TM:
                        f = True
                        break
                if a[ci[3]-1][1] <= b[j][0] <= ci[0] or a[ci[3]-1][1] <= b[j][1] <= ci[0]:
                    f = True
                    break
            if f:
                continue
            r += 1
            m += ci[2]
        kr = kk-r

        r = 0
        m = 0
        a,b = b,a
        kk,jj = jj,kk
        for i in range(kk):
            if i == 0:
                a[0].append(a[0][0] - a[-1][1] + TM)
            else:
                a[i].append(a[i][0] - a[i-1][1])
            a[i].append(i)
            m += a[i][1] - a[i][0]

        c = sorted(a, key=lambda x: x[2])
        for i in range(kk):
            ci = c[i]
            if ci[2] + m > 720:
                break
            f = False
            for j in range(jj):
                if ci[3] == 0:
                    if a[ci[3]-1][1] <= b[j][0]+TM <= ci[0]+TM or\
                       a[ci[3]-1][1] <= b[j][1]+TM <= ci[0]+TM or\
                       a[ci[3]-1][1] <= b[j][0] <= ci[0]+TM or\
                       a[ci[3]-1][1] <= b[j][1] <= ci[0]+TM:
                        f = True
                        break
                if a[ci[3]-1][1] <= b[j][0] <= ci[0] or a[ci[3]-1][1] <= b[j][1] <= ci[0]:
                    f = True
                    break
            if f:
                continue
            r += 1
            m += ci[2]
        jr = kk-r


        rr.append('Case #{}: {}'.format(ti, max(kr,jr)*2))

    return '\n'.join(rr)


print(main())
