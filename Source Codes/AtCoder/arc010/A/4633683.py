n,m,a,b=map(int,input().split())
for i in range(m):
  if n<=a:n+=b
  n-=int(input())
  if n<0:
    print(i+1)
    break
  if i+1==m:print("complete")