t = int(input())
n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
if n<m:
  print("no")
  exit()
for i in b:
  for l in range(len(a)):
    if i-t-1<a[l]<i+1:
      a.pop(l)
      break
if len(a)==n-m:
  print("yes")
else:
  print("no")