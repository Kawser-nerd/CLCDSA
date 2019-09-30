n=int(input())
hoge=[]
for i in range(n):
  hoge.append(int(input()))
ans=0
punch=1
while 1:
  ans+=1
  punch=hoge[punch-1]
  if(punch-1==1):
    print(ans)
    break
  if(ans>=100001):
    print(-1)
    break