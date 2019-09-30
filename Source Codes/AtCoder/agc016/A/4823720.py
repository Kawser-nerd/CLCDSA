s = input()
n = len(s)
a = list(set(list(s)))
ans = 1000
for x in a:
    t = 0
    l = r = 0
    while l < n:
        while r < n and s[r] != x:
            r += 1
        t = max(t, r - l)
        l = r + 1
        r = l
    ans = min(ans, t)
print(ans)