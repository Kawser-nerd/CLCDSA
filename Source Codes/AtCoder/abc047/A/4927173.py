A = list(map(int, input().split()))
x = sorted(A)
if x[0] + x[1] == x[2]:
  print('Yes')
else:
  print('No')