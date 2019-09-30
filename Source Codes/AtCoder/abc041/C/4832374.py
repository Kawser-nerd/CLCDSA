n=int(input())
a=list(map(int,input().split()))
b=[]
for i in range(n):
  b.append([a[i],i+1])
b.sort()
b.reverse()
for i in range(n):
  print(b[i][1])