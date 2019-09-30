# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M = map(int, input().split())
L = input()[:-1]

ans = 0
i = len(L)-1
first = True
while i >= 0:
    if L[i] == "o":
        i -= 1
    else:
        if first:
            ans += 1
            i -= M
            if i >= 0:
                ans += i+1
            first = False
        else:
            ans += 1
            i -= M
print(ans)