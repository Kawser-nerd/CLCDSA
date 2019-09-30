import sys

def i2s():
    return sys.stdin.readline().rstrip()

def ii2ss(n):
    return [sys.stdin.readline() for _ in range(n)]

def sp2nn(sp, sep=' '):
    return [int(s) for s in sp.split(sep)]

def ss2nn(ss):
    return [int(s) for s in list(ss)]

def main(s):
    dic = {
        'A': 'T',
        'T': 'A',
        'C': 'G',
        'G': 'C',
    }
    print(dic[s])

main(i2s())