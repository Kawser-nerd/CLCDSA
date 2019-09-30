# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
e = [list(map(int, input().split())) for _ in range(N)]


def check(mid):
    """
    ?????t??????????Ture
    ???????false
    """
    lx = ly = -float('inf')
    ux = uy = float('inf')
    for a, b, w in e:
        dist = mid/w
        _lx, _ux = a-dist, a+dist
        _ly, _uy = b-dist, b+dist

        lx = _lx if _lx > lx else lx
        ly = _ly if _ly > ly else ly

        ux = _ux if ux > _ux else ux
        uy = _uy if uy > _uy else uy
    return lx > ux or ly > uy


def solve():
    e = 10**(-6)
    upper = 10**10
    lower = 0
    while upper-lower > e:
        mid = (lower+upper)/2
        if check(mid):
            lower = mid
        else:
            upper = mid
    print(lower)


solve()