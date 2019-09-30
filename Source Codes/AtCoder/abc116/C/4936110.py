import sys

def ii2ss(n):
    return [sys.stdin.readline() for _ in range(n)]

def sp2nn(sp, sep=' '):
    return [int(s) for s in sp.split(sep)]

def ss2nn(ss):
    return [int(s) for s in list(ss)]

def count(hh, n):
    c = 0
    b = False
    for h in hh:
        if h >= n:
            if b == False:
                b = True
                c += 1
        else:
            if b == True:
                b = False
    return c
    
def main(ss):
    hh = sp2nn(ss[1])
    total = 0
    n = 1
    while True:
        c = count(hh, n)
        if c == 0:
            break
        total += c
        n += 1
    print(total)

main(ii2ss(2))