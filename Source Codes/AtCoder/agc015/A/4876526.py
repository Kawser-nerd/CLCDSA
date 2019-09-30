n,a,b=map(int,input().split())

print(
  max(
    ((n-1)*b+a)-((n-1)*a+b)+1
    ,0))