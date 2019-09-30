A, B = map(int, input().split())
if (A == B):
  print('Draw')
elif (A == 1):
  print('Alice')
elif (B == 1):
  print('Bob')
elif (A > B):
  print('Alice')
else:
  print('Bob')