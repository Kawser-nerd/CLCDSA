n,x=map(int,input().split())

a=[0]*(n+1)
a[0]=1
p=[0]*(n+1)
p[0]=1

for i in range(n):
  a[i+1]=2*a[i]+3
  p[i+1]=2*p[i]+1


def f(n,x):
  if x==a[n]:
    return p[n]
  elif x==0:
    return 0
  elif x<=1+a[n-1]:
    return f(n-1,x-1)
  elif x==2+a[n-1]:
    return p[n-1]+1
  elif x>2+a[n-1]:
    return p[n-1]+1+f(n-1,x-2-a[n-1])
  
print(f(n,x))