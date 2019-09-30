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
    b = [[c for c in S()] for _ in range(19)]
    d = collections.defaultdict(int)
    for l in b:
        for c in l:
            d[c] += 1
    if d['o'] - d['x'] > 1 or d['o'] - d['x'] < 0:
        return 'NO'
    def ff(b):
        # yoko
        f = [[False]*19 for _ in range(19)]
        for i in range(19):
            l = b[i]
            for j in range(19):
                if f[i][j] or l[j] == '.':
                    continue
                t = l[j]
                tc = 1
                for k in range(j+1,19):
                    if l[k] != t:
                        break
                    f[i][k] = True
                    tc += 1
                if tc > 4:
                    return
        # tate
        f = [[False]*19 for _ in range(19)]
        for i in range(19):
            for j in range(19):
                if f[i][j] or b[j][i] == '.':
                    continue
                t = b[j][i]
                tc = 1
                for k in range(j+1,19):
                    if b[k][i] != t:
                        break
                    f[i][k] = True
                    tc += 1
                if tc > 4:
                    return False
        # naname1
        f = [[False]*19 for _ in range(19)]
        for i in range(19):
            for j in range(19):
                if f[i][j] or b[i][j] == '.':
                    continue
                t = b[i][j]
                tc = 1
                for k in range(j+1,19):
                    if i+tc > 18 or b[i+tc][k] != t:
                        break
                    f[i+tc][k] = True
                    tc += 1
                if tc > 4:
                    return
        # naname2
        f = [[False]*19 for _ in range(19)]
        for i in range(18,-1,-1):
            for j in range(19):
                if f[i][j] or b[i][j] == '.':
                    continue
                t = b[i][j]
                tc = 1
                for k in range(j+1,19):
                    if i-tc < 0 or b[i-tc][k] != t:
                        break
                    f[i-tc][k] = True
                    tc += 1
                if tc > 4:
                    return

        return True

    if d['o'] - d['x'] == 1:
        for i in range(19):
            for j in range(19):
                if b[i][j] != 'o':
                    continue
                b[i][j] = '.'
                if ff(b) == True:
                    return 'YES'
                b[i][j] = 'o'
    else:
        if d['x'] == 0:
            return 'YES'
        for i in range(19):
            for j in range(19):
                if b[i][j] != 'x':
                    continue
                b[i][j] = '.'
                if ff(b) == True:
                    return 'YES'
                b[i][j] = 'x'
    return 'NO'




print(main())