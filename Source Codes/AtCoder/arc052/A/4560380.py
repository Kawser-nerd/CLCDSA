s=input()
c=""
for i in range(len(s)):
    if ord(s[i])<=57:
        c+=s[i]
print(c)