sum=0
for _ in range(3):
  n,m=map(int,input().split())
  sum+=int((n*m)/10)
print(sum)