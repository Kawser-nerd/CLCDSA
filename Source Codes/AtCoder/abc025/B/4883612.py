n,a,b=map(int,input().split())
ans=0

for i in range(n):
  muki,atai=map(str,input().split())
  atai=int(atai)
  
  if(a>atai):
    atai=a
  elif(b<atai):
    atai=b
  
  if(muki=="East"):
    ans+=atai
  else:
    ans-=atai
    
if(ans>0):
  print("East",ans)
elif(ans<0):
  print("West",-ans)
else:
  print(0)