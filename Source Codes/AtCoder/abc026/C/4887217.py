n=int(input())
salary=[0,1]
ans=[0]*(n+1)
for i in range(n-1):
  k=int(input())
  salary.append(k)
def find(x,i):
  if salary[x]==x:
    return i
  return find(salary[x],i+1)
order=[]
for i in range(len(salary)):
  order.append([find(salary[i],0),i])
order.sort()
order.reverse()
salary[1]=0
for i in order:
  stack=[]
  if salary.count(i[1])==0:
    ans[i[1]]=1
  elif salary.count(i[1])==1:
    for j in range(len(salary)):
      if salary[j]==i[1]:
        ans[i[1]]=ans[j]*2 + 1
  else:
    for j in range(len(salary)):
      if salary[j]==i[1]:
        stack.append(ans[j])
    ans[i[1]]=min(stack)+max(stack)+1
print(ans[1])