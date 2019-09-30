s=input()
ans=0
for i in range(len(s)):
  if s[i]=="D":
    ans+=i*1+(len(s)-i-1)*2
  else:
    ans+=i*2+(len(s)-i-1)*1
print(ans)