from math import ceil
n=int(input())
ans4=0
ans2=0
ans0=0
a=list(map(int,input().split()))
for i in range(n):
  if a[i]%4==0:
    ans4+=1
  elif a[i]%2==0:
    ans2+=1
  else:
    ans0+=1
if ans2>0:
  if ans0<=ans4:
    print('Yes')
  else:
    print('No')
else:
  if ceil((ans0+ans4)/2)>=ans0:
    print('Yes')
  else:
    print('No')