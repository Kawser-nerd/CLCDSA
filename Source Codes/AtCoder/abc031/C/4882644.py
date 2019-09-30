n=int(input())
a=list(map(int,input().split()))
ans=-10**18
for i in range(n):
  stack=[]
  stack2=[]
  for j in range(n):
    tmp1=0
    tmp2=0
    if i==j:
      continue
    if i>j:
      for k in range(j,i+1):
        if k%2==j%2:
          tmp1+=a[k]
        else:
          tmp2+=a[k]
    else:
      for k in range(i,j+1):
        if k%2==i%2:
          tmp1+=a[k]
        else:
          tmp2+=a[k]
    stack.append(tmp1)
    stack2.append(tmp2)
  ans=max(ans,stack[stack2.index(max(stack2))])
print(ans)