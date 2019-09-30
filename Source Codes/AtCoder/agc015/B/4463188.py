s=input()
m=len(s)
ans=2*(m-1)
for i in range(1,m-1):
    ans+=i+(m-i-1)
    if s[i]=='D':
        ans+=m-i-1
    else:
        ans+=i
print(ans)