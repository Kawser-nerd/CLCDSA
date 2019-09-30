e=list(map(int,input().split()))
b=int(input())
l=list(map(int,input().split()))
x=0
for i in range(6):
  if e.count(l[i])==1:x+=1
if x==6:print(1) 
elif x==5:
  if l.count(b)==1:print(2)
  else:print(3)
elif x==4:print(4)
elif x==3:print(5)
else:print(0)