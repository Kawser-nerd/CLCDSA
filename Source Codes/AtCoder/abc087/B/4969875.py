a=int(input())
b=int(input())
c=int(input())
x=int(input())
ans=0
for i in range(a+1):
  for j in range(b+1):
    for k in range(c+1):
      if 500*i+100*j+50*k==x:
        ans+=1
      else:
        pass
print(ans)