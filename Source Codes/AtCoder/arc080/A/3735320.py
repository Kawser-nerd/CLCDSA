N=int(input())
n1,n2,n4=0,0,0
for i in input().split():
  if int(i)%4==0:
    n4+=1
  elif int(i)%2==0:
    n2+=1
  else:
    n1+=1
if n2==0:
  if n4>=n1-1:
    print("Yes")
  else:
    print("No")
else:
  if n4>=n1:
    print("Yes")
  else:
    print("No")