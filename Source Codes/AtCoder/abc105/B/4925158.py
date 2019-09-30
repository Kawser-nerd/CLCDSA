n=int(input())
for i in range(0, 100):
  for j in range(0, 100):
    if 4*i+7*j==n:
      print('Yes')
      exit()
print('No')