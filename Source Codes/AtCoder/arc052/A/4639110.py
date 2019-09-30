S=input()
num=list(map(str,range(10)))
ans=''
for s in S:
  if s in num:
    ans+=s
print(ans)