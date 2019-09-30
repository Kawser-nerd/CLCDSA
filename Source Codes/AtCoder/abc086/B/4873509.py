import math
s = input()
s = int(s.replace(' ', ''))
if (math.sqrt(s) == math.floor(math.sqrt(s))):
  print('Yes')
else:
  print('No')