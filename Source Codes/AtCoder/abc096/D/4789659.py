n=int(input())
prime=[2]
no=3
mod1=[]
mod2=[2]
mod3=[]
mod4=[]
while len(mod1)<n and len(mod2)<n and len(mod3)<n and len(mod4)<n:
  for i in prime:
    if(no%i==0):
      no+=1
      break
  else:
    prime.append(no)
    if(no%5==1):
      mod1+=[no]
    elif(no%5==2):
      mod2+=[no]
    elif(no%5==3):
      mod3+=[no]
    elif(no%5==4):
      mod4+=[no]
    no+=1
if(len(mod1)==n):
  ans=mod1
elif(len(mod2)==n):
  ans=mod2
elif(len(mod3)==n):
  ans=mod3
elif(len(mod4)==n):
  ans=mod4
for i in ans:
  print(i,end=' ')