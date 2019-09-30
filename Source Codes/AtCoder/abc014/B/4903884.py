a,b=map(int,input().split())
hoge=list(map(int,input().split()))
c=bin(b)
c=c[2:]
c=c[::-1]
ans=0
for i in range(len(c)):
  if(c[i]=="1"):
    ans+=hoge[i]
print(ans)