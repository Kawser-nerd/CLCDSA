# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

S = input()
ans = 0
N = len(S[:-1])
for i in range(1, N+1):
    if S[i-1] == "U":
        ans += N-i + 2*(i-1)
    else:
        ans += 2*(N-i)+i-1
print(ans)