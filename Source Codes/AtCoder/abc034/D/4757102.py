# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())
item = []  # [solt,weight]
for _ in range(N):
    w, p = map(int, input().split())
    item.append([p*w, w])


def check(x):
    y = [0]*N
    for i in range(N):
        y[i] = item[i][0]-item[i][1]*x
    y = sorted(y, reverse=True)
    if sum(y[:K]) >= 0:
        return True
    else:
        return False


def solve():
    low = 0
    up = 10**10
    e = 10**(-8)
    while up-low >= e:
        mid = (low+up)/2
        if check(mid):
            low = mid
        else:
            up = mid
    print(up)


solve()