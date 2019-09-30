# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def isPrime(n)->bool:
    if n < 2:
        return False
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


ans = "Not Prime"

N = int(input())
if isPrime(N):
    ans = "Prime"
if N!=1 and N % 2 != 0 and N % 5 != 0 and N % 3 != 0:
    ans = "Prime"
print(ans)