n,m,a,b=map(int,input().split())
c=[int(input()) for i in range(m)]
f=0
for i in range(m):
  if n<=a:n+=b
  n-=c[i]
  if n<0:
    f=1
    break
if f==0:print('complete')
else:print(i+1)