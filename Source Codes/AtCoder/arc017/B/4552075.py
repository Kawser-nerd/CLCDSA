# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, K = map(int, input().split())


def solve():
    prev = 0
    l = 0
    r = 0
    ans = 0
    A = [int(input()) for _ in range(N)]
    while r < N:
        if A[r] > prev:
            prev = A[r]
            r += 1
            if r-l == K:
                ans += 1
                l += 1
        else:
            prev = 0
            l = r
    print(ans)


def solve2():
    prev = 0
    l = 0
    r = 0
    ans = 0
    A = [int(input()) for _ in range(N)]
    while r < N:
        if A[r] > prev:
            prev = A[r]
            r += 1
        else:
            prev = 0
            if r-l >= K:
                ans += (r-l)-K+1
            l = r
    if r-l >= K:
        ans += (r-l)-K+1
    print(ans)


solve2()