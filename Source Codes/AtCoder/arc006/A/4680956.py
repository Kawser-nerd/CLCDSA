e=list(map(int,input().split()))
b=int(input())
l=list(map(int,input().split()))
ct=0;ctb=0
for i in range(6):
  if l[i] in e:
    ct+=1
  if l[i]==b:
    ctb+=1
if ct==6:print(1)
elif ct==5 and ctb==1:print(2)
elif ct==5:print(3)
elif ct>2:print(8-ct)
else:print(0)