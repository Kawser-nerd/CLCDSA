n, m = map(int, input().split())
 
if m<2*n or 4*n<m:
  print('-1 -1 -1')
else:
  if (4*n-m)%2 == 0:
    b = 0
    a = int((4*n-m)/2)
  else:
    b = 1
    a = int((4*n-m-1)/2)
  print(a, b, n-a-b)