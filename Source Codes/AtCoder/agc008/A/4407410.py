a,b=map(int,input().split())
ans=0
if a==b:
  print(0)
  exit()  
if b>0:
  if abs(a)<abs(b):
    if a<0:
      ans+=1
      ans+=b+a  
    else:
      ans+=b-a  
  else:
    if a<0:
      ans+=abs(a)-b+1
    else:
      ans+=a-b+2
else:
  if abs(a)<abs(b):
    if a<0:  
      ans+=2
      ans+=a-b
    else:
      ans+=abs(b)-a
      ans+=1 
  else:
    if a<0:
      ans+=b-a
    else:
      ans+=a+b+1
print(ans)