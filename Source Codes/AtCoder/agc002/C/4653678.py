n,l = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n-1):
  if a[i] + a[i+1] >= l:
    print("Possible")
    break
else:
  print("Impossible")
  exit()
li = list(range(1,i+1))+list(range(n-1,i+1,-1))+[i+1]
for x in li:
  print(x)