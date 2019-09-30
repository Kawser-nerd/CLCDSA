a = [int(n) for n in input().split()]
if a[0]==1:
  print (a[1])
else:
  print (a[1]*(a[1]-1)**(a[0]-1))