# -*- coding utf-8 -*-

s = str(input())
ans = ""

for i in range(0,len(s),1):
    if s[i] =="1" or s[i] == "0":
        ans += s[i]
    else:
        ans=ans[:-1]

print(ans)