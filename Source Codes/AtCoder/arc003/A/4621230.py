n=int(input())
c=input()
ans=0
for i in range(n):
  if c[i]=="A":ans+=4
  elif c[i]=="B":ans+=3
  elif c[i]=="C":ans+=2
  elif c[i]=="D":ans+=1
print(ans/n)