N=int(input())
l=list(map(int,input().split()))

if sum(l)%N!=0:
  print(-1)
  exit()

ave=sum(l)//N

c=0
s=0
a=0
for x in l:
  a+=1
  s+=x
  if s/a==ave:
    c+=a-1
    a=0
    s=0
print(c)