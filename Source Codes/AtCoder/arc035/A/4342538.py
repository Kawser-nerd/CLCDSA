import sys

s = input()
rs=s[::-1]

flag = False
for i in range(len(s)):
    if s[i]!=rs[i] and s[i]!="*" and rs[i]!="*":
        flag=True
print("YES" if flag==False else "NO")