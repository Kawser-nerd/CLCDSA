s = list(input())
t = list(input())
s.sort()
t.sort(reverse=True)
if (''.join(s) < ''.join(t)):
  print('Yes')
else:
  print('No')