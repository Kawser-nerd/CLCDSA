n=int(input())
list=[]
list2=[0]*n
count=0
next=1
for i in range(n):
  list.append(int(input()))
while True:
  list2[next-1]+=1
  count+=1
  next=list[next-1]
  if next==2:
    print(count)
    break
  if list2[next-1] >= 2:
    print(-1)
    break