# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
s = sum(range(1, N+1))


def isPrime(N):
    if N <= 1:
        return False
    i = 2
    while i*i <= N:
        if N % i == 0:
            return False
        i += 1
    return True


if not isPrime(s):
    print("BOWWOW")
else:
    print("WANWAN")