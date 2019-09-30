# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)

N = int(input())
p = set()
ans = "DRAW"
cnt = 1
prev = input()
p.add(prev)
for _ in range(N-1):
    cnt += 1
    s = input()
    if s[0] == prev[-1]:
        if s in p:
            if cnt % 2 == 1:
                ans = "LOSE"
            else:
                ans = "WIN"
            break
        else:
            prev = s
            p.add(s)
    else:
        if cnt % 2 == 1:
            ans = "LOSE"
        else:
            ans = "WIN"
        break
print(ans)