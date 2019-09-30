n,a,b=map(int,input().split())
x=list(map(int,input().split()))
ret=0
for i in range(n-1):
  ret+=min(a*(x[i+1]-x[i]),b)
print(ret)