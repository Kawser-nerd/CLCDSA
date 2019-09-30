a = list(map(int,input().split()))
for i in range(3):
  if a.count(a[i])==1:
    print(a[i])