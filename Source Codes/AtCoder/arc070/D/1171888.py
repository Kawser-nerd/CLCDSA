import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


def pf(s):
    print(s, flush=True)

def main():
    a,b = LI()
    if a <= b:
        return 'Impossible'

    l = []
    for i in range(a+b):
        if not l:
            l.append(i)
            continue
        pf('? {} {}'.format(i,l[-1]))
        if S() == 'Y':
            l.append(i)
        else:
            l = l[:-1]

    r = []
    ai = l[0]
    for i in range(a+b):
        if i == ai:
            r.append('1')
            continue
        pf('? {} {}'.format(ai,i))
        if S() == 'Y':
            r.append('1')
        else:
            r.append('0')

    return '! {}'.format(''.join(r))


print(main(), flush=True)