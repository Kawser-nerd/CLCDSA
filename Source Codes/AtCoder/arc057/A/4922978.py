a,k=map(int,input().split())
s=a
t=0
if k==0:
  print(2*(10**12)-a)
  exit()
else:
    while s<2*(10**12):
        s+=1+k*s
        t+=1
print(t)