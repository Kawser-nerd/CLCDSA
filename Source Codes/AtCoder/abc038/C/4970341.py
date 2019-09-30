n,*a=map(int,open(0).read().split())
stack=[]

c=1
for i in range(n-1):
    if a[i+1]-a[i]<=0:
        stack.append(c*(c+1)//2)
        c=1
    else:
        c+=1
stack.append(c*(c+1)//2)
print(sum(stack))