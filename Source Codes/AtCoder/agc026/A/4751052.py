n=int(input());a=list(map(int,input().split()));c,ans=1,0
for i in range(n-1):
  if a[i]==a[i+1]:c+=1
  else:
    if c>=2:ans+=c//2
    c=1
if c>=2:ans+=c//2
print(ans)