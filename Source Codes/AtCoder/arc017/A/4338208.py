# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
i = 2
ans = "YES"
while i*i <= n:
    if n % i == 0:
        ans = "NO"
        break
    else:
        i += 1
print(ans)