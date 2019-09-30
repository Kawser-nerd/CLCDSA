n = int(input())
maxP = 2025
for i in range(1,10):
  for j in range(1,10):
    if i*j+n==maxP:
      print("{} x {}".format(i,j))