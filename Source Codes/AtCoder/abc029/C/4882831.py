n=int(input())
ans=[]
def dfs(i,stack):
  if i==n:
    ans.append(stack)
    return 0
  for j in ['a','b','c']:
    stack1=stack+j
    dfs(i+1,stack1)
dfs(0,"")
ans.sort()
for i in range(len(ans)):
  print(ans[i])