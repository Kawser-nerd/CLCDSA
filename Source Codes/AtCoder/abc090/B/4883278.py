a,b=map(int,input().split())
cnt=0
for i in range(a,b+1):
  s=str(i)
  if s[0]==s[4] and s[1]==s[3]:
    cnt+=1
print(cnt)