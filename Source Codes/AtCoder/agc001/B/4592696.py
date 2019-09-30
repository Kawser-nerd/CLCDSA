N,x=map(int,input().split())
x=min(x,N-x)
rem=[N-x,x]
len=x
ans=N
i=1

while True:
  i=(i+1)%2
  ans+=2*(rem[i]//len)*len
  rem[i]=rem[i]%len
  if rem[i]!=0:
  	len=rem[i]
  else:
    break
  
print(ans-len)