s = input()
se = set("".join(s))
ans = 10**10
for m in se:
    t = s
    tans = 0
    for i in range(len(s)):
        if len(set("".join(t))) == 1 and m in t:
            break
        tt = ""
        for j in range(len(t)-1):
            if t[j] == m or t[j+1] == m:
                tt += m
            else:
                tt += t[j]
        tans += 1
        t = tt
    ans = min(ans , tans)
print(ans)