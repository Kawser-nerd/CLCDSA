s=input()
c=0
t=s[0]
for i in range(1,len(s)):
    if t!=s[i]:
        c+=1
        t=s[i]
print(c)