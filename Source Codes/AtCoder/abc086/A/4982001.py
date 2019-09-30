a, b = map(int, input().split())

ab = a * b

if ab % 2 != 0:
  print('Odd')
else:
  print('Even')