r, b=map(int, input().split())
x, y=map(int, input().split())
n1=0
n2=int(1e18)
while n1!=n2:
  n=(n1+n2+1)//2
  a2=(r-n)//(x-1)
  a1=(n*y-b+y-2)//(y-1)
  if a2>=0 and a1<=n and a1<=a2:
    n1=n
  else:
    n2=n-1
print(n1)