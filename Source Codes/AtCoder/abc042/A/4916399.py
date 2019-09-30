from sys import stdin
a = stdin.readline().rstrip()
a.count('5')
if a.count('5') == 2:
  print('YES');
else:
  print('NO')