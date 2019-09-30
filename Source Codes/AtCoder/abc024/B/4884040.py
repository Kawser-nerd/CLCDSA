n,t=map(int,input().split())
hoge=[]
for i in range(n):
  hoge.append(int(input()))
  
ans=0
for i in range(n-1):
  if(hoge[i]+t>hoge[i+1]):
    ans+=hoge[i+1]-hoge[i]
  else:
    ans+=t
    
ans+=t

print(ans)