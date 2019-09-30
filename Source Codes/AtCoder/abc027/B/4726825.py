n=int(input())
a=list(map(int,input().split()))
if sum(a)%n!=0:
  print(-1)
  exit()
if a.count(a[0])==n:
  print(0)
  exit()
p=sum(a)//n
count=0
while len(a)>0:
  if a[-1]==p:
    a.pop()
    continue
  tmp=1
  sums=a[-1]
  a.pop()
  while 1:
    if sums==tmp*p:
      break
    tmp+=1
    sums+=a.pop()
  count+=tmp-1
print(count)