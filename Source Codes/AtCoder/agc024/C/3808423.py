n = int(input())
a = [int(input()) for i in range(n)]
ans = 0
if a[0] != 0:
  print(-1)
  exit()
for i in range(1,n):
  if a[i]-1 == a[i-1]:
    pass
  else:
    if a[i]>a[i-1]+1:
      print(-1)
      exit()
    else:
      ans += a[i-1]
ans += a[n-1]
print(ans)