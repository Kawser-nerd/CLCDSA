n,l=map(int,input().split())
*a,=map(int,input().split())
v=[0]

for i in range(n-1):
  if a[i]+a[i+1]>=l:
    v[0]=i+1
    v+=list(range(1,i+1)[::-1])
    v+=list(range(i+2,n))
    print("Possible")
    print(*v[::-1],sep="\n")
    break
else:
  print("Impossible")