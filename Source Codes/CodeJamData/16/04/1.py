import math

t = int(input())
for cs in range(1, t + 1):
    (k, c, s) = map(int, input().split())
    ls = []
    for i in range(0, k, c):
        cnt = 0
        now = 0
        for j in range(i, min(i + c, k)):
            cnt += 1
            now = now * k + j
        while (cnt < c):
            now = now * k + (k - 1)
            cnt += 1
        ls.append(now + 1)
    if len(ls)<= s:
        ans = " ".join(map(str, ls))
    else:
        ans = "IMPOSSIBLE"
    print("Case #" + str(cs) + ": " + ans)

