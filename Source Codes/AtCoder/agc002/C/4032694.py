n,l=map(int,input().split())
*a,=map(int,input().split())

for i in range(n-1):
  if a[i]+a[i+1]>=l:
    print("Possible")
    print(*range(i+2,n)[::-1],sep="\n")
    print(*range(1,i+2),sep="\n")
    break
else:
  print("Impossible")