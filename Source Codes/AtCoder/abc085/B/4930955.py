n=int(input())
list=[]
count=1
for i in range(n):
  list.append(int(input()))
list.sort()
tmp=list[0]
for i in range(1,n):
  if tmp==list[i]:
    continue
  else:
    count += 1
  tmp=list[i]
print(count)