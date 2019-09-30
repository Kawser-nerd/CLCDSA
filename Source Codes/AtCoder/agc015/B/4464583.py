from collections import deque

s = input()
n = len(s)

ans = 0
for i, si in enumerate(s):
    if si == "U":
        ans += n - (i+1)
        ans += i * 2
    else:
        ans += (n - (i+1)) * 2
        ans += i

print(ans)