n=int(input())
line=[]
for i in range(n):
  k=list(input())
  line.append(k)
ans=[]
for i in range(n):
  stack=[]
  for j in range(n):
    stack.append(line[j][i])
  stack.reverse()
  ans.append(stack)
for i in ans:
  print("".join(i))