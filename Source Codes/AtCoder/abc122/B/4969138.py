import sys

def i2s():
    return sys.stdin.readline().rstrip()

def ii2ss(n):
    return [sys.stdin.readline() for _ in range(n)]

def sp2nn(sp, sep=' '):
    return [int(s) for s in sp.split(sep)]

def ss2nn(ss):
    return [int(s) for s in list(ss)]

def main(S):
    st = set(('A', 'C', 'G', 'T'))
    cmax = 0
    c = 0
    for s in S:
        if s in st:
            c += 1
        else:
            if cmax < c:
                cmax = c
            c = 0
    if cmax < c:
        cmax = c
    print(cmax)

main(i2s())