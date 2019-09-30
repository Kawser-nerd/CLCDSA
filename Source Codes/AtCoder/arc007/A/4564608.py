x=input()
s=input()
c=""
for i in range(len(s)):
    if s[i]!=x:
        c+=s[i]
print(c)