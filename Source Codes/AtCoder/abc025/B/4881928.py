n,a,b = map(int, input().split())

pos = 0

for _ in range(n):
  s, d = input().split()
  d = int(d)
  if d < a:
    d = a
  elif d > b:
    d = b
  d = d if s == 'East' else -d
  pos += d

if pos == 0:
  print(0)
elif pos > 0:
  print('East {}'.format(pos))
else:
  print('West {}'.format(-pos))