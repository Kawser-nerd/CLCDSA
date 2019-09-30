s=input()
l=len(s)
ans=0
for i in range(1<<( l-1)):
    res=0
    tmp=int(s[0])
    for j in range(l-1):
        if ((i>>j) & 1) == 1:
            res+=tmp
            tmp=int(s[j+1])
        else:
            tmp=tmp*10+int(s[j+1])
    res+=tmp
    ans+=res
print(ans)