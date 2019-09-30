a,b,k=map(int,input().split())
li=[]
for i in range(min(a,b)):
  if a%(i+1)==0 and 0==b%(i+1) :
    li.append(i+1)
  else:
    pass
li=list(reversed(li))
print(li[k-1])