n=int(input())
hoge=list(map(int,input().split()))
ans=0
for i in range(n):
  huga=hoge[i]%6
  if(huga==1 or huga==3):
    ans+=0
  elif(huga==2 or huga==4):
    ans+=1
  elif(huga==5):
    ans+=2
  else:
    ans+=3

print(ans)