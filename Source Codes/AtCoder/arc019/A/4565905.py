s=input()
c=""
d=["O","D","I","Z","S","B"]
e=[0,0,1,2,5,8]
for i in range(len(s)):
    if s[i] in d:
        c+=str(e[d.index(s[i])])
    else:
        c+=s[i]
print(c)