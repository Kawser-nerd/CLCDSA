# coding:utf-8

import sys
from collections import Counter

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    s = SI()
    char_cnt = Counter(s)

    res = INF
    for c in char_cnt.keys():
        r = s[:]
        cnt = 0
        while len(set(r)) != 1:
            t = ''
            for ss in zip(r[:-1], r[1:]):
                if c in ss:
                    t += c
                else:
                    t += ss[0]
            cnt += 1
            r = t
            # print(r)
        res = min(res, cnt)

    return res


print(main())