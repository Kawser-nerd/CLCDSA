# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


R, B = map(int, input().split())
x, y = map(int, input().split())


def check(n: int)->bool:
    """
    ???n??????????????
    """
    rR = R-n
    rB = B-n
    if rR < 0 or rB < 0:
        return False
    return rR//(x-1)+rB//(y-1) >= n


lower = 0
upper = max(R, B)

while lower+1 < upper:
    mid = (lower+upper)//2
    if check(mid):
        lower = mid
    else:
        upper = mid
print(lower)