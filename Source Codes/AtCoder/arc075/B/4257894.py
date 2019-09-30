# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def ceil(x):
    return int((-x)//1*(-1))


N, A, B = map(int, input().split())
hp = [int(input()) for _ in range(N)]
diff = A-B


def check(x, HP):
    cnt = 0
    for i in range(N):
        if HP[i]-B*x <= 0:
            break
        else:
            cnt += ceil((HP[i]-B*x)/diff)
    return cnt <= x


def solve2():
    HP = sorted(hp, reverse=True)
    mi = HP[0]//A
    ma = ceil(HP[0]/B)
    while mi <= ma:
        mid = (mi+ma)//2
        if check(mid, HP):
            ma = mid-1
        else:
            mi = mid+1
    print(mi)


def check2(x, hp):
    l = [a-B*x for a in hp]
    ret = 0
    for a in l:
        if a <= 0:
            continue
        else:
            ret += ceil(a/diff)
    return ret <= x


def solve3():
    mi = max(hp)//A
    ma = ceil(max(hp)/B)
    while mi <= ma:
        mid = (mi+ma)//2
        if check2(mid, hp):
            ma = mid-1
        else:
            mi = mid+1
    print(mi)


solve3()