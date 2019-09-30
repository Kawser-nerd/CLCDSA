y=int(input())
ans=0
if y%4==0:
  ans+=1
if y%100==0:
  ans-=1
if y%400==0:
  ans+=1

if ans==1:
  print("YES")
else:
  print("NO")