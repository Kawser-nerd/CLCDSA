s=input()
ls=len(s)
c=0
ans=0
for i in range(ls):
    if s[i]=='S':
        c+=1
    elif c>0:
        ans+=2
        c-=1
print(ls-ans)