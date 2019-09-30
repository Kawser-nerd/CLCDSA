s=input()

ans=0
pre=s[0]
for i in range(1,len(s)):
    if(pre==s[i]):
        continue
    else:
        ans+=1
        pre=s[i]

print(ans)