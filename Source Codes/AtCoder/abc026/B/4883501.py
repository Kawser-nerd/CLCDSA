n=int(input())
hoge=[]
for i in range(n):
  hoge.append(int(input()))
hoge.sort(reverse=True)
ans=0
flag=0
for i in range(n):
  if(flag==0):
    ans+=hoge[i]**2
    flag=1
  else:
    ans-=hoge[i]**2
    flag=0
    
print(ans*3.1415926535)