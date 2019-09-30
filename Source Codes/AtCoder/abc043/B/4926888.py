s=input()
s=list(s)
l=[]
ls=len(s)
for i in range (ls):
    if s[i]=='1':
        l.append(1)
    elif s[i]=='0':
        l.append(0)
    else:
        if len(l)==0:
            l=l
        else:
            l.pop()
ans=""
for i in range(len(l)):
    ans=ans+str(l[i])
print(ans)