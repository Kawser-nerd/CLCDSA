n=int(input())
sum=0
for _ in range(n):
  x,y=map(str,input().split())
  if y=='JPY':
    sum+=int(x)
  else:
    sum+=float(x)*380000
print(sum)