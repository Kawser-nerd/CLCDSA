n,k = (int(i) for i in input().split())
zentoori = n**3
ryoutan = (3*n-2)/zentoori
if n == k or k == 1:
  print(ryoutan)
else:
  print("{0:.20f}".format(((3*n-2)+6*(k-1)*(n-k))/zentoori))