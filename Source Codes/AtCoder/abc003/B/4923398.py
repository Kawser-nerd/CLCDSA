hoge=input()
huga=input()
ans=0
c="atcoder"
for i in range(len(hoge)):
  a=hoge[i]
  b=huga[i]
  if(a==b):
    ans+=0
  else:
    if(c.count(a)==1 and b=="@"):
      ans+=0
    elif(c.count(b)==1 and a=="@"):
      ans+=0
    else:
      ans+=1

if(ans==0):
  print("You can win")
else:
  print("You will lose")