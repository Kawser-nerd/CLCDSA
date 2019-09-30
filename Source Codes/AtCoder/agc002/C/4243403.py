n,l = (int(i) for i in input().split())
a = list(int(i) for i in input().split())
for i in range(n-1):
  if a[i]+a[i+1] >= l:
    print('Possible')
    for j in range(n,i+2,-1):
      print(j-1)
    for k in range(1,i+2):
      print(k)
    exit()
print('Impossible')