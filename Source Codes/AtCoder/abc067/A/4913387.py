a, b = map(int, input().split())
if ((a + b) % 3 == 0 or a * b % 3 == 0):
  print('Possible')
else:
  print('Impossible')