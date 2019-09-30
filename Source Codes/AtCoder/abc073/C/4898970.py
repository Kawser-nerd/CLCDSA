n,c=int(input()),{}
for i in range(n):
  a=int(input())
  if a in c:del c[a]
  else:c[a]=1
print(len(c))