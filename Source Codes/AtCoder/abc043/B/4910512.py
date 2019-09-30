# -*- coding utf-8  -*-
s=str(input())

ans=""

for i in range(0,len(s),1):
    if s[i]=="0":
        ans +="0"
    elif s[i]=="1":
        ans +="1"
    elif s[i]=="B":
        ans=ans[:-1]
print(ans)