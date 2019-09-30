n,x=map(int,input().split());a=list(map(int,input().split()));a.sort();ans=0
for i in range(n):
  if a[i]>x:break
  else:
    ans+=1
    x-=a[i]
    if i==n-1 and x!=0:ans-=1
print(ans)