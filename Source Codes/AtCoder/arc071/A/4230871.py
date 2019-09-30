n=int(input())
s=list(input())
for i in range(n-1):
    t=[]
    p=list(input())
    for i in range(len(s)):
        if s[i] in p:
            t.append(s[i])
            p.pop(p.index(s[i]))
    else:
        s=t[:]
s.sort()
c=""
for i in range(len(s)):
    c+=s[i]
print(c)