n=int(input())
max=0
for i in range(n+1):
  tmp=i*(n-i)
  if tmp>max:
    max=tmp
print(max)