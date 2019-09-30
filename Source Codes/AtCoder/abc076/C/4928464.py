# -*- coding: utf-8 -*-

s = list(input())
t = list(input())

slen = len(s)
tlen = len(t)

cand = []
for i in range(slen - tlen + 1):
    match = True
    for j in range(tlen):
        if s[i + j] == "?" or s[i + j] == t[j]:
            pass
        else:
            match = False
    if match:
        cand.append(i)

if len(cand) != 0:
    cand.reverse()
    ans = ""
    for i in range(slen):
        if not (cand[0] <= i < cand[0] + tlen):
            if s[i] == "?":
                ans += "a"
            else:
                ans += s[i]
        else:
            ans += t[i - cand[0]]
    print(ans)
else:
    print("UNRESTORABLE")