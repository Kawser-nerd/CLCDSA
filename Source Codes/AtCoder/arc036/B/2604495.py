n=int(input())
ans=0
l=0
u=1
c=0
for j in range(n):
  i=int(input())
  if u==0 and i>l:
    c=1
  
  if i>l:
    u=1
  elif i<l:
    u=0
    
  c+=1
  ans=max(ans,c)
  l=i
print(ans)