k=int(input())
*a,=map(int,input().split())

l,r=2,2
for i in a[::-1]:
  l=(l+i-1)//i*i
  if r<l:
    print(-1)
    break
  r=(r//i+1)*i-1
else:
  print(l,r)