n,p=map(int,input().split())
l=list(map(lambda x:int(x)%2,input().split()))
a,b=0,0
for i in l:
  if i>0:
    a+=1
  else:
    b+=1
if a==0:
  if p==0:
    print(2**n)
  else:
    print(0)
else:
  print(2**(n-1))