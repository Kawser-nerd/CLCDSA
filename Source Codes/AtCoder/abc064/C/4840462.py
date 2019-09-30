c=[0]*8;n=int(input());a=list(map(int,input().split()))
r=0
for i in a:
  if i>3199:r+=1
  else:c[i//400]=1
b=c.count(1)
print(max(b,1),b+r)