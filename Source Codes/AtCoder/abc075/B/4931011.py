def count(i,j):
  count=0
  if list[i-1][j-1]=='#':
    count += 1
  if list[i-1][j]=='#':
    count += 1
  if list[i-1][j+1]=='#':
    count += 1
  if list[i][j-1]=='#':
    count += 1
  if list[i][j+1]=='#':
    count += 1
  if list[i+1][j-1]=='#':
    count += 1
  if list[i+1][j]=='#':
    count += 1
  if list[i+1][j+1]=='#':
    count += 1
  return count

h,w=map(int, input().split())
s_init='0'*(w+2)
list=[]
list.append(s_init)
for i in range(h):
  s=str(input())
  list.append('0'+s+'0')
list.append(s_init)
for i in range(1,h+1):
  for j in range(1,w+1):
    if list[i][j]=='.':
      list[i]=list[i][:j]+str(count(i,j))+list[i][j+1:]
for i in range(h):
  print(list[i+1][1:-1])